#include "movableitem.h"
#include <QPainter>

MovableItem::MovableItem(qreal x, qreal y, qreal d, QGraphicsItem *parent) :
    QGraphicsEllipseItem (x, y, d, d, parent)
{

}

void MovableItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Reference: https://doc.qt.io/archives/qt-4.8/qgraphicsitem.html#paint

    painter->setPen(Qt::gray);
    painter->setBrush(Qt::SolidPattern);
    painter->setBrush(Qt::gray);
    painter->drawEllipse(rect());
}
