#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include <QFile>
#include <QTextStream>

// Constructor (ahora acepta la ruta SQL de inicialización)
DatabaseManager::DatabaseManager(const QString& dbPath, const QString& sqlInitPath)
    : m_dbPath(dbPath),
      m_sqlInitPath(sqlInitPath),
      m_connectionName("main_inventory_connection")
{
    // Asegura que exista la carpeta donde estará la base de datos
    QFileInfo dbFileInfo(m_dbPath);
    QDir().mkpath(dbFileInfo.path());
}

DatabaseManager::~DatabaseManager() {
    close();
    if(QSqlDatabase::contains(m_connectionName))
        QSqlDatabase::removeDatabase(m_connectionName);
}

// Inicialización automática si falta la tabla components
void DatabaseManager::initIfNeeded()
{
    QSqlQuery query(m_db);
    // Comprueba si la tabla "components" existe
    query.exec("SELECT name FROM sqlite_master WHERE type='table' AND name='components';");
    if (!query.next()) {
        QFile sqlFile(m_sqlInitPath);
        if (sqlFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&sqlFile);
            QString sql = in.readAll();
            // Ejecuta cada sentencia separada por ;
            for (const QString& statement : sql.split(';', Qt::SkipEmptyParts)) {
                QString stmt = statement.trimmed();
                if (!stmt.isEmpty()) {
                    if (!query.exec(stmt)) {
                        qDebug() << "Error ejecutando:" << stmt;
                        qDebug() << "Error:" << query.lastError().text();
                    }
                }
            }
            sqlFile.close();
            qDebug() << "Base de datos inicializada automáticamente desde" << m_sqlInitPath;
        } else {
            qDebug() << "No se pudo abrir el archivo SQL:" << m_sqlInitPath;
        }
    } else {
        qDebug() << "La tabla components ya existe; no es necesario inicializar.";
    }
}

bool DatabaseManager::open() {
    qDebug() << "[DatabaseManager] Drivers disponibles:" << QSqlDatabase::drivers();
    qDebug() << "[DatabaseManager] Intentando abrir base de datos en:" << m_dbPath;

    if(QSqlDatabase::contains(m_connectionName))
        m_db = QSqlDatabase::database(m_connectionName);
    else
        m_db = QSqlDatabase::addDatabase("QSQLITE", m_connectionName);

    m_db.setDatabaseName(m_dbPath);

    if (!m_db.open()) {
        qDebug() << "No se pudo abrir la base de datos:" << m_dbPath;
        qDebug() << "Razón:" << m_db.lastError().text();
        return false;
    }
    qDebug() << "Base de datos ABRIENDOSE correctamente.";

    // Inicializa la base de datos solo si hace falta
    initIfNeeded();

    return true;
}

void DatabaseManager::close() {
    if (m_db.isOpen())
        m_db.close();
}

QList<Component> DatabaseManager::getAllComponents() {
    QList<Component> list;
    QSqlQuery query(m_db);
    if (query.exec("SELECT id, name, type, quantity, location, purchase_date, min_quantity, notes FROM components")) {
        while (query.next()) {
            Component c(
                query.value(0).toInt(),    // id
                query.value(1).toString(), // name
                query.value(2).toString(), // type
                query.value(3).toInt(),    // quantity
                query.value(4).toString(), // location
                query.value(5).toString(), // purchase_date
                query.value(6).toInt(),    // min_quantity
                query.value(7).toString()  // notes
            );
            list.append(c);
        }
    } else {
        qDebug() << "Error al listar componentes:" << query.lastError().text();
    }
    return list;
}

bool DatabaseManager::addComponent(const Component &component) {
    QSqlQuery query(m_db);
    query.prepare("INSERT INTO components (name, type, quantity, location, purchase_date, min_quantity, notes) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(component.getName());
    query.addBindValue(component.getType());
    query.addBindValue(component.getQuantity());
    query.addBindValue(component.getLocation());
    query.addBindValue(component.getPurchaseDate());
    query.addBindValue(component.getMinQuantity());
    query.addBindValue(component.getNotes());
    if (!query.exec()) {
        qDebug() << "Error al insertar componente:" << query.lastError().text();
        return false;
    }
    return true;
}

bool DatabaseManager::updateComponent(const Component &component) {
    QSqlQuery query(m_db);
    query.prepare("UPDATE components SET name=?, type=?, quantity=?, location=?, purchase_date=?, min_quantity=?, notes=? "
                  "WHERE id=?");
    query.addBindValue(component.getName());
    query.addBindValue(component.getType());
    query.addBindValue(component.getQuantity());
    query.addBindValue(component.getLocation());
    query.addBindValue(component.getPurchaseDate());
    query.addBindValue(component.getMinQuantity());
    query.addBindValue(component.getNotes());
    query.addBindValue(component.getId());
    if (!query.exec()) {
        qDebug() << "Error al actualizar componente:" << query.lastError().text();
        return false;
    }
    return true;
}

bool DatabaseManager::deleteComponent(int id) {
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM components WHERE id=?");
    query.addBindValue(id);
    if (!query.exec()) {
        qDebug() << "Error al borrar componente:" << query.lastError().text();
        return false;
    }
    return true;
}
