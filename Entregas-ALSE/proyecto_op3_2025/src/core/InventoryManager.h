#pragma once
#include "Component.h"
#include <vector>
#include <optional>

class DatabaseManager;
class AlertManager;
class ReportGenerator;

class InventoryManager
{
public:
    explicit InventoryManager(DatabaseManager* db);

    bool addComponent(const Component&);
    bool updateComponent(const Component&);
    bool removeComponent(int id);
    std::vector<Component> searchComponent(const QString& filter) const;
    std::optional<Component> getById(int id) const;

    void sync();                 // lee la BD a caché
    void setAlertManager(AlertManager*);
    void setReportGenerator(ReportGenerator*);

private:
    DatabaseManager*   m_db;
    AlertManager*      m_alertMgr{nullptr};
    ReportGenerator*   m_reportGen{nullptr};
    std::vector<Component> m_cache;
};