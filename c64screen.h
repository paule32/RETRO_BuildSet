#ifndef C64SCREEN_H
#define C64SCREEN_H

#include <QMessageBox>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include "c64scene.h"

class c64Screen : public QGraphicsView
{
public:
    explicit c64Screen(QWidget *parent = nullptr);
    QPointF mouseCoords;
    c64Scene *myscene = nullptr;
};

#endif // C64SCREEN_H
