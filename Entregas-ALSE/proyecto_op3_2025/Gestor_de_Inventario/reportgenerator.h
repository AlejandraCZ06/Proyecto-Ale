#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <QString>
#include <QList>
#include "Component.h"

class ReportGenerator
{
public:
    static bool exportToCSV(const QList<Component>& components, const QString& filePath);
    // Puedes agregar exportToPDF en el futuro si lo necesitas
};

#endif // REPORTGENERATOR_H
