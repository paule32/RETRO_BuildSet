#include "mainwindow.h"
#include <QApplication>

class MainWindow *main_window = nullptr;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    main_window = new MainWindow;
    main_window->setStyleSheet("QMenu::item:selected { backgroind-color: blue; color: yellow;");
    
    main_window->show();

    return a.exec();
}
