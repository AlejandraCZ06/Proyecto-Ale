#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include "component.h"
#include "databasemanager.h"
#include <QList>
#include <QString>

class InventoryManager
{
public:
    /// Crea un gestor partiendo de un DatabaseManager ya creado.
    InventoryManager(DatabaseManager* dbManager);

    /// Recupera la lista de todos los componentes.
    QList<Component> getComponents();

    /// Agrega un nuevo componente. Devuelve true si tuvo éxito.
    bool addComponent(const Component& component);

    /// Actualiza la información de un componente existente. Devuelve true si tuvo éxito.
    bool updateComponent(const Component& component);

    /// Elimina un componente por su ID. Devuelve true si tuvo éxito.
    bool removeComponent(int componentId);

    /// Devuelve una lista filtrada según patrón de nombre o tipo (búsqueda insensible a mayúsculas/minúsculas).
    QList<Component> filterComponents(const QString &pattern) const;

    /// Devuelve componentes de bajo stock (vacío por ahora, se implementará cuando uses min_quantity).
    QList<Component> lowStockComponents() const;

private:
    DatabaseManager* m_dbManager;
};

#endif // INVENTORYMANAGER_H
