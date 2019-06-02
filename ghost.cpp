#include "ghost.h"
#include <QDebug>

#define TIME 15
#define STEP 1
#define TURN_RIGHT togoX=STEP;togoY=0;
#define TURN_LEFT togoX=-STEP;togoY=0;
#define TURN_UP togoX=0;togoY=-STEP;
#define TURN_DOWN togoX=0;togoY=STEP;

Ghost::Ghost( PacMan *pacman, Map *map, QWidget *parent) :
    MoveableItem(map, parent), pacman(pacman)
{
    pics.push_back(QPixmap(":/resource/img/scared.png"));

    character = new QLabel(parent);

     walkTimer = new QTimer(this);
     //movieTimer = new QTimer(this);
     scaredTimer = new QTimer(this);

     TURN_LEFT
     goX = -STEP; goY = 0;

     connect(map, SIGNAL(eat()), this, SLOT(scared()));
     connect(map, SIGNAL(stop()), this, SLOT(freeze()));
     connect(scaredTimer,SIGNAL(timeout()),this,SLOT(count()));
     connect(walkTimer,SIGNAL(timeout()),this,SLOT(callMove()));
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

    return (way>2);
}

int Ghost::getDistance(int x=0, int y=0){
    return (character->x()+x-targetX)*(character->x()+x-targetX)
         +(character->y()+y-targetY)*(character->y()+y-targetY);
}

void Ghost::detectCollide(){
    int x = character->x()-pacman->getX();
    int y = character->y()-pacman->getY();
    if((x*x + y*y) < 9){
        if(isScared){
            map->point+=500;
            reset();
        }else {
            emit map->stop();
        }
    }
}

void Ghost::scared(){
    character->setPixmap(pics[0].scaled(20, 20, Qt::KeepAspectRatio));
    isScared = true;
    scaredTimer->start(10);
    counter = 0;
}

void Ghost::count(){
    if(counter > 1000){
        isScared = false;
        character->setPixmap(pics[1].scaled(20, 20, Qt::KeepAspectRatio));
        scaredTimer->stop();
    }else
        counter++;
}

void Ghost::freeze(){
        walkTimer->stop();
        //movieTimer->stop();
}
/***************Blinky***************/
Blinky::Blinky( PacMan *pacman, Map *map, QWidget *parent) :
    Ghost(pacman, map, parent)
{
    pics.push_back(QPixmap(":/resource/img/blinky.png"));
    reset();
}

void Blinky::reset(){
    isScared = false;
    timer = 0;
    picture = pics[1];

    character->setGeometry(270, 220, 20, 20);
    character->setPixmap(picture.scaled(20, 20, Qt::KeepAspectRatio));

    walkTimer->start(TIME);
}

void Blinky::callMove(){
    detectCollide();
    timer++;
    if(timer<100)return;
    else if((timer/70)%30<10){//scatter mode
        targetX = 540;
        targetY = 20;
    }else {//chasing mode
        targetX = pacman->getX();
        targetY = pacman->getY();
    }
    move();
}

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
                distance2 = getDistance(togoX, togoY);
                if(distance1>distance2){
                    distance1 = distance2;
                    maxX = togoX; maxY = togoY;
                }
            }
        }
        TURN_DOWN
        if(canMove(togoX, togoY)){
            if(togoX!=-goX || togoY!=-goY){
                distance2 = getDistance(togoX, togoY);
                if(distance1>distance2){
                    distance1 = distance2;
                    maxX = togoX; maxY = togoY;
                }
            }
        }
        TURN_LEFT
        if(canMove(togoX, togoY)){
            if(togoX!=-goX || togoY!=-goY){
                distance2 = getDistance(togoX, togoY);
                if(distance1>distance2){
                    distance1 = distance2;
                    maxX = togoX; maxY = togoY;
                }
            }
        }
        TURN_RIGHT
        if(canMove(togoX, togoY)){
            if(togoX!=-goX || togoY!=-goY){
                distance2 = getDistance(togoX, togoY);
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

/***************Pinky***************/
Pinky::Pinky( PacMan *pacman, Map *map, QWidget *parent) :
    Ghost(pacman, map, parent)
{
    pics.push_back(QPixmap(":/resource/img/pinky.png"));
    reset();
}

void Pinky::reset(){
    isScared = false;
    timer = 0;
    picture = pics[1];

    character->setGeometry(270, 280, 20, 20);
    character->setPixmap(picture.scaled(20, 20, Qt::KeepAspectRatio));

    walkTimer->start(TIME);
}

void Pinky::callMove(){
    detectCollide();
    if(timer<350){
        if(timer==349)
            character->move(270, 220);
        timer++;
        return;
    }
    move();
}

void Pinky::move(){
    if(character->x()+goX<-20)
        character->move(559, character->y());
    else if(character->x()+goX>559)
        character->move(1, character->y());

    if(isIntersection()){
        do{
            int ran = rand()%4;
            switch (ran) {
                case 0:
                    TURN_UP
                break;
                case 1:
                    TURN_DOWN
                break;
                case 2:
                    TURN_LEFT
                break;
                case 3:
                    TURN_RIGHT
                break;
            }
            if(togoX==-goX && togoY==-goY) continue;
            else if(canMove(togoX, togoY))break;
        }while(1);
        goX=togoX; goY=togoY;
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

/***************Inky***************/
Inky::Inky( PacMan *pacman, Map *map, QWidget *parent) :
    Ghost(pacman, map, parent)
{
    pics.push_back(QPixmap(":/resource/img/inky.png"));
    reset();
}

void Inky::reset(){
    isScared = false;
    timer = 0;
    picture = pics[1];

    character->setGeometry(240, 280, 20, 20);
    character->setPixmap(picture.scaled(20, 20, Qt::KeepAspectRatio));

    walkTimer->start(TIME);
}

void Inky::callMove(){
    detectCollide();
    if(timer<800){
        if(timer==799)
            character->move(270, 220);
        timer++;
        return;
    }
    move();
    timer++;
}

void Inky::move(){
    if(character->x()+goX<-20)
        character->move(559, character->y());
    else if(character->x()+goX>559)
        character->move(1, character->y());

    while(!canMove(goX, goY)){
        TURN_LEFT
        if(canMove(togoX, togoY) && togoX!=goX && togoY!=goY) {
            goX = togoX; goY = togoY; break;
        }
        TURN_DOWN
        if(canMove(togoX, togoY) && togoX!=goX && togoY!=goY) {
            goX = togoX; goY = togoY; break;
        }
        TURN_UP
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

/***************Clyde***************/
Clyde::Clyde( PacMan *pacman, Map *map, QWidget *parent) :
    Ghost(pacman, map, parent)
{
    pics.push_back(QPixmap(":/resource/img/clyde.png"));
    reset();
}

void Clyde::reset(){
    isScared = false;
    timer = 0;
    picture = pics[1];

    character->setGeometry(300, 280, 20, 20);
    character->setPixmap(picture.scaled(20, 20, Qt::KeepAspectRatio));

    walkTimer->start(TIME);
}

void Clyde::callMove(){
    detectCollide();
    if(timer<1300){
        if(timer==1299)
            character->move(270, 220);
        timer++;
        return;
    }
    move();
    timer++;
}

void Clyde::move(){
    if(character->x()+goX<-20)
        character->move(559, character->y());
    else if(character->x()+goX>559)
        character->move(1, character->y());

    while(!canMove(goX, goY)){
        TURN_RIGHT
        if(canMove(togoX, togoY) && togoX!=goX && togoY!=goY) {
            goX = togoX; goY = togoY; break;
        }
        TURN_LEFT
        if(canMove(togoX, togoY) && togoX!=goX && togoY!=goY) {
            goX = togoX; goY = togoY; break;
        }
        TURN_DOWN
        if(canMove(togoX, togoY) && togoX!=goX && togoY!=goY) {
            goX = togoX; goY = togoY; break;
        }
        TURN_UP
        if(canMove(togoX, togoY) && togoX!=goX && togoY!=goY) {
            goX = togoX; goY = togoY; break;
        }
    }

    character->move(character->x()+goX, character->y()+goY);
}
