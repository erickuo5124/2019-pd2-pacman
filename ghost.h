#ifndef GHOST_H
#define GHOST_H

#include "moveableitem.h"
#include "pacman.h"

class Ghost : public MoveableItem
{
    Q_OBJECT

public:
    Ghost( PacMan *, Map *, QWidget *parent = nullptr);
    virtual void move()=0;
    virtual void reset()=0;

protected:
    PacMan *pacman;
    int goX, goY, togoX, togoY, targetX, targetY;
    int timer, counter;
    bool isIntersection();
    int getDistance(int, int);
    void detectCollide();
    bool isScared=false;
    QTimer *scaredTimer = nullptr;

private slots:
    virtual void callMove()=0;
    void scared();
    void freeze();
    void count();
};

class Blinky : public Ghost
{
    Q_OBJECT

public:
    Blinky( PacMan *, Map *, QWidget *parent = nullptr);
    void move();
    void reset();

private slots:
    void callMove();
};

class Pinky : public Ghost
{
    Q_OBJECT

public:
    Pinky( PacMan *, Map *, QWidget *parent = nullptr);
    void move();
    void reset();

private slots:
    void callMove();
};

class Inky : public Ghost
{
    Q_OBJECT

public:
    Inky( PacMan *, Map *, QWidget *parent = nullptr);
    void move();
    void reset();

private slots:
    void callMove();
};

class Clyde : public Ghost
{
    Q_OBJECT

public:
    Clyde( PacMan *, Map *, QWidget *parent = nullptr);
    void move();
    void reset();

private slots:
    void callMove();
};

#endif // GHOST_H
