#include "moveableitem.h"
#include <QDebug>

MoveableItem::MoveableItem(Map *map,QWidget *parent) :
    QWidget (parent),
    map(map)
{

}

bool MoveableItem::canMove(int x, int y){
    int newX = character->x()+x, newY = character->y()+y;

    if(map->getmapval(newX/20, newY/20) == wall ||
       map->getmapval((newX+19)/20, newY/20) == wall ||
       map->getmapval(newX/20, (newY+19)/20) == wall ||
       map->getmapval((newX+19)/20, (newY+19)/20) == wall){
        return false;
    }
    return true;
}


