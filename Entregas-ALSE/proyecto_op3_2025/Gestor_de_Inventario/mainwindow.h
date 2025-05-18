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

private:
    Ui::MainWindow *ui;
    InventoryManager *m_inventory;
    DatabaseManager *m_db;

    void updateComponentTable();
};

#endif // MAINWINDOW_H
