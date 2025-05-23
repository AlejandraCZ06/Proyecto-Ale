#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTableWidgetItem>
#include "reportgenerator.h"
#include <QFileDialog>
#include <QMessageBox>

// -- Tu constructor, destructor y configuración de la tabla --
MainWindow::MainWindow(InventoryManager *inventory, DatabaseManager *db, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_inventory(inventory), m_db(db)
{
    ui->setupUi(this);

    // Configuración visual y lógica
    ui->tableWidget->setColumnCount(8);
    QStringList headers = { "ID", "Nombre", "Tipo", "Cantidad", "Ubicación", "Fecha", "Lote", "Notas" };
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    updateComponentTable();
    // conectas el slot de selección solo si no usas el sistema automático de Qt Creator
}

MainWindow::~MainWindow()
{
    delete ui;
}
// ========================== SELECCION TABLA ==========================
void MainWindow::on_tableWidget_itemSelectionChanged()
{
    // Carga los datos del componente seleccionado desde la tabla al formulario
    loadSelectedComponentData();
}
// ========================== ACTUALIZAR TABLA ==========================
void MainWindow::updateComponentTable(const QString &filterText)
{
    QList<Component> componentes;

    // Si hay filtro, directamente usa la función de InventoryManager (más eficiente)
    if (!filterText.isEmpty()) {
        componentes = m_inventory->filterComponents(filterText);
    } else {
        componentes = m_inventory->getComponents();
    }

    // Limpia tabla y ajusta filas
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(componentes.size());

    // SOLO ES NECESARIO ASIGNAR HEADERS UNA SOLA VEZ, usualmente en el constructor
    // Dejarlo aquí solo si se borra accidentalmente en clearContents y tu UI lo requiere.
    QStringList headers = {"ID", "Nombre", "Tipo", "Cantidad", "Ubicación", "Fecha", "Lote", "Notas"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // Rellenar la tabla con los datos
    for (int row = 0; row < componentes.size(); ++row) {
        const Component& c = componentes[row];
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(c.getId())));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(c.getName()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(c.getType()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(c.getQuantity())));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(c.getLocation()));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(c.getPurchaseDate()));
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem(QString::number(c.getLote())));
        ui->tableWidget->setItem(row, 7, new QTableWidgetItem(c.getNotes()));
    }
    // Mejor UX: autoajusta el ancho de columnas
    ui->tableWidget->resizeColumnsToContents();
}
// ========================== LIMPIAR FORMULARIO ==========================
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

// ========================== CARGAR DATOS SELECCIONADOS ==========================
void MainWindow::loadSelectedComponentData()
{
    auto selected = ui->tableWidget->selectedItems();
    if (selected.isEmpty()) {
        clearForm(); // Opcional: limpia si no hay selección
        return;
    }

    int row = selected.first()->row();

    ui->nombre_2->setText(ui->tableWidget->item(row, 1)->text());
    ui->tipo_2->setText(ui->tableWidget->item(row, 2)->text());
    ui->cantidad->setValue(ui->tableWidget->item(row, 3)->text().toInt());
    ui->ubicacion_2->setText(ui->tableWidget->item(row, 4)->text());

    // Robustez en el parseo de la fecha
    QDate date = QDate::fromString(ui->tableWidget->item(row, 5)->text(), Qt::ISODate);
    if (!date.isValid())
        date = QDate::fromString(ui->tableWidget->item(row, 5)->text(), "yyyy-MM-dd");
    if (date.isValid())
        ui->fecha->setDate(date);
    else
        ui->fecha->setDate(QDate::currentDate());

    ui->lote_2->setValue(ui->tableWidget->item(row, 6)->text().toInt());
    ui->notes_2->setPlainText(ui->tableWidget->item(row, 7)->text());
}
// ========================== BOTÓN NUEVO ==========================
void MainWindow::on_nuevo_clicked()
{
    clearForm();
}

// ========================== BOTÓN AGREGAR ==========================
void MainWindow::on_agregar_clicked()
{
    // Construye un nuevo componente desde los valores del formulario (ID -1 porque aún no existe en la BD)
    Component nuevo(
        -1,
        ui->nombre_2->text(),
        ui->tipo_2->text(),
        ui->cantidad->value(),
        ui->ubicacion_2->text(),
        ui->fecha->date().toString("yyyy-MM-dd"),
        ui->lote_2->value(),
        ui->notes_2->toPlainText()
    );

    // Validación simple: campos básicos (puedes hacerla más estricta)
    if (nuevo.getName().isEmpty() || nuevo.getType().isEmpty()) {
        QMessageBox::warning(this, "Faltan datos", "Debes ingresar al menos nombre y tipo.");
        return;
    }

    if (m_inventory->addComponent(nuevo)) {
        QMessageBox::information(this, "Éxito", "Componente agregado.");
        updateComponentTable(ui->buscar_2->text());
        clearForm();
    } else {
        QMessageBox::critical(this, "Error", "Error al agregar en la base de datos.");
    }
}
// ========================== BOTÓN EDITAR ==========================
void MainWindow::on_editar_clicked()
{
    auto selected = ui->tableWidget->selectedItems();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Sin selección", "Por favor, selecciona el componente que deseas editar.");
        return;
    }

    int row = selected.first()->row();
    int id = ui->tableWidget->item(row, 0)->text().toInt();

    Component actualizado(
        id,
        ui->nombre_2->text(),
        ui->tipo_2->text(),
        ui->cantidad->value(),
        ui->ubicacion_2->text(),
        ui->fecha->date().toString("yyyy-MM-dd"),
        ui->lote_2->value(),
        ui->notes_2->toPlainText()
    );

    if (m_inventory->updateComponent(actualizado)) {
        QMessageBox::information(this, "Éxito", "Componente actualizado.");
        updateComponentTable(ui->buscar_2->text());
        clearForm();
    } else {
        QMessageBox::critical(this, "Error", "Error al actualizar el componente.");
    }
}
// ========================== BOTÓN ELIMINAR ==========================
void MainWindow::on_eliminar_clicked()
{
    auto selected = ui->tableWidget->selectedItems();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Sin selección", "Selecciona un componente a eliminar.");
        return;
    }

    int row = selected.first()->row();
    int id = ui->tableWidget->item(row, 0)->text().toInt();

    // Confirmación antes de eliminar
    auto resp = QMessageBox::question(this, "Confirmar eliminación",
                "¿Seguro que deseas eliminar este componente?",
                QMessageBox::Yes | QMessageBox::No);
    if (resp != QMessageBox::Yes)
        return;

    if (m_inventory->removeComponent(id)) {
        QMessageBox::information(this, "Éxito", "Componente eliminado.");
        updateComponentTable(ui->buscar_2->text());
        clearForm();
    } else {
        QMessageBox::critical(this, "Error", "Error al eliminar el componente.");
    }
}
// ========================== BÚSQUEDA EN TIEMPO REAL ==========================
void MainWindow::on_buscar_2_textChanged(const QString &text)
{
    updateComponentTable(text);
    if (ui->tableWidget->rowCount() == 0)
        clearForm();
}

// ========================== EXPORTAR A CSV ==========================

void MainWindow::on_exportar_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Exportar a CSV", "", "CSV Files (*.csv)");
    if (filename.isEmpty())
        return;

    // Exporta TODO lo visible (si quieres solo lo filtrado actualmente)
    QList<Component> componentes;
    if (!ui->buscar_2->text().isEmpty())
        componentes = m_inventory->filterComponents(ui->buscar_2->text());
    else
        componentes = m_inventory->getComponents();

    if (ReportGenerator::exportToCSV(componentes, filename)) {
        QMessageBox::information(this, "Éxito", "Datos exportados correctamente a CSV.");
    } else {
        QMessageBox::warning(this, "Error", "No se pudo exportar el archivo CSV.");
    }
}
