#include <QDrag>
#include <QMimeData>
#include <QPixmap>

#include "mainwindow.h"

#include "c64screen.h"
#include "c64scene.h"

c64Screen::c64Screen(QWidget *parent)
    : QGraphicsView (parent)
{
    myscene = new c64Scene(this);
    myscene->setSceneRect(0.0,0.0,320.0,200.0);

    setScene(myscene);
    setAcceptDrops(true);

    setDragMode(QGraphicsView::RubberBandDrag);
}
