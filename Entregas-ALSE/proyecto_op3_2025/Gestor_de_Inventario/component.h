#ifndef COMPONENT_H
#define COMPONENT_H

#include <QString>

// Clase que representa un componente/artículo del inventario
class Component
{
public:
    // Constructor completo con valores por defecto para facilitar creación y actualización
    Component(int id = -1, const QString& name = "", const QString& type = "", int quantity = 0,
              const QString& location = "", const QString& purchaseDate = "",
              int lote = 0, const QString& notes = "");

    // Getters
    int getId() const;
    QString getName() const;
    QString getType() const;
    int getQuantity() const;
    QString getLocation() const;
    QString getPurchaseDate() const;
    int getLote() const;
    QString getNotes() const;

    // Setters (puedes agregar más si los necesitas)
    void setQuantity(int quantity);
    void setLote(int lote);
    void setNotes(const QString& notes);

    // Métodos útiles (Extras, opcionales)
    void setId(int id);
    void setName(const QString& name);
    void setType(const QString& type);
    void setLocation(const QString& location);
    void setPurchaseDate(const QString& date);

private:
    int m_id;                // Identificador en la base de datos
    QString m_name;
    QString m_type;
    int m_quantity;
    QString m_location;
    QString m_purchaseDate;  // Usa QString si así lo prefieres, compatible con databases
    int m_lote;
    QString m_notes;
};

#endif // COMPONENT_H
