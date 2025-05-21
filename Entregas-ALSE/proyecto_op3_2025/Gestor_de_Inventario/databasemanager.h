#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QSqlDatabase>
#include <QList>
#include "component.h"

class DatabaseManager
{
public:
    // Ahora puedes pasar opcionalmente la ruta SQL al constructor
    DatabaseManager(const QString& dbPath, const QString& sqlInitPath = "db/inventario.sql");
    ~DatabaseManager();

    bool open();
    void close();

    QList<Component> getAllComponents();
    bool addComponent(const Component &component);
    bool updateComponent(const Component &component);
    bool deleteComponent(int id);

private:
    QString m_dbPath;
    QString m_sqlInitPath;
    QString m_connectionName;
    QSqlDatabase m_db;

    // Nueva función privada para auto-inicialización
    void initIfNeeded();
};

#endif // DATABASEMANAGER_H
