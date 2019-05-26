#ifndef PACMAN_H
#define PACMAN_H

#include "moveableitem.h"
#include "map.h"
#include <QKeyEvent>
#include <QTimer>

class PacMan : MoveableItem
{
    Q_OBJECT

public:
    PacMan( Map *, QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent *event);
    void move();

private:
    Map *map;
    QPixmap piccopy[4];
    int goX, goY, togoX, togoY;
    QTimer *myTimer = nullptr, *movie;
    bool canMove(int, int);
    QKeyEvent *next = nullptr;
    void eat();
    int num=0, add=1;

private slots:
    void callMove();
    void animation();
};

#endif // PACMAN_H
