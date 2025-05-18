#include "Component.h"

Component::Component(int id, const QString& name, const QString& type, int quantity,
                     const QString& location, const QString& purchaseDate, int minQuantity, const QString& notes)
    : m_id(id), m_name(name), m_type(type), m_quantity(quantity),
      m_location(location), m_purchaseDate(purchaseDate),
      m_minQuantity(minQuantity), m_notes(notes)
{}

int Component::id() const { return m_id; }
QString Component::name() const { return m_name; }
QString Component::type() const { return m_type; }
int Component::quantity() const { return m_quantity; }
QString Component::location() const { return m_location; }
QString Component::purchaseDate() const { return m_purchaseDate; }
int Component::minQuantity() const { return m_minQuantity; }
QString Component::notes() const { return m_notes; }