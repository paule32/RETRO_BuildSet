#ifndef FLOWITEM_H
#define FLOWITEM_H

#include <QWidget>
#include <QVariant>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class FlowPixmapItem: public QGraphicsPixmapItem
{
public:
    FlowPixmapItem(QGraphicsPixmapItem * parent = nullptr);
//    itemChange(GraphicsPixmapItemChange change, const QVariant &value);
};

#endif  // FLOWITEM_H