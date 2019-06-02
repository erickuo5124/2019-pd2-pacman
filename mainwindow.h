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
    QPushButton *resetButton;

private:
    Ui::MainWindow *ui;
    void setup();
    Map *map = nullptr;
    PacMan *pacman = nullptr;
    Ghost *blinky = nullptr, *pinky = nullptr, *inky = nullptr, *clyde = nullptr;//need

private slots:
    void resetClicked();
};

#endif // MAINWINDOW_H
