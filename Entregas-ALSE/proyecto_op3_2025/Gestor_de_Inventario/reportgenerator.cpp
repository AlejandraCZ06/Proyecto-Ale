#include "reportgenerator.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

// ----- Utilidad para escapar texto en campos CSV -----
static QString escapeCSV(const QString& s)
{
    QString temp = s;
    temp.replace('"', "\"\"");  // Doble comilla interna
    if (temp.contains(',') || temp.contains('"') || temp.contains('\n') || temp.contains('\r'))
        temp = '"' + temp + '"';
    return temp;
}

bool ReportGenerator::exportToCSV(const QList<Component>& components, const QString& filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "[ReportGenerator] No se pudo abrir el archivo para exportar CSV:" << filePath;
        return false;
    }

    // Usa UTF-8 para soportar tildes, eñes, etc.
    QTextStream out(&file);
    out.setCodec("UTF-8");

    // Encabezados
    out << "ID,Nombre,Tipo,Cantidad,Ubicación,Fecha,Lote,Notas\n";

    for (const Component& c : components) {
        out
            << c.getId() << ","
            << escapeCSV(c.getName()) << ","
            << escapeCSV(c.getType()) << ","
            << c.getQuantity() << ","
            << escapeCSV(c.getLocation()) << ","
            << escapeCSV(c.getPurchaseDate()) << ","
            << c.getLote() << ","
            << escapeCSV(c.getNotes()) << "\n";
    }

    file.close();
    qDebug() << "[ReportGenerator] Exportación exitosa a CSV en:" << filePath;
    return true;
}
