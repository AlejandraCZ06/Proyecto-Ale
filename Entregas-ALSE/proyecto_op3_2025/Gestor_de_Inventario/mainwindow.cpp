#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTableWidgetItem>

MainWindow::MainWindow(InventoryManager *inventory, DatabaseManager *db, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_inventory(inventory),
    m_db(db)
{
    ui->setupUi(this);

    // Actualiza la tabla al arrancar la interfaz
    updateComponentTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateComponentTable()
{
    // Obtiene la lista de componentes
    QList<Component> componentes = m_inventory->getComponents();

    ui->tableWidget->clear(); // Asegúrate de tener un QTableWidget en el .ui llamado tableWidget

    // Ajusta el número de filas y columnas
    ui->tableWidget->setRowCount(componentes.size());
    ui->tableWidget->setColumnCount(8);
    QStringList headers;
    headers << "ID" << "Nombre" << "Tipo" << "Cantidad" << "Ubicación" << "Fecha" << "Stock Mín." << "Notas";
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    int row = 0;
    for (const auto& c : componentes) {
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(c.getId())));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(c.getName()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(c.getType()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(c.getQuantity())));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(c.getLocation()));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(c.getPurchaseDate()));
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem(QString::number(c.getMinQuantity())));
        ui->tableWidget->setItem(row, 7, new QTableWidgetItem(c.getNotes()));
        ++row;
    }
}
