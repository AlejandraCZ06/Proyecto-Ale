#pragma once
#include <QString>
#include <QDate>

class Component
{
public:
    Component(int id = -1,
              const QString& name = {},
              const QString& type = {},
              int quantity = 0,
              const QString& location = {},
              const QDate& purchaseDate = QDate::currentDate());

    // getters
    int id() const;
    QString name() const;
    QString type() const;
    int quantity() const;
    QString location() const;
    QDate purchaseDate() const;

    // setters
    void setId(int);
    void setName(const QString&);
    void setType(const QString&);
    void setQuantity(int);
    void setLocation(const QString&);
    void setPurchaseDate(const QDate&);

    // helpers
    void updateQuantity(int delta);
    QString toString() const;

private:
    int         m_id;
    QString     m_name;
    QString     m_type;
    int         m_quantity;
    QString     m_location;
    QDate       m_purchaseDate;
};