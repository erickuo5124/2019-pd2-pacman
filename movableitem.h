#ifndef MOVABLEITEM_H
#define MOVABLEITEM_H

#include <QObject>
#include <QGraphicsEllipseItem>

class MovableItem : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT

public:
    MovableItem(qreal x, qreal y, qreal d, QGraphicsItem *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    virtual void move() = 0;
};

#endif // MOVABLEITEM_H
