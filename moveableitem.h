#ifndef MOVEABLEITEM_H
#define MOVEABLEITEM_H

#include "map.h"
#include <QWidget>
#include <QLabel>
#include <QMovie>
#include <QList>
#include <QTimer>

class MoveableItem : public QWidget
{
    Q_OBJECT

public:
    MoveableItem(Map *, QWidget *parent = nullptr);//map
    virtual void move() = 0;
    QTimer *walkTimer = nullptr, *movieTimer;

protected:
    QPixmap picture;
    QList<QPixmap> pics;
    QLabel *character;
    Map *map;
    bool canMove(int, int);
};

#endif // MOVEABLEITEM_H
