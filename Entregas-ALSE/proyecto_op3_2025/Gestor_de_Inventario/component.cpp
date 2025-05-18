#include "component.h"

Component::Component(int id, const QString& name, const QString& type, int quantity,
                     const QString& location, const QString& purchaseDate, int minQuantity, const QString& notes)
    : m_id(id), m_name(name), m_type(type), m_quantity(quantity),
      m_location(location), m_purchaseDate(purchaseDate),
      m_minQuantity(minQuantity), m_notes(notes)
{}

int Component::getId() const { return m_id; }
QString Component::getName() const { return m_name; }
QString Component::getType() const { return m_type; }
int Component::getQuantity() const { return m_quantity; }
QString Component::getLocation() const { return m_location; }
QString Component::getPurchaseDate() const { return m_purchaseDate; }
int Component::getMinQuantity() const { return m_minQuantity; }
QString Component::getNotes() const { return m_notes; }
void Component::setQuantity(int quantity) { m_quantity = quantity; }
