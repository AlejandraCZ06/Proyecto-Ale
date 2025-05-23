/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QScrollBar *vertical;
    QGroupBox *groupBox;
    QLineEdit *nombre_2;
    QDoubleSpinBox *cantidad;
    QPushButton *agregar;
    QPushButton *editar;
    QPushButton *eliminar;
    QDateEdit *fecha;
    QLineEdit *tipo_2;
    QLineEdit *ubicacion_2;
    QLabel *nombre;
    QLabel *tipo;
    QLabel *ubicacion;
    QLabel *cantidad_2;
    QLabel *fecha_2;
    QPushButton *nuevo;
    QLabel *lote;
    QDoubleSpinBox *lote_2;
    QPlainTextEdit *notes_2;
    QLabel *notes;
    QLineEdit *buscar_2;
    QLabel *buscar;
    QPushButton *exportar;
    QScrollBar *horizontal;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(753, 623);
        MainWindow->setStyleSheet(QString::fromUtf8("font: 700 italic 9pt \"Nimbus Sans [URW ]\";"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(30, 50, 681, 361));
        vertical = new QScrollBar(centralwidget);
        vertical->setObjectName(QString::fromUtf8("vertical"));
        vertical->setGeometry(QRect(710, 50, 16, 361));
        vertical->setOrientation(Qt::Vertical);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 430, 691, 141));
        nombre_2 = new QLineEdit(groupBox);
        nombre_2->setObjectName(QString::fromUtf8("nombre_2"));
        nombre_2->setGeometry(QRect(70, 20, 113, 22));
        cantidad = new QDoubleSpinBox(groupBox);
        cantidad->setObjectName(QString::fromUtf8("cantidad"));
        cantidad->setGeometry(QRect(80, 60, 60, 23));
        agregar = new QPushButton(groupBox);
        agregar->setObjectName(QString::fromUtf8("agregar"));
        agregar->setGeometry(QRect(180, 110, 80, 22));
        editar = new QPushButton(groupBox);
        editar->setObjectName(QString::fromUtf8("editar"));
        editar->setGeometry(QRect(280, 110, 80, 22));
        eliminar = new QPushButton(groupBox);
        eliminar->setObjectName(QString::fromUtf8("eliminar"));
        eliminar->setGeometry(QRect(380, 110, 80, 22));
        fecha = new QDateEdit(groupBox);
        fecha->setObjectName(QString::fromUtf8("fecha"));
        fecha->setGeometry(QRect(380, 60, 110, 23));
        tipo_2 = new QLineEdit(groupBox);
        tipo_2->setObjectName(QString::fromUtf8("tipo_2"));
        tipo_2->setGeometry(QRect(270, 20, 91, 22));
        ubicacion_2 = new QLineEdit(groupBox);
        ubicacion_2->setObjectName(QString::fromUtf8("ubicacion_2"));
        ubicacion_2->setGeometry(QRect(480, 20, 81, 22));
        nombre = new QLabel(groupBox);
        nombre->setObjectName(QString::fromUtf8("nombre"));
        nombre->setGeometry(QRect(10, 20, 57, 21));
        tipo = new QLabel(groupBox);
        tipo->setObjectName(QString::fromUtf8("tipo"));
        tipo->setGeometry(QRect(236, 20, 31, 21));
        ubicacion = new QLabel(groupBox);
        ubicacion->setObjectName(QString::fromUtf8("ubicacion"));
        ubicacion->setGeometry(QRect(416, 20, 61, 21));
        cantidad_2 = new QLabel(groupBox);
        cantidad_2->setObjectName(QString::fromUtf8("cantidad_2"));
        cantidad_2->setGeometry(QRect(20, 60, 60, 21));
        fecha_2 = new QLabel(groupBox);
        fecha_2->setObjectName(QString::fromUtf8("fecha_2"));
        fecha_2->setGeometry(QRect(336, 60, 41, 21));
        nuevo = new QPushButton(groupBox);
        nuevo->setObjectName(QString::fromUtf8("nuevo"));
        nuevo->setGeometry(QRect(70, 110, 80, 22));
        lote = new QLabel(groupBox);
        lote->setObjectName(QString::fromUtf8("lote"));
        lote->setGeometry(QRect(200, 60, 31, 21));
        lote_2 = new QDoubleSpinBox(groupBox);
        lote_2->setObjectName(QString::fromUtf8("lote_2"));
        lote_2->setGeometry(QRect(240, 60, 60, 23));
        notes_2 = new QPlainTextEdit(groupBox);
        notes_2->setObjectName(QString::fromUtf8("notes_2"));
        notes_2->setGeometry(QRect(540, 60, 141, 71));
        notes = new QLabel(groupBox);
        notes->setObjectName(QString::fromUtf8("notes"));
        notes->setGeometry(QRect(500, 60, 41, 21));
        buscar_2 = new QLineEdit(centralwidget);
        buscar_2->setObjectName(QString::fromUtf8("buscar_2"));
        buscar_2->setGeometry(QRect(120, 10, 181, 22));
        buscar = new QLabel(centralwidget);
        buscar->setObjectName(QString::fromUtf8("buscar"));
        buscar->setGeometry(QRect(66, 10, 51, 21));
        exportar = new QPushButton(centralwidget);
        exportar->setObjectName(QString::fromUtf8("exportar"));
        exportar->setGeometry(QRect(559, 10, 91, 22));
        horizontal = new QScrollBar(centralwidget);
        horizontal->setObjectName(QString::fromUtf8("horizontal"));
        horizontal->setGeometry(QRect(40, 410, 671, 16));
        horizontal->setOrientation(Qt::Horizontal);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        agregar->setText(QCoreApplication::translate("MainWindow", "Agregar", nullptr));
        editar->setText(QCoreApplication::translate("MainWindow", "Editar", nullptr));
        eliminar->setText(QCoreApplication::translate("MainWindow", "Eliminar", nullptr));
        nombre->setText(QCoreApplication::translate("MainWindow", "Nombre:", nullptr));
        tipo->setText(QCoreApplication::translate("MainWindow", "Tipo:", nullptr));
        ubicacion->setText(QCoreApplication::translate("MainWindow", "Ubicaci\303\263n:", nullptr));
        cantidad_2->setText(QCoreApplication::translate("MainWindow", "Cantidad:", nullptr));
        fecha_2->setText(QCoreApplication::translate("MainWindow", "Fecha:", nullptr));
        nuevo->setText(QCoreApplication::translate("MainWindow", "Nuevo item", nullptr));
        lote->setText(QCoreApplication::translate("MainWindow", "Lote:", nullptr));
        notes->setText(QCoreApplication::translate("MainWindow", "Notas:", nullptr));
        buscar->setText(QCoreApplication::translate("MainWindow", "Buscar:", nullptr));
        exportar->setText(QCoreApplication::translate("MainWindow", "Exportar CSV", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
