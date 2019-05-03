#include "squarepathitem.h"
#include <QtMath>

#define ITEM_RADIUS 10
#define FPS 50
#define PERIOD 4

SquarePathItem::SquarePathItem(const QPointF basePoint, qreal pathEdge, QGraphicsItem *parent) :
    MovableItem(0, 0, ITEM_RADIUS * 2, parent),
    basePoint(basePoint),
    pathEdge(pathEdge),
    currentDist(0)
{
    auto halfEdge = pathEdge / 2;
    this->setPos(basePoint - QPointF(halfEdge, halfEdge));
}

void SquarePathItem::move()
{
    static const qreal dist_per_frame = (4 * pathEdge) / (PERIOD * FPS);
    static const QPointF direction[] = { QPointF(dist_per_frame, 0), QPointF(0, dist_per_frame),
                                         QPointF(-dist_per_frame, 0), QPointF(0, -dist_per_frame) };

    currentDist += dist_per_frame;

    auto i = qFloor(currentDist / pathEdge) % 4;

    this->setPos(pos() + direction[i]);
}
