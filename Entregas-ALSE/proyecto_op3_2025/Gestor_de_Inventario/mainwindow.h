#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "inventorymanager.h"
#include "databasemanager.h"

// Forward declaration del espacio de nombres generado por Qt Designer
namespace Ui {
class MainWindow;
}

// Ventana principal de la aplicación de inventario
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(InventoryManager *inventory, DatabaseManager *db, QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_agregar_clicked();      // Botón Agregar
    void on_editar_clicked();       // Botón Editar
    void on_eliminar_clicked();     // Botón Eliminar
    void on_nuevo_clicked();        // Botón Nuevo ítem / Limpiar formulario
    void on_tableWidget_itemSelectionChanged(); // Selección en la tabla
    void on_buscar_2_textChanged(const QString &text); // Búsqueda en vivo
    void on_exportar_clicked();     // Botón Exportar CSV

private:
    Ui::MainWindow *ui;
    InventoryManager *m_inventory;  // Gestor de inventario (no propietario)
    DatabaseManager *m_db;          // Gestor de base de datos (no propietario)

    // Métodos internos auxiliares
    void updateComponentTable(const QString &filterText = QString()); // Actualizar tabla con filtro (default sin filtro)
    void clearForm();                    // Limpiar formulario de captura
    void loadSelectedComponentData();    // Cargar datos al formulario desde la selección actual

    Q_DISABLE_COPY(MainWindow)           // Evita copias accidentales  (best practice con widgets Qt)
};

#endif // MAINWINDOW_H
