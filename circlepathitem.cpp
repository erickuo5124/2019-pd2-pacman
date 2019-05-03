#include "circlepathitem.h"
#include <QtMath>
#include <QPainter>
#include <QDebug>

#define ITEM_RADIUS 10
#define FPS 50
#define PERIOD 4
#define PI 3.1415926535897

CirclePathItem::CirclePathItem(const QPointF basePoint, qreal pathRadius, QGraphicsItem *parent) :
    MovableItem(0, 0, ITEM_RADIUS * 2, parent),
    basePoint(basePoint),
    pathRadius(pathRadius),
    currentRad(0)
{
    auto rProject = pathRadius * QPointF(qCos(currentRad), -qSin(currentRad));
    this->setPos(basePoint + rProject - QPointF(ITEM_RADIUS, ITEM_RADIUS));
}

void CirclePathItem::move()
{
    static const qreal rad_per_frame = (2 * PI) / (4 * 50);

    currentRad += rad_per_frame;

    auto rProject = pathRadius * QPointF(qCos(currentRad), -qSin(currentRad));
    this->setPos(basePoint + rProject - QPointF(ITEM_RADIUS, ITEM_RADIUS));
}
