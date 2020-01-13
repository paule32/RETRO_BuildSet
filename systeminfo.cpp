#include "systeminfo.h"
#include "mainwindow.h"

SystemInfo::SystemInfo(QWidget *parent) : QWidget(parent)
{
    infoText = new QPlainTextEdit(parent);
    infoText->move(570,0);
    infoText->resize(156,58);
    infoText->setStyleSheet("background-color:lime;");
    infoText->show();
}
