#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include <QList>
#include <QLabel>
#include <QPixmap>

#define W 28
#define H 31
#define O 1

enum{road, wall, dot};

class Map : public QWidget
{
    Q_OBJECT

public:
    Map(QWidget *parent = nullptr);
    ~Map();
    int getmapval(int, int);
    void eaten(int, int);

private:
    QLabel *mappic[W][H];
    QPixmap *wall, *dot, *pellet;
    int mapval[W][H] = {
        {O,O,O,O,O,O,O,O,O,O,0,0,0,O,0,O,0,0,0,O,O,O,O,O,O,O,O,O,O,O,O},
        {O,2,2,3,2,2,2,2,2,O,0,0,0,O,0,O,0,0,0,O,2,2,2,3,O,O,2,2,2,2,O},
        {O,2,O,O,O,2,O,O,2,O,0,0,0,O,0,O,0,0,0,O,2,O,O,2,O,O,2,O,O,2,O},
        {O,2,O,0,O,2,O,O,2,O,0,0,0,O,0,O,0,0,0,O,2,O,O,2,2,2,2,O,O,2,O},
        {O,2,O,0,O,2,O,O,2,O,0,0,0,O,0,O,0,0,0,O,2,O,O,O,O,O,2,O,O,2,O},
        {O,2,O,O,O,2,O,O,2,O,O,O,O,O,0,O,O,O,O,O,2,O,O,O,O,O,2,O,O,2,O},
        {O,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,O,O,2,O},
        {O,2,O,O,O,2,O,O,O,O,O,O,O,O,0,O,O,O,O,O,2,O,O,2,O,O,O,O,O,2,O},
        {O,2,O,0,O,2,O,O,O,O,O,O,O,O,0,O,O,O,O,O,2,O,O,2,O,O,O,O,O,2,O},
        {O,2,O,0,O,2,2,2,2,O,O,0,0,0,0,0,0,0,0,0,2,O,O,2,2,2,2,O,O,2,O},
        {O,2,O,0,O,2,O,O,2,O,O,0,O,O,O,O,O,0,O,O,2,O,O,2,O,O,2,O,O,2,O},
        {O,2,O,O,O,2,O,O,2,O,O,0,O,0,0,0,O,0,O,O,2,O,O,2,O,O,2,O,O,2,O},
        {O,2,2,2,2,2,O,O,2,0,0,0,O,0,0,0,O,0,O,O,2,2,2,2,O,O,2,2,2,2,O},
        {O,O,O,O,O,2,O,O,O,O,O,0,0,0,0,0,O,0,O,O,O,O,O,0,O,O,O,O,O,2,O},
        {O,O,O,O,O,2,O,O,O,O,O,0,0,0,0,0,O,0,O,O,O,O,O,0,O,O,O,O,O,2,O},
        {O,2,2,2,2,2,O,O,2,0,0,0,O,0,0,0,O,0,O,O,2,2,2,2,O,O,2,2,2,2,O},
        {O,2,O,O,O,2,O,O,2,O,O,0,O,0,0,0,O,0,O,O,2,O,O,2,O,O,2,O,O,2,O},
        {O,2,O,0,O,2,O,O,2,O,O,0,O,O,O,O,O,0,O,O,2,O,O,2,O,O,2,O,O,2,O},
        {O,2,O,0,O,2,2,2,2,O,O,0,0,0,0,0,0,0,0,0,2,O,O,2,2,2,2,O,O,2,O},
        {O,2,O,0,O,2,O,O,O,O,O,O,O,O,0,O,O,O,O,O,2,O,O,2,O,O,O,O,O,2,O},
        {O,2,O,O,O,2,O,O,O,O,O,O,O,O,0,O,O,O,O,O,2,O,O,2,O,O,O,O,O,2,O},
        {O,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,O,O,2,O},
        {O,2,O,O,O,2,O,O,2,O,O,O,O,O,0,O,O,O,O,O,2,O,O,O,O,O,2,O,O,2,O},
        {O,2,O,0,O,2,O,O,2,O,0,0,0,O,0,O,0,0,0,O,2,O,O,O,O,O,2,O,O,2,O},
        {O,2,O,0,O,2,O,O,2,O,0,0,0,O,0,O,0,0,0,O,2,O,O,2,2,2,2,O,O,2,O},
        {O,2,O,O,O,2,O,O,2,O,0,0,0,O,0,O,0,0,0,O,2,O,O,2,O,O,2,O,O,2,O},
        {O,2,2,3,2,2,2,2,2,O,0,0,0,O,0,O,0,0,0,O,2,2,2,3,O,O,2,2,2,2,O},
        {O,O,O,O,O,O,O,O,O,O,0,0,0,O,0,O,0,0,0,O,O,O,O,O,O,O,O,O,O,O,O},
    };
};

#endif // MAP_H
