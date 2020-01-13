#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Ui::MainWindow *ui;
private slots:
    void on_treeWidgetCompos_itemActivated(QTreeWidgetItem *item, int column);

    void on_actionExit_triggered();

    void on_treeWidgetCompos_itemPressed(QTreeWidgetItem *item, int column);

    void on_actionHelp_triggered();

    void on_treeWidget_3_itemPressed(QTreeWidgetItem *item, int column);

protected:
    virtual void keyPressEvent(QKeyEvent *event);
};

extern MainWindow *main_window;

#endif // MAINWINDOW_H
