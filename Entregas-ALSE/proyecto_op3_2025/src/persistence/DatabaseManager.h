#pragma once
#include <QSqlDatabase>
#include <QVariantList>
#include <QVector>
#include <QVariantMap>

class DatabaseManager
{
public:
    bool connect(const QString& filePath);
    void disconnect();
    bool initSchema();
    QSqlQuery exec(const QString& sql, const QVariantList& params = {});
    QVector<QVariantMap> fetchAll(const QSqlQuery& query) const;

private:
    QSqlDatabase m_db;
};