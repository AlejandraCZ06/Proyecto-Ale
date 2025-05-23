#include "inventorymanager.h"

InventoryManager::InventoryManager(DatabaseManager* dbManager)
    : m_dbManager(dbManager) {}

QList<Component> InventoryManager::getComponents()
{
    return m_dbManager->getAllComponents();
}

bool InventoryManager::addComponent(const Component& component)
{
    return m_dbManager->addComponent(component);
}

bool InventoryManager::updateComponent(const Component& component)
{
    return m_dbManager->updateComponent(component);
}

bool InventoryManager::removeComponent(int componentId)
{
    return m_dbManager->deleteComponent(componentId);
}

QList<Component> InventoryManager::filterComponents(const QString &pattern) const
{
    QList<Component> result;
    QList<Component> all = m_dbManager->getAllComponents();
    for (const auto& comp : all) {
        if (comp.getName().contains(pattern, Qt::CaseInsensitive) ||
            comp.getType().contains(pattern, Qt::CaseInsensitive) ||
            comp.getLocation().contains(pattern, Qt::CaseInsensitive)) {
            result.append(comp);
        }
    }
    return result;
}

QList<Component> InventoryManager::lowStockComponents() const
{
    QList<Component> result;

    QList<Component> all = m_dbManager->getAllComponents();
    for (const auto& comp : all) {
        if (comp.getQuantity() <= comp.getLote()) {
            result.append(comp);
        }
    }

    return result;
}
