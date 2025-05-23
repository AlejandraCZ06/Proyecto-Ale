#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "inventorymanager.h"
#include "databasemanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(InventoryManager *inventory, DatabaseManager *db, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_agregar_clicked();      // Botón Agregar
    void on_editar_clicked();       // Botón Editar
    void on_eliminar_clicked();     // Botón Eliminar
    void on_nuevo_clicked();        // Botón Nuevo ítem / Limpiar formulario
    void on_tableWidget_itemSelectionChanged();
    void on_buscar_2_textChanged(const QString &text);

private:
    Ui::MainWindow *ui;
    InventoryManager *m_inventory;
    DatabaseManager *m_db;

    void updateComponentTable(const QString &filterText = QString());
    void clearForm();
    void loadSelectedComponentData();
};

#endif // MAINWINDOW_H
