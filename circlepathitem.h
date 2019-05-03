#ifndef CIRCLEPATHITEM_H
#define CIRCLEPATHITEM_H

#include "movableitem.h"

class CirclePathItem : public MovableItem
{
    Q_OBJECT

public:
    CirclePathItem(const QPointF basePoint, qreal pathRadius, QGraphicsItem *parent = nullptr);

    void move();

private:
    QPointF basePoint;
    qreal pathRadius;
    qreal currentRad;
};

#endif // CIRCLEPATHITEM_H
