#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QSqlDatabase>
#include <QList>
#include "component.h"

// Clase para gestionar la conexión y operaciones principales con la BD (Singleton opcional en proyectos grandes)
class DatabaseManager
{
public:
    // Constructor. Permite establecer la ruta del archivo SQLite y el script SQL de inicialización.
    explicit DatabaseManager(const QString& dbPath = "db/inventario1.db", const QString& sqlInitPath = "db/inventario.sql");
    ~DatabaseManager();

    // Conexión y cierre
    bool open();
    void close();

    // CRUD principal para componentes
    QList<Component> getAllComponents();
    bool addComponent(const Component &component);
    bool updateComponent(const Component &component);
    bool deleteComponent(int id);

    // QList<MovementLog> getMovementLogs(int componentId);

    bool isOpen() const { return m_db.isOpen(); }

private:
    // Rutas y control interno
    QString m_dbPath;
    QString m_sqlInitPath;
    QString m_connectionName;
    QSqlDatabase m_db;

    // Inicialización automática si la base NO existe (ejecuta el SQL de creación)
    void initIfNeeded();

    // Evita copias accidentales del gestor
    Q_DISABLE_COPY(DatabaseManager)
};

#endif // DATABASEMANAGER_H
