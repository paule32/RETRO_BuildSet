#include "flowitem.h"

FlowPixmapItem::FlowPixmapItem(QGraphicsPixmapItem *parent)
    : QGraphicsPixmapItem(parent)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
}

#if 0
QVariant
FlowPixmapItem::itemChange(
    GraphicsPixmapItemChange change,
    const QVariant &value)
{
    if (change == QGraphicsPixmapItem::ItemSelectedHasChanged)
        emit selectedChange(this);
    return value;
}
#endif