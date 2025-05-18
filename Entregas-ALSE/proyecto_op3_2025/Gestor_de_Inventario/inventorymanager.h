#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include "component.h"
#include "databasemanager.h"
#include <QList>

class InventoryManager
{
public:
    InventoryManager(DatabaseManager* dbManager);
    QList<Component> getComponents();
    void addComponent(const Component& component);
    void updateComponent(const Component& component);
    void removeComponent(int componentId);

    QList<Component> filterComponents(const QString &pattern) const;
    QList<Component> lowStockComponents() const;

private:
    DatabaseManager* m_dbManager;
};

#endif // INVENTORYMANAGER_H
