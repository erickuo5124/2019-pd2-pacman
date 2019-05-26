#include "map.h"
#include <QDebug>

Map::Map(QWidget *parent) :
    QWidget(parent)
{
    wall = new QPixmap(":/resource/img/wall.png");
    dot = new QPixmap(":/resource/img/dot.png");
    pellet = new QPixmap(":/resource/img/dot.png");//need

    for(int i=0; i<W; ++i)
        for(int j=0; j<H; ++j){
            mappic[i][j] = new QLabel(parent);
            mappic[i][j]->setGeometry(20*i, 20*j, 20, 20);
            mappic[i][j]->setAlignment(Qt::AlignCenter);
            if(mapval[i][j] == 1)
                mappic[i][j]->setPixmap(wall->scaled(20, 20, Qt::KeepAspectRatio));
            else if(mapval[i][j] == 2)
                mappic[i][j]->setPixmap(dot->scaled(5, 5, Qt::KeepAspectRatio));
            else if(mapval[i][j] == 3)
                mappic[i][j]->setPixmap(dot->scaled(15, 15, Qt::KeepAspectRatio));
        }

}

Map::~Map(){
}

int Map::getmapval(int row, int col){
    return mapval[row][col];
}

void Map::eaten(int row, int col){
    mapval[row][col] = road;
    delete mappic[row][col];
}
