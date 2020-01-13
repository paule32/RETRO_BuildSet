#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QMessageBox>
#include <QHelpEngine>
#include <QSplitter>
#include <QTextDocument>
#include <QHelpContentWidget>
#include <QDrag>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "helpbrowser.h"
#include "systeminfo.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->helpDocker->setAutoFillBackground(true);
    ui->helpDocker->setVisible(false);

    ui->mainToolBar->insertWidget(
    ui->actionHelp,new SystemInfo(
    ui->mainToolBar));

    ui->screenA->setStyleSheet("background-color: rgb(171, 163, 255);");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeWidgetCompos_itemActivated(QTreeWidgetItem *item, int column)
{
    Q_UNUSED(column);
    QFont afont;

    afont.setBold(false);
    for(int i = 0; i < ui->treeWidgetCompos->topLevelItemCount(); ++i) {
        QTreeWidgetItem *_item =
        ui->treeWidgetCompos->topLevelItem(i);
        _item->setFont(0,afont);
    }
    afont.setBold(true ); item->setFont(0,afont);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_F1) {
        QUrl path = QUrl("file://" +
        QCoreApplication::applicationDirPath() + "/help/docs/index.html");
        ui->textContent->setSource(path);
        ui->helpDocker->setVisible(true);
    }
    else if (event->key() == Qt::Key_Escape) {
        if (ui->helpDocker->isVisible()) {
            ui->helpDocker->setVisible(false);
            ui->editor->setFocus();
        }
    }
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_treeWidgetCompos_itemPressed(QTreeWidgetItem *item, int column)
{
    Q_UNUSED(item);
    Q_UNUSED(column);

    ui->flowBoard->setAcceptDrops(true);

    QDrag *drag = new QDrag(ui->treeWidgetCompos);
    QMimeData *mimeData = new QMimeData;

    mimeData->setText("A Item");
    drag->setMimeData(mimeData);

    Qt::DropAction dropAction = drag->exec();
}

void MainWindow::on_actionHelp_triggered()
{
    if(!ui->helpDocker->isVisible()) {
        ui->helpDocker->setVisible(true);
        ui->helpDocker->setAutoFillBackground(true);
    }   else {
        ui->helpButtonWidget->setAutoFillBackground(true);
        ui->helpDocker->setVisible(false);
        ui->helpButtonWidget->setAutoFillBackground(true);
    }
}

void MainWindow::on_treeWidget_3_itemPressed(QTreeWidgetItem *item, int column)
{
    Q_UNUSED(item);
    Q_UNUSED(column);

    ui->flowBoard->setAcceptDrops(true);

    QDrag *drag = new QDrag(ui->treeWidgetCompos);
    QMimeData *mimeData = new QMimeData;

    mimeData->setText("B Item");
    drag->setMimeData(mimeData);

    Qt::DropAction dropAction = drag->exec();
}
