#include <QApplication>
#include "gui/MainWindow.h"
#include "persistence/DatabaseManager.h"
#include "core/InventoryManager.h"
#include "core/AlertManager.h"
#include "core/ReportGenerator.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    DatabaseManager db;
    db.connect("inventory.db");
    db.initSchema();

    InventoryManager inv(&db);
    AlertManager alert;
    ReportGenerator report;
    inv.setAlertManager(&alert);
    inv.setReportGenerator(&report);

    MainWindow w(&inv);
    w.show();
    return app.exec();
}