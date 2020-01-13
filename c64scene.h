#ifndef C64SCENE_H
#define C64SCENE_H

#include <QObject>
#include <QRectF>

#include <QPainter>
#include <QtWidgets>
#include <QtWidgets/QGraphicsScene>

#include <QGraphicsScene>
#include <QGraphicsSceneDragDropEvent>

class c64Scene: public QGraphicsScene
{
    Q_OBJECT
public:
    explicit c64Scene(QObject *parent=nullptr);
    int getGridSize() const { return this->gridSize;}

protected:
    void drawBackground(QPainter *painter, const QRectF &rect);
    void dragMoveEvent(QGraphicsSceneDragDropEvent *event);

    void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    int gridSize;
};

#endif  // C64SCENE_H
