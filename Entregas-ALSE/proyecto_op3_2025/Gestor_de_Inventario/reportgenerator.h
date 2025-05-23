#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <QString>
#include <QList>
#include "component.h"

// Clase utilitaria para la generación de reportes
class ReportGenerator
{
public:
    /// Genera un archivo CSV a partir de la lista de componentes.
    /// @param components Lista de componentes a exportar
    /// @param filePath   Ruta destino del archivo CSV
    /// @return           true si se exportó exitosamente, false en caso de error
    static bool exportToCSV(const QList<Component>& components, const QString& filePath);

    //PDF
    // static bool exportToPDF(const QList<Component>& components, const QString& filePath);
};

#endif // REPORTGENERATOR_H
