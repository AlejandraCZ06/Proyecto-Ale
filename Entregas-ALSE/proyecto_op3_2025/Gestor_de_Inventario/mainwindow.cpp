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
    updateComponentTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateComponentTable(const QString &filterText)
{
    QList<Component> componentes = m_inventory->getComponents();

    // Filtro rápido por nombre o tipo si hay texto en buscar_2
    if (!filterText.isEmpty()) {
        QList<Component> filtrados;
        for (const auto& c : componentes) {
            if (c.getName().contains(filterText, Qt::CaseInsensitive) ||
                c.getType().contains(filterText, Qt::CaseInsensitive))
            {
                filtrados.append(c);
            }
        }
        componentes = filtrados;
    }

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(componentes.size());
    ui->tableWidget->setColumnCount(6);
    QStringList headers;
    headers << "ID" << "Nombre" << "Tipo" << "Cantidad" << "Ubicación" << "Fecha";
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    int row = 0;
    for (const auto& c : componentes) {
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(c.getId())));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(c.getName()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(c.getType()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(c.getQuantity())));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(c.getLocation()));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(c.getPurchaseDate()));
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem(c.getLote()));
        ui->tableWidget->setItem(row, 7, new QTableWidgetItem(c.getNotes()));
        ++row;
    }
}

void MainWindow::clearForm()
{
    ui->nombre_2->clear();
    ui->tipo_2->clear();
    ui->ubicacion_2->clear();
    ui->cantidad->setValue(0);
    ui->fecha->setDate(QDate::currentDate());
    ui->lote_2->setValue(0);
    ui->notes_2->clear();
    ui->tableWidget->clearSelection();
}

void MainWindow::loadSelectedComponentData()
{
    auto selected = ui->tableWidget->selectedItems();
    if (selected.isEmpty())
        return;

    int row = selected.first()->row();
    ui->nombre_2->setText(ui->tableWidget->item(row, 1)->text());
    ui->tipo_2->setText(ui->tableWidget->item(row, 2)->text());
    ui->cantidad->setValue(ui->tableWidget->item(row, 3)->text().toDouble());
    ui->ubicacion_2->setText(ui->tableWidget->item(row, 4)->text());
    ui->fecha->setDate(QDate::fromString(ui->tableWidget->item(row, 5)->text(), "yyyy-MM-dd"));
    ui->lote_2->setValue(ui->tableWidget->item(row, 6)->text().toDouble());
    ui->notes_2->setPlainText(ui->tableWidget->item(row, 7)->text());
}

// AGREGAR
void MainWindow::on_agregar_clicked()
{
    QString nombre = ui->nombre_2->text();
    QString tipo = ui->tipo_2->text();
    double cantidad = ui->cantidad->value();
    QString ubicacion = ui->ubicacion_2->text();
    QString fecha = ui->fecha->date().toString("yyyy-MM-dd");
    int lote = 0;
    QString notes = ui->notes_2->toPlainText();

    Component nuevo(-1, nombre, tipo, cantidad, ubicacion, fecha, lote, notes);
    if (m_inventory->addComponent(nuevo)) {
        QMessageBox::information(this, "Éxito", "Componente agregado.");
        updateComponentTable(ui->buscar_2->text());
        clearForm();
    } else {
        QMessageBox::warning(this, "Error", "No se pudo agregar el componente.");
    }
}

// EDITAR
void MainWindow::on_editar_clicked()
{
    auto selected = ui->tableWidget->selectedItems();
    if (selected.isEmpty())
        return;

    int row = selected.first()->row();
    int id = ui->tableWidget->item(row, 0)->text().toInt();
    QString nombre = ui->nombre_2->text();
    QString tipo = ui->tipo_2->text();
    double cantidad = ui->cantidad->value();
    QString ubicacion = ui->ubicacion_2->text();
    QString fecha = ui->fecha->date().toString("yyyy-MM-dd");
    int lote = 0;
    QString notes = ui->notes_2->toPlainText();

    Component actualizado(id, nombre, tipo, cantidad, ubicacion, fecha, lote, notes);
    if (m_inventory->updateComponent(actualizado)) {
        QMessageBox::information(this, "Éxito", "Componente actualizado.");
        updateComponentTable(ui->buscar_2->text());
        clearForm();
    } else {
        QMessageBox::warning(this, "Error", "No se pudo actualizar el componente.");
    }
}

// ELIMINAR
void MainWindow::on_eliminar_clicked()
{
    auto selected = ui->tableWidget->selectedItems();
    if (selected.isEmpty())
        return;

    int row = selected.first()->row();
    int id = ui->tableWidget->item(row, 0)->text().toInt();

    if (m_inventory->removeComponent(id)) {
        QMessageBox::information(this, "Éxito", "Componente eliminado.");
        updateComponentTable(ui->buscar_2->text());
        clearForm();
    } else {
        QMessageBox::warning(this, "Error", "No se pudo eliminar el componente.");
    }
}

// NUEVO
void MainWindow::on_nuevo_clicked()
{
    clearForm();
}

// CAMBIO DE SELECCIÓN EN TABLA
void MainWindow::on_tableWidget_itemSelectionChanged()
{
    loadSelectedComponentData();
}

// BÚSQUEDA EN VIVO
void MainWindow::on_buscar_2_textChanged(const QString &text)
{
    // Usa tu InventoryManager para filtrar los componentes
    QList<Component> filtrados = m_inventory->filterComponents(text);

    // Muestra la tabla sólo con los componentes filtrados
    ui->tableWidget->setRowCount(filtrados.size());
    ui->tableWidget->setColumnCount(6); // O 8, según las columnas visibles

    // Rellena la fila con los datos filtrados:
    int row = 0;
    for (const auto& c : filtrados) {
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(c.getId())));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(c.getName()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(c.getType()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(c.getQuantity())));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(c.getLocation()));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(c.getPurchaseDate()));
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem(QString::number(c.getLote())));
        ui->tableWidget->setItem(row, 7, new QTableWidgetItem(c.getNotes()));
        ++row;
    }
}
