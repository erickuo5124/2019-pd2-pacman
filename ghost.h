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

protected:
    PacMan *pacman;
    int goX, goY, togoX, togoY;
    bool isIntersection();


};

class Blinky : Ghost
{
    Q_OBJECT

public:
    Blinky( PacMan *, Map *, QWidget *parent = nullptr);
    void move();

private slots:
    void callMove();
};

class Pinky : Ghost
{
    Q_OBJECT

public:
    Pinky( PacMan *, Map *, QWidget *parent = nullptr);
    void move();

private slots:
    //void callMove();
};

class Inky : Ghost
{
    Q_OBJECT

public:
    Inky( PacMan *, Map *, QWidget *parent = nullptr);
    void move();

private slots:
    //void callMove();
};

class Clyde : Ghost
{
    Q_OBJECT

public:
    Clyde( PacMan *, Map *, QWidget *parent = nullptr);
    void move();

private slots:
    //void callMove();
};

#endif // GHOST_H
