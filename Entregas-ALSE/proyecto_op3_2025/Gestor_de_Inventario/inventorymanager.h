#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include "component.h"
#include "databasemanager.h"
#include <QList>
#include <QString>

// Clase de alto nivel para la lógica de inventario (interactúa con DatabaseManager)
class InventoryManager
{
public:
    /// Constructor. Recibe un DatabaseManager ya inicializado.
    explicit InventoryManager(DatabaseManager* dbManager);

    /// Recupera la lista de todos los componentes.
    QList<Component> getComponents() const;

    /// Agrega un nuevo componente. Devuelve true si tuvo éxito.
    bool addComponent(const Component& component);

    /// Actualiza la información de un componente existente. Devuelve true si tuvo éxito.
    bool updateComponent(const Component& component);

    /// Elimina un componente por su ID. Devuelve true si tuvo éxito.
    bool removeComponent(int componentId);

    /// Devuelve una lista filtrada por nombre o tipo, búsqueda insensible a mayúsculas/minúsculas.
    QList<Component> filterComponents(const QString &pattern) const;

    /// Devuelve componentes con stock bajo (usa un umbral predefinido, por ejemplo: "5" piezas).
    QList<Component> lowStockComponents(int lowStockThreshold = 5) const;

private:
    DatabaseManager* m_dbManager; // No propietario, asume que la vida útil la gestiona el llamador.
};

#endif // INVENTORYMANAGER_H
