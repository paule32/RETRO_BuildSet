#include <QDrag>
#include <QPaintEngine>

#include "scene.h"

Scene::Scene(QObject *parent) :
    QGraphicsScene(parent), gridSize(10)
{
    Q_ASSERT(gridSize > 0);
}

void
Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->update();
    QGraphicsScene::mouseMoveEvent(event);
}
void
Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->update();
    QGraphicsScene::mousePressEvent(event);
}
void
Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->update();
    QGraphicsScene::mouseReleaseEvent(event);
}

void
Scene::drawBackground(QPainter *painter, const QRectF &rect)
{
    const int gridSize = 15;
 
    qreal left = int(rect.left()) - (int(rect.left()) % gridSize);
    qreal top  = int(rect.top ()) - (int(rect.top ()) % gridSize);
 
    QVarLengthArray<QLineF, 100> lines;
 
    for (qreal x = left; x < rect.right(); x += gridSize)
        lines.append(QLineF(x, rect.top(), x, rect.bottom()));
    for (qreal y = top; y < rect.bottom(); y += gridSize)
        lines.append(QLineF(rect.left(), y, rect.right(), y));

    painter->setBrush(QColor::fromRgb(230,249,255));
    painter->fillRect(QRectF(0.0,0.0,1000.0,1000.0),painter->brush());

    painter->setBrush(QColor(Qt::black));
    painter->drawLines(lines.data(), lines.size());

#if 0
    QPen pen;
    painter->setPen(pen);

    qreal left = int(rect.left()) - (int(rect.left()) % gridSize);
    qreal top  = int(rect.top ()) - (int(rect.top ()) % gridSize);

    QVector<QPointF> points;

    for (qreal x = left; x < rect.right(); x += gridSize) {
        for (qreal y = top; y < rect.bottom(); y += gridSize){
            points.append(QPointF(x,y));
        }
    }
    painter->drawPoints(points.data(), points.size());
#endif
}

void
Scene::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    event->accept();
}

#if 0
void
makegrid(
    QGraphicsItemGroup &qItemGrp,
    const QRect &rect,
    qreal gridSize = 20,
    const QColor &gridColor = 0x0a8affu)
{
    for (int x = rect.x(), xE = x + rect.width(); x < xE; x += gridSize) {
	QGraphicsLineItem *pQItem = new
	QGraphicsLineItem(x, rect.y(), x, rect.height() - 1);

	pQItem->setPen(gridColor);
	qItemGrp.addToGroup(pQItem);
    }

    for (int y = rect.y(), yE = y + rect.height(); y < yE; y += gridSize) {
	QGraphicsLineItem *pQItem = new
	QGraphicsLineItem(rect.x(), y, rect.width() - 1, y);

	pQItem->setPen(gridColor);
	qItemGrp.addToGroup(pQItem);
    }
}
#endif