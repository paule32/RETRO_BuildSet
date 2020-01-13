#ifndef HELPBROWSER_H
#define HELPBROWSER_H

#include <QtWidgets/QTextBrowser>
#include <QtHelp/QHelpEngine>

class HelpBrowser: public QTextBrowser
{
    Q_OBJECT

public:
    HelpBrowser(QWidget *parent);
};

#endif
