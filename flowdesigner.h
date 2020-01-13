#ifndef FLOWDESIGNER_H
#define FLOWDESIGNER_H

#include <QMessageBox>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include "scene.h"
#include "flowitem.h"

class FlowDesigner : public QGraphicsView
{
public:
    explicit FlowDesigner(QWidget *parent = nullptr);
    QPointF mouseCoords;
    Scene *myscene = nullptr;
protected:
    virtual void dragEnterEvent(QDragEnterEvent *event);
    virtual void dropEvent(QDropEvent *event);
};

#endif // FLOWDESIGNER_H
