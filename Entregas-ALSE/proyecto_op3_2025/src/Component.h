#ifndef COMPONENT_H
#define COMPONENT_H

#include <QString>

class Component {
public:
    Component(int id, const QString& name, const QString& type, int quantity,
              const QString& location, const QString& purchaseDate, int minQuantity, const QString& notes);

    // Getters y setters
    int id() const;
    QString name() const;
    QString type() const;
    int quantity() const;
    QString location() const;
    QString purchaseDate() const;
    int minQuantity() const;
    QString notes() const;
private:
    int m_id;
    QString m_name, m_type, m_location, m_purchaseDate, m_notes;
    int m_quantity, m_minQuantity;
};
#endif