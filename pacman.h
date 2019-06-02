#ifndef PACMAN_H
#define PACMAN_H

#include "moveableitem.h"
#include <QKeyEvent>

class PacMan : public MoveableItem
{
    Q_OBJECT

public:
    PacMan( Map *,QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent *event);
    void move();
    int getX();
    int getY();

private:
    QPixmap piccopy[4];
    int goX, goY, togoX, togoY;
    QKeyEvent *next = nullptr;
    int num=0, add=1;
    bool stop = false;

private slots:
    void callMove();
    void animation();
    void freeze();
};

#endif // PACMAN_H
