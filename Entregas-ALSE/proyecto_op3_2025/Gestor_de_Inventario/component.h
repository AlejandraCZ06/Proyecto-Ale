#ifndef COMPONENT_H
#define COMPONENT_H

#include <QString>

class Component
{
public:
    // Constructor completo usando todos los campos
    Component(int id, const QString& name, const QString& type, int quantity,
              const QString& location, const QString& purchaseDate,
              int lote, const QString& notes);

    // Getters
    int getId() const;
    QString getName() const;
    QString getType() const;
    int getQuantity() const;
    QString getLocation() const;
    QString getPurchaseDate() const;
    int getLote() const;
    QString getNotes() const;

    // Setters específicos
    void setQuantity(int quantity);
    void setLote(int lote);
    void setNotes(const QString& notes);

private:
    int m_id;
    QString m_name;
    QString m_type;
    int m_quantity;
    QString m_location;
    QString m_purchaseDate;
    int m_lote;
    QString m_notes;
};

#endif // COMPONENT_H
