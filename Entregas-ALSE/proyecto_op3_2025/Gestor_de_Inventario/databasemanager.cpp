#include "databasemanager.h"
#include "component.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include <QFile>
#include <QTextStream>

// Constructor
DatabaseManager::DatabaseManager(const QString& dbPath, const QString& sqlInitPath)
    : m_dbPath(dbPath), m_sqlInitPath(sqlInitPath), m_connectionName("main_inventory_connection")
{
    // Crea carpeta si no existe
    QFileInfo dbFileInfo(m_dbPath);
    QDir().mkpath(dbFileInfo.path());
}

// Destructor
DatabaseManager::~DatabaseManager() {
    close();
    if (QSqlDatabase::contains(m_connectionName))
        QSqlDatabase::removeDatabase(m_connectionName);
}

// Inicializa la base de datos si es necesario
void DatabaseManager::initIfNeeded()
{
    QSqlQuery query(m_db);
    query.exec("PRAGMA foreign_keys = ON;"); // Siempre activa claves foráneas

    query.exec("SELECT name FROM sqlite_master WHERE type='table' AND name='components';");
    if (!query.next()) {
        QFile sqlFile(m_sqlInitPath);
        if (sqlFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&sqlFile);
            QString sql = in.readAll();
            for (const QString& statement : sql.split(';', Qt::SkipEmptyParts)) {
                QString stmt = statement.trimmed();
                if (!stmt.isEmpty()) {
                    if (!query.exec(stmt)) {
                        qDebug() << "[initIfNeeded][ERROR] Ejecutando:" << stmt;
                        qDebug() << "[initIfNeeded][ERROR]" << query.lastError().text();
                    }
                }
            }
            sqlFile.close();
            qDebug() << "[initIfNeeded] Base de datos inicializada correctamente desde" << m_sqlInitPath;
        } else {
            qDebug() << "[initIfNeeded][ERROR] No se pudo abrir el archivo SQL:" << m_sqlInitPath;
        }
    } else {
        qDebug() << "[initIfNeeded] Tabla 'components' ya existe, no es necesario inicializar.";
    }
}

bool DatabaseManager::open() {
    qDebug() << "[DatabaseManager] Intentando abrir base de datos en:" << m_dbPath;

    if (QSqlDatabase::contains(m_connectionName))
        m_db = QSqlDatabase::database(m_connectionName);
    else
        m_db = QSqlDatabase::addDatabase("QSQLITE", m_connectionName);

    m_db.setDatabaseName(m_dbPath);

    if (!m_db.open()) {
        qDebug() << "[DatabaseManager][ERROR] No se pudo abrir la base de datos:" << m_dbPath;
        qDebug() << "[DatabaseManager][ERROR] Razón:" << m_db.lastError().text();
        return false;
    }
    // Activa claves foráneas cada vez que abras
    QSqlQuery query(m_db);
    query.exec("PRAGMA foreign_keys = ON;");

    qDebug() << "[DatabaseManager] Base de datos abierta correctamente.";
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
    if (query.exec("SELECT id, name, type, quantity, location, purchase_date, lote, notes FROM components")) {
        while (query.next()) {
            Component c(
                query.value(0).toInt(),    // id
                query.value(1).toString(), // name
                query.value(2).toString(), // type
                query.value(3).toInt(),    // quantity
                query.value(4).toString(), // location
                query.value(5).toString(), // purchase_date
                query.value(6).toInt(),    // lote
                query.value(7).toString()  // notes
            );
            list.append(c);
        }
    } else {
        qDebug() << "[getAllComponents][ERROR]" << query.lastError().text();
    }
    return list;
}

bool DatabaseManager::addComponent(const Component &component) {
    QSqlQuery query(m_db);
    query.prepare("INSERT INTO components (name, type, quantity, location, purchase_date, lote, notes) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(component.getName());
    query.addBindValue(component.getType());
    query.addBindValue(component.getQuantity());
    query.addBindValue(component.getLocation());
    query.addBindValue(component.getPurchaseDate());
    query.addBindValue(component.getLote());
    query.addBindValue(component.getNotes());
    if (!query.exec()) {
        qDebug() << "[addComponent][ERROR]" << query.lastError().text();
        return false;
    }
    return true;
}

bool DatabaseManager::updateComponent(const Component &component) {
    QSqlQuery query(m_db);
    query.prepare("UPDATE components SET name=?, type=?, quantity=?, location=?, purchase_date=?, lote=?, notes=? WHERE id=?");
    query.addBindValue(component.getName());
    query.addBindValue(component.getType());
    query.addBindValue(component.getQuantity());
    query.addBindValue(component.getLocation());
    query.addBindValue(component.getPurchaseDate());
    query.addBindValue(component.getLote());
    query.addBindValue(component.getNotes());
    query.addBindValue(component.getId());
    if (!query.exec()) {
        qDebug() << "[updateComponent][ERROR]" << query.lastError().text();
        return false;
    }
    return true;
}

bool DatabaseManager::deleteComponent(int id) {
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM components WHERE id=?");
    query.addBindValue(id);
    if (!query.exec()) {
        qDebug() << "[deleteComponent][ERROR]" << query.lastError().text();
        return false;
    }
    return true;
}
