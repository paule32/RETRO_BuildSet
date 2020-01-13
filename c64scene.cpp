#include <QDrag>
#include <QPaintEngine>

#include "c64scene.h"

c64Scene::c64Scene(QObject *parent) :
    QGraphicsScene(parent), gridSize(10)
{
    Q_ASSERT(gridSize > 0);
}

void
c64Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->update();
    QGraphicsScene::mouseMoveEvent(event);
}
void
c64Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->update();
    QGraphicsScene::mousePressEvent(event);
}
void
c64Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->update();
    QGraphicsScene::mouseReleaseEvent(event);
}

void
c64Scene::drawBackground(QPainter *painter, const QRectF &rect)
{
#if 0
    const int gridSize = 2;
 
    qreal left = int(rect.left()) - (int(rect.left()) % gridSize);
    qreal top  = int(rect.top ()) - (int(rect.top ()) % gridSize);
 
    QVarLengthArray<QLineF, 100> lines;
 
    for (qreal x = left; x < rect.right(); x += gridSize)
        lines.append(QLineF(x, rect.top(), x, rect.bottom()));
    for (qreal y = top; y < rect.bottom(); y += gridSize)
        lines.append(QLineF(rect.left(), y, rect.right(), y));
#endif
    painter->setBrush(QColor::fromRgb(171, 163, 255));
    painter->fillRect(QRectF(0.0,0.0,320.0,200.0),painter->brush());

#if 0
    painter->setBrush(QColor(Qt::black));
    painter->drawLines(lines.data(), lines.size());
#endif
}

void
c64Scene::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    event->accept();
}
