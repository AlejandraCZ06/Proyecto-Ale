#include "reportgenerator.h"
#include <QFile>
#include <QTextStream>

bool ReportGenerator::exportToCSV(const QList<Component>& components, const QString& filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);
    // Escribimos encabezados
    out << "id,name,type,quantity,location,purchase_date,lote,notes\n";
    for (const auto &c : components) {
        out << c.getId() << ","
            << "\"" << c.getName() << "\","
            << "\"" << c.getType() << "\","
            << c.getQuantity() << ","
            << "\"" << c.getLocation() << "\","
            << "\"" << c.getPurchaseDate() << "\","
            //<< c.geLote() << ","
            << "\"" << c.getNotes().replace('"', '\'') << "\""
            << "\n";
    }
    file.close();
    return true;
}
