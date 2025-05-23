#include "inventorymanager.h"

// Constructor
InventoryManager::InventoryManager(DatabaseManager* dbManager)
    : m_dbManager(dbManager) {}

// Obtiene todos los componentes
QList<Component> InventoryManager::getComponents() const
{
    return m_dbManager->getAllComponents();
}

// Agrega componente
bool InventoryManager::addComponent(const Component& component)
{
    return m_dbManager->addComponent(component);
}

// Actualiza componente
bool InventoryManager::updateComponent(const Component& component)
{
    return m_dbManager->updateComponent(component);
}

// Elimina componente por ID
bool InventoryManager::removeComponent(int componentId)
{
    return m_dbManager->deleteComponent(componentId);
}

// Filtra componentes por patrón en nombre, tipo o ubicación (insensible a mayúsculas)
QList<Component> InventoryManager::filterComponents(const QString &pattern) const
{
    QList<Component> result;
    const QList<Component>& all = m_dbManager->getAllComponents();
    for (const auto& comp : all) {
        if (comp.getName().contains(pattern, Qt::CaseInsensitive)
            || comp.getType().contains(pattern, Qt::CaseInsensitive)
            || comp.getLocation().contains(pattern, Qt::CaseInsensitive)) {
            result.append(comp);
        }
    }
    return result;
}

// Devuelve componentes con stock bajo (parámetro: umbral)
QList<Component> InventoryManager::lowStockComponents(int lowStockThreshold) const
{
    QList<Component> result;
    const QList<Component>& all = m_dbManager->getAllComponents();

    for (const auto& comp : all) {
        // Si el umbral es inválido o negativo, utiliza el campo lote (como antes)
        int threshold = (lowStockThreshold >= 0) ? lowStockThreshold : comp.getLote();
        if (comp.getQuantity() <= threshold)
            result.append(comp);
    }
    return result;
}
