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
    // Degradado en fondo y widgets principales
    QString qss = R"(
    QWidget {
        background: qlineargradient(
            spread:pad, x1:0, y1:0, x2:1, y2:1,
            stop:0 #e3f0ff, stop:1 #3984e8
        );
        color: #1a2340;
    }

    /* Tablas con fondo blanco/transparente y bordes */
    QTableWidget, QTableView {
        background: rgba(255,255,255,0.7);
        alternate-background-color: #b3d1ff;
        border: 1px solid #26577c;
        selection-background-color: #7ca7e7;
    }

    /* Celda de cantidad baja personalizada */
    QTableWidget::item {
        selection-background-color: #2257a7;
    }

    QHeaderView::section {
        background: #2661b8;
        color: white;
        font-weight: bold;
        border: 1px solid #8cb3d9;
    }

    QLabel {
        color: #1a2340;
        font-weight: bold;
    }

    QPushButton {
        background: qlineargradient(
            spread:pad, x1:0, y1:0, x2:1, y2:1,
            stop:0 #a0c1f7, stop:1 #185a9d
        );
        color: white;
        border-radius: 6px;
        border: 1px solid #2661b8;
        padding: 4px 10px;
        font-weight: bold;
    }

    QPushButton:hover {
        background: #0d305d;
    }

    QLineEdit, QSpinBox, QDoubleSpinBox, QDateEdit, QPlainTextEdit {
        background: #f0f7ff;
        border: 1px solid #7ca7e7;
        color: #253860;
        border-radius: 4px;
    }

    QStatusBar, QGroupBox {
        background: transparent;
    }
    )";

    // Aplica el stylesheet global
    qApp->setStyleSheet(qss);

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
    if (!filterText.isEmpty()) {
        componentes = m_inventory->filterComponents(filterText);
    } else {
        componentes = m_inventory->getComponents();
    }

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(componentes.size());
    QStringList headers = {"ID", "Nombre", "Tipo", "Cantidad", "Ubicación", "Fecha", "Lote", "Notas"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // ---- AGREGA o MODIFICA este bloque: ----
    const int lowStockThreshold = 3; // umbral configurable

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

        // ---- Resalta la celda de cantidad si está por debajo del umbral ----
        auto cantidadItem = ui->tableWidget->item(row, 3);
        if (cantidadItem && c.getQuantity() < lowStockThreshold) {
            cantidadItem->setBackground(Qt::red);
            cantidadItem->setForeground(Qt::white);
        } else if (cantidadItem) {
            cantidadItem->setBackground(Qt::white);
            cantidadItem->setForeground(Qt::black);
        }
    }
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
