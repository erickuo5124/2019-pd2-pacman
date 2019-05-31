#include "ghost.h"
#include <QDebug>

#define TIME 10
#define STEP 1
#define TURN_RIGHT togoX=STEP;togoY=0;
#define TURN_LEFT togoX=-STEP;togoY=0;
#define TURN_UP togoX=0;togoY=-STEP;
#define TURN_DOWN togoX=0;togoY=STEP;

Ghost::Ghost( PacMan *pacman, Map *map, QWidget *parent) :
    MoveableItem(map, parent),
    pacman(pacman)
{

}

bool Ghost::isIntersection(){
    int way=0;

    TURN_RIGHT
    if(canMove(togoX, togoY)) way++;
    TURN_LEFT
    if(canMove(togoX, togoY)) way++;
    TURN_UP
    if(canMove(togoX, togoY)) way++;
    TURN_DOWN
    if(canMove(togoX, togoY)) way++;

    //qDebug() << (way>2) << endl;

    return (way>2);
}

Blinky::Blinky( PacMan *pacman, Map *map, QWidget *parent) :
    Ghost(pacman, map, parent)
{
    pics.push_back(QPixmap(":/resource/img/blinky.png"));
    picture = pics[0];

    character = new QLabel(parent);
    character->setGeometry(270, 220, 20, 20);
    character->setPixmap(picture.scaled(20, 20, Qt::KeepAspectRatio));

    TURN_LEFT
    goX = -STEP; goY = 0;

    walkTimer = new QTimer(this);
    walkTimer->start(TIME);
    connect(walkTimer,SIGNAL(timeout()),this,SLOT(callMove()));
}

void Blinky::callMove(){ move(); }

void Blinky::move(){
    if(character->x()+goX<-20)
        character->move(559, character->y());
    else if(character->x()+goX>559)
        character->move(1, character->y());

    if(isIntersection()){
        int distance1 = 700000;
        int distance2;
        int maxX = 0, maxY = 0;

        TURN_UP
        if(canMove(togoX, togoY)){
            if(togoX!=-goX || togoY!=-goY){
                distance2 = pacman->getDistance(character->x()+togoX, character->y()+togoY);
                if(distance1>distance2){
                    distance1 = distance2;
                    maxX = togoX; maxY = togoY;
                }
            }
        }
        TURN_DOWN
        if(canMove(togoX, togoY)){
            if(togoX!=-goX || togoY!=-goY){
                distance2 = pacman->getDistance(character->x()+togoX, character->y()+togoY);
                if(distance1>distance2){
                    distance1 = distance2;
                    maxX = togoX; maxY = togoY;
                }
            }
        }
        TURN_LEFT
        if(canMove(togoX, togoY)){
            if(togoX!=-goX || togoY!=-goY){

                distance2 = pacman->getDistance(character->x()+togoX, character->y()+togoY);
                if(distance1>distance2){
                    distance1 = distance2;
                    maxX = togoX; maxY = togoY;
                }
            }
        }
        TURN_RIGHT
        if(canMove(togoX, togoY)){
            if(togoX!=-goX || togoY!=-goY){
                distance2 = pacman->getDistance(character->x()+togoX, character->y()+togoY);
                if(distance1>distance2){
                    distance1 = distance2;
                    maxX = togoX; maxY = togoY;
                }
            }
        }

        goX=maxX; goY=maxY;
        character->move(character->x()+goX, character->y()+goY);
        return;
    }

    while(!canMove(goX, goY)){
        TURN_UP
        if(canMove(togoX, togoY) && togoX!=goX && togoY!=goY) {
            goX = togoX; goY = togoY; break;
        }
        TURN_DOWN
        if(canMove(togoX, togoY) && togoX!=goX && togoY!=goY) {
            goX = togoX; goY = togoY; break;
        }
        TURN_LEFT
        if(canMove(togoX, togoY) && togoX!=goX && togoY!=goY) {
            goX = togoX; goY = togoY; break;
        }
        TURN_RIGHT
        if(canMove(togoX, togoY) && togoX!=goX && togoY!=goY) {
            goX = togoX; goY = togoY; break;
        }
    }

    character->move(character->x()+goX, character->y()+goY);
}

//need
Pinky::Pinky( PacMan *pacman, Map *map, QWidget *parent) :
    Ghost(pacman, map, parent)
{
    pics.push_back(QPixmap(":/resource/img/ghost.png"));
    picture = pics[0];

    character = new QLabel(parent);
    character->setGeometry(270, 220, 20, 20);
    character->setPixmap(picture.scaled(20, 20, Qt::KeepAspectRatio));

    TURN_LEFT
    goX = -STEP; goY = 0;

    walkTimer = new QTimer(this);
    walkTimer->start(TIME);
    connect(walkTimer,SIGNAL(timeout()),this,SLOT(callMove()));
}

void Pinky::move(){}

Inky::Inky( PacMan *pacman, Map *map, QWidget *parent) :
    Ghost(pacman, map, parent)
{
    pics.push_back(QPixmap(":/resource/img/ghost.png"));
    picture = pics[0];

    character = new QLabel(parent);
    character->setGeometry(270, 220, 20, 20);
    character->setPixmap(picture.scaled(20, 20, Qt::KeepAspectRatio));

    TURN_LEFT
    goX = -STEP; goY = 0;

    walkTimer = new QTimer(this);
    walkTimer->start(TIME);
    connect(walkTimer,SIGNAL(timeout()),this,SLOT(callMove()));
}

void Inky::move(){}

Clyde::Clyde( PacMan *pacman, Map *map, QWidget *parent) :
    Ghost(pacman, map, parent)
{
    pics.push_back(QPixmap(":/resource/img/ghost.png"));
    picture = pics[0];

    character = new QLabel(parent);
    character->setGeometry(270, 220, 20, 20);
    character->setPixmap(picture.scaled(20, 20, Qt::KeepAspectRatio));

    TURN_LEFT
    goX = -STEP; goY = 0;

    walkTimer = new QTimer(this);
    walkTimer->start(TIME);
    connect(walkTimer,SIGNAL(timeout()),this,SLOT(callMove()));
}

void Clyde::move(){}
