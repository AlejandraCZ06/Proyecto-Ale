#pragma once
#include <QMainWindow>

namespace Ui { class MainWindow; }
class InventoryManager;
class ComponentForm;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(InventoryManager*, QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void onAddClicked();
    void onEditClicked();
    void onDeleteClicked();
    void onGenerateReport();
    void refreshTable();

private:
    Ui::MainWindow* ui;
    InventoryManager* m_invMgr;
};