#ifndef COMPONENT_H
#define COMPONENT_H

#include <QString>

class Component
{
public:
    Component(int id, const QString& name, const QString& type, int quantity,
              const QString& location, const QString& purchaseDate, int minQuantity, const QString& notes);

    int getId() const;
    QString getName() const;
    QString getType() const;
    int getQuantity() const;
    QString getLocation() const;
    QString getPurchaseDate() const;
    int getMinQuantity() const;
    QString getNotes() const;

    void setQuantity(int quantity);
private:
    int m_id;
    QString m_name;
    QString m_type;
    int m_quantity;
    QString m_location;
    QString m_purchaseDate;
    int m_minQuantity;
    QString m_notes;
};

#endif // COMPONENT_H
