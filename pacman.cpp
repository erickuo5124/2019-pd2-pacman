#include "pacman.h"
#include <QDebug>
#include <QtGlobal>

#define STEP 1
#define TIME 10
#define FPS 60

PacMan::PacMan( Map *copymap, QWidget *parent) :
    MoveableItem(parent),
    map(copymap)
{
    pics.push_back(QPixmap(":/resource/img/pacman1.png"));
    pics.push_back(QPixmap(":/resource/img/pacman2.png"));
    pics.push_back(QPixmap(":/resource/img/pacman3.png"));
    pics.push_back(QPixmap(":/resource/img/pacman4.png"));

    picture = pics[2];

    character = new QLabel(parent);
    character->setGeometry(270, 460, 20, 20);
    character->setPixmap(picture.scaled(20, 20, Qt::KeepAspectRatio));
    this->setFocus();
}

void PacMan::keyPressEvent(QKeyEvent *event){

    if(event->key()==Qt::Key_Up){
        togoX = 0; togoY = -STEP;
        if(!canMove(togoX, togoY)){
            next = new QKeyEvent(*event);
            return;
        }
        goX = 0; goY = -STEP;
        piccopy[0] = pics[0].transformed(QTransform().rotate(270));
        piccopy[1] = pics[1].transformed(QTransform().rotate(270));
        piccopy[2] = pics[2].transformed(QTransform().rotate(270));
        piccopy[3] = pics[3].transformed(QTransform().rotate(270));
    }
    else if(event->key()==Qt::Key_Down){
        togoX = 0; togoY = STEP;
        if(!canMove(togoX, togoY)){
            next = new QKeyEvent(*event);
            return;
        }
        goX = 0; goY = STEP;
        piccopy[0] = pics[0].transformed(QTransform().rotate(90));
        piccopy[1] = pics[1].transformed(QTransform().rotate(90));
        piccopy[2] = pics[2].transformed(QTransform().rotate(90));
        piccopy[3] = pics[3].transformed(QTransform().rotate(90));
    }
    else if(event->key()==Qt::Key_Left){
        togoX = -STEP; togoY = 0;
        if(!canMove(togoX, togoY)){
            next = new QKeyEvent(*event);
            return;
        }
        goX = -STEP; goY = 0;
        piccopy[0] = pics[0].transformed(QTransform().rotate(180));
        piccopy[1] = pics[1].transformed(QTransform().rotate(180));
        piccopy[2] = pics[2].transformed(QTransform().rotate(180));
        piccopy[3] = pics[3].transformed(QTransform().rotate(180));
    }
    else if(event->key()==Qt::Key_Right){
        togoX = STEP; togoY = 0;
        if(!canMove(togoX, togoY)){
            next = new QKeyEvent(*event);
            return;
        }
        goX = STEP; goY = 0;
        piccopy[0] = pics[0].transformed(QTransform().rotate(0));
        piccopy[1] = pics[1].transformed(QTransform().rotate(0));
        piccopy[2] = pics[2].transformed(QTransform().rotate(0));
        piccopy[3] = pics[3].transformed(QTransform().rotate(0));
    }else return;

    if(myTimer != nullptr) return;
    myTimer = new QTimer(this);
    movie = new QTimer(this);

    myTimer->start(TIME);
    movie->start(FPS);
    connect(myTimer,SIGNAL(timeout()),this,SLOT(callMove()));
    connect(movie,SIGNAL(timeout()),this,SLOT(animation()));
}

void PacMan::move(){
    int newX = character->x()+goX, newY = character->y()+goY;

    if(newX<-20)
        character->move(559, character->y());
    else if(newX>559)
        character->move(1, character->y());
    newX = character->x()+goX;

    if(goX!=togoX && goY!=togoY && canMove(togoX, togoY)){
        myTimer->stop(); movie->stop();
        delete myTimer; delete movie;
        myTimer = nullptr;
        newX = character->x()+togoX;
        newY = character->y()+togoY;
        character->move(newX, newY);
        keyPressEvent(next);
        return;
    }else if(!canMove(goX, goY)){
        myTimer->stop(); movie->stop();
        delete myTimer; delete movie;
        myTimer = nullptr;
        return;
    }

    character->move(newX, newY);
    if(map->getmapval(newX/20, newY/20) != road) eat();
}

void PacMan::callMove(){ move(); }

bool PacMan::canMove(int x, int y){
    int newX = character->x()+x, newY = character->y()+y;

    if(map->getmapval(newX/20, newY/20) == wall ||
       map->getmapval((newX+19)/20, newY/20) == wall ||
       map->getmapval(newX/20, (newY+19)/20) == wall ||
       map->getmapval((newX+19)/20, (newY+19)/20) == wall){
        return false;
    }
    return true;
}

void PacMan::eat(){
    int item = map->getmapval(character->x()/20, character->y()/20);
    map->eaten(character->x()/20, character->y()/20);

    switch (item) {
        case dot:
           //point
        break;
    }
}

void PacMan::animation(){
    num += add;
    character->setPixmap(piccopy[num].scaled(20, 20, Qt::KeepAspectRatio));
    if(num == 3) add=-1;
    else if(num == 0) add=1;
}
