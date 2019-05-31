#include "map.h"
#include <QDebug>

Map::Map(QWidget *parent) :
    QWidget(parent),
    point(0)
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

    dashboard = new QLabel(parent);
    dashboard->setGeometry(180, 620, 200, 100);
    dashboard->setAlignment(Qt::AlignCenter);
    dashboard->setText(QString::number(point));
    dashboard->setStyleSheet("QLabel { font-size: 20px; color : white; }");
}

Map::~Map(){
}

int Map::getmapval(int row, int col){
    return mapval[row][col];
}

void Map::eaten(int row, int col){
    int item = getmapval(row, col);

    switch (item) {
        case Dot:
        point += 100;
        dashboard->setText(QString::number(point));
        break;

    }

    mapval[row][col] = road;
    delete mappic[row][col];
}
