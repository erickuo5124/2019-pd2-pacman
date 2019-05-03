#ifndef SQUAREPATHITEM_H
#define SQUAREPATHITEM_H

#include "movableitem.h"

class SquarePathItem : public MovableItem
{
public:
    SquarePathItem(const QPointF basePoint, qreal pathEdge, QGraphicsItem *parent = nullptr);

    void move();

private:
    QPointF basePoint;
    qreal pathEdge;
    qreal currentDist;
};

#endif // SQUAREPATHITEM_H
