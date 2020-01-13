#include <QtCore/QLibraryInfo>
#include <QtWidgets/QApplication>
#include <QtHelp/QHelpEngine>
#include <QtHelp/QHelpEngineCore>
#include <QMessageBox>

#include "helpbrowser.h"

HelpBrowser::HelpBrowser(QWidget *parent)
    : QTextBrowser(parent)
{
}

