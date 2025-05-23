#include "component.h"

// Constructor con valores por defecto
Component::Component(int id, const QString& name, const QString& type, int quantity,
                     const QString& location, const QString& purchaseDate,
                     int lote, const QString& notes)
    : m_id(id), m_name(name), m_type(type), m_quantity(quantity),
      m_location(location), m_purchaseDate(purchaseDate),
      m_lote(lote), m_notes(notes)
{}

// Getters
int Component::getId() const { return m_id; }
QString Component::getName() const { return m_name; }
QString Component::getType() const { return m_type; }
int Component::getQuantity() const { return m_quantity; }
QString Component::getLocation() const { return m_location; }
QString Component::getPurchaseDate() const { return m_purchaseDate; }
int Component::getLote() const { return m_lote; }
QString Component::getNotes() const { return m_notes; }

// Setters principales
void Component::setQuantity(int quantity) { m_quantity = quantity; }
void Component::setLote(int lote)         { m_lote = lote; }
void Component::setNotes(const QString& notes) { m_notes = notes; }

// Setters adicionales recomendados para flexibilidad (puedes omitir si no usas)
void Component::setId(int id)                    { m_id = id; }
void Component::setName(const QString& name)     { m_name = name; }
void Component::setType(const QString& type)     { m_type = type; }
void Component::setLocation(const QString& location) { m_location = location; }
void Component::setPurchaseDate(const QString& purchaseDate) { m_purchaseDate = purchaseDate; }
