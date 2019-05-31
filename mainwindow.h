#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pacman.h"
#include "ghost.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void setup();
    Map *map;
    PacMan *pacman;
    Blinky *blinky;
    MoveableItem *pacmann, *ghostt;//need
};

#endif // MAINWINDOW_H
