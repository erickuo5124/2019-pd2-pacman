#include "movableitem.h"
#include <QPainter>

MovableItem::MovableItem(qreal x, qreal y, qreal d, QGraphicsItem *parent) :
    QGraphicsEllipseItem (x, y, d, d, parent)
{

}

void MovableItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::SolidPattern);
    painter->setPen(Qt::gray);
    painter->setBrush(Qt::gray);
    painter->drawEllipse(rect());
}
