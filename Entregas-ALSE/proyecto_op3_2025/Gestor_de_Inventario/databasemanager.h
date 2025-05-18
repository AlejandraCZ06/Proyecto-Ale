#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QSqlDatabase>
#include <QList>
#include "Component.h"

class DatabaseManager
{
public:
    DatabaseManager(const QString& dbPath);
    ~DatabaseManager();

    bool open();
    void close();

    QList<Component> getAllComponents();
    bool addComponent(const Component &component);
    bool updateComponent(const Component &component);
    bool deleteComponent(int id);

private:
    QString m_dbPath;
    QSqlDatabase m_db;
    QString m_connectionName;
};

#endif // DATABASEMANAGER_H
