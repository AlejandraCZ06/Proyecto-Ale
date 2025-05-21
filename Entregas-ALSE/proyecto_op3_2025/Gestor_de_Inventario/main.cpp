#include <QApplication>
#include <QCoreApplication>
#include <QDir>
#include <QDebug>
#include "mainwindow.h"
#include "databasemanager.h"
#include "inventorymanager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Carpeta de base y archivo SQL relativos al ejecutable
    QString dbFolder    = QCoreApplication::applicationDirPath() + "/db";
    QString dbPath      = dbFolder + "/inventario.db";
    QString sqlInitPath = dbFolder + "/inventario.sql";

    // Asegura que el directorio de la base de datos existe
    if (!QDir().exists(dbFolder)) {
        QDir().mkpath(dbFolder);
        qDebug() << "Directorio 'db' creado en:" << dbFolder;
    } else {
        qDebug() << "Directorio 'db' ya existe en:" << dbFolder;
    }
    qDebug() << "Base de datos esperada en:" << dbPath;

    // Inicializa la conexión a la base de datos, pasando la ruta al archivo SQL
    DatabaseManager dbManager(dbPath, sqlInitPath);
    if (!dbManager.open()) {
        qCritical("No se pudo abrir la base de datos en %s. Terminando.", qPrintable(dbPath));
        return 1;
    }
    qDebug() << "Base de datos abierta correctamente.";

    // Crea el gestor de inventario y la ventana principal
    InventoryManager inventoryManager(&dbManager);
    MainWindow w(&inventoryManager, &dbManager);
    w.show();

    int resultado = app.exec();

    dbManager.close();

    return resultado;
}
