#include "pacman.h"
#include <QDebug>
#include <QtGlobal>

#define STEP 1
#define TIME 10
#define FPS 60

PacMan::PacMan( Map *map, QWidget *parent) :
    MoveableItem(map ,parent)
{
    pics.push_back(QPixmap(":/resource/img/pacman1.png"));
    pics.push_back(QPixmap(":/resource/img/pacman2.png"));
    pics.push_back(QPixmap(":/resource/img/pacman3.png"));
    pics.push_back(QPixmap(":/resource/img/pacman4.png"));

    picture = pics[2];

    character = new QLabel(parent);
    reset();
}

void PacMan::reset(){
    if(walkTimer != nullptr){
        walkTimer->stop();
        delete walkTimer;
        walkTimer = nullptr;
    }
    if(movieTimer != nullptr){
        movieTimer->stop();
        delete movieTimer;
        movieTimer = nullptr;
    }
    stop = false;
    character->setGeometry(270, 460, 20, 20);
    character->setPixmap(picture.scaled(20, 20, Qt::KeepAspectRatio));
    this->setFocus();
    connect(map, SIGNAL(stop()), this, SLOT(freeze()));
}

void PacMan::keyPressEvent(QKeyEvent *event){
    if(stop) return;
    qDebug()<<event<<endl;
    if(event->key()==Qt::Key_Up){
        togoX = 0; togoY = -STEP;
        if(!MoveableItem::canMove(togoX, togoY)){
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
        if(!MoveableItem::canMove(togoX, togoY)){
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
        if(!MoveableItem::canMove(togoX, togoY)){
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
        if(!MoveableItem::canMove(togoX, togoY)){
            next = new QKeyEvent(*event);
            return;
        }
        goX = STEP; goY = 0;
        piccopy[0] = pics[0].transformed(QTransform().rotate(0));
        piccopy[1] = pics[1].transformed(QTransform().rotate(0));
        piccopy[2] = pics[2].transformed(QTransform().rotate(0));
        piccopy[3] = pics[3].transformed(QTransform().rotate(0));
    }else return;

    if(walkTimer != nullptr) return;
    walkTimer = new QTimer(this);
    movieTimer = new QTimer(this);

    walkTimer->start(TIME);
    movieTimer->start(FPS);
    connect(walkTimer,SIGNAL(timeout()),this,SLOT(callMove()));
    connect(movieTimer,SIGNAL(timeout()),this,SLOT(animation()));
}

void PacMan::move(){
    int newX = character->x()+goX, newY = character->y()+goY;

    //transport
    if(newX<-20)
        character->move(559, character->y());
    else if(newX>559)
        character->move(1, character->y());
    newX = character->x()+goX;

    if(goX!=togoX && goY!=togoY && MoveableItem::canMove(togoX, togoY)){
        walkTimer->stop(); movieTimer->stop();
        delete walkTimer; delete movieTimer;
        walkTimer = nullptr; movieTimer = nullptr;
        newX = character->x()+togoX;
        newY = character->y()+togoY;
        character->move(newX, newY);
        keyPressEvent(next);
        return;
    }else if(!MoveableItem::canMove(goX, goY)){
        walkTimer->stop(); movieTimer->stop();
        delete walkTimer; delete movieTimer;
        walkTimer = nullptr; movieTimer = nullptr;
        return;
    }

    character->move(newX, newY);

    int x = (character->x()+10)/20;
    int y = (character->y()+10)/20;
    if(x<0 || x>=W ) return;
    if(map->getmapval(x, y) != road) map->eaten(x, y);
}

void PacMan::animation(){
    num += add;
    character->setPixmap(piccopy[num].scaled(20, 20, Qt::KeepAspectRatio));
    if(num == 3) add=-1;
    else if(num == 0) add=1;
}

void PacMan::callMove(){ move(); }
int PacMan::getX(){ return character->x(); }
int PacMan::getY(){ return character->y(); }

void PacMan::freeze(){
    if(walkTimer != nullptr)
        walkTimer->stop();
    if(movieTimer != nullptr)
        movieTimer->stop();
    stop = true;
}
