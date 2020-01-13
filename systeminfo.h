#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H

#include <QObject>
#include <QWidget>
#include <QPlainTextEdit>

class SystemInfo : public QWidget
{
    Q_OBJECT
public:
    explicit SystemInfo(QWidget *parent = nullptr);
    QPlainTextEdit * infoText;
signals:

public slots:
};

#endif // SYSTEMINFO_H
