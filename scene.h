#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QRectF>

#include <QPainter>
#include <QtWidgets>
#include <QtWidgets/QGraphicsScene>

#include <QGraphicsScene>
#include <QGraphicsSceneDragDropEvent>

class Scene: public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent=nullptr);
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


#if 0
#include <QtWidgets>

extern void
makegrid(
	QGraphicsItemGroup &qItemGrp,
	const QRect &rect,
	int gridSize,
	const QColor &gridColor);

class Canvas: public QGraphicsView {
  private:
    int _gridSize;
    QColor _gridColor;
    bool _gridVisible;

  public:
    explicit Canvas(QWidget *pQParent = nullptr):
      QGraphicsView(pQParent),
     _gridSize(20), _gridColor(0x0a8affu), _gridVisible(true)
    { }

    bool gridVisible() const { return _gridVisible; }
    void setGridVisible(bool gridVisible)
    {
      _gridVisible = gridVisible;
      viewport()->update();
    }

  protected:
    virtual void paintEvent(QPaintEvent *pQEvent) override
    {
      QPainter qPainter(viewport());
      if (_gridVisible) {
        const int wView = viewport()->width(), hView = viewport()->height();
        const QPointF offs = mapToScene(0, 0);
        qPainter.setPen(_gridColor);
        for (int x = (int)offs.x() % _gridSize; x < wView; x += _gridSize) {
          qPainter.drawLine(x, 0, x, hView - 1);
        }
        for (int y = (int)offs.y() % _gridSize; y < hView; y += _gridSize) {
          qPainter.drawLine(0, y, wView - 1, y);
        }
      }
      QGraphicsView::paintEvent(pQEvent);
    }
};
#endif

#endif
