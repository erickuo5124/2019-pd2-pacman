#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("Pac Man"));
    ui->mainToolBar->hide();
    this->setStyleSheet("background-color: black;");

    setup();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setup(){
    this->setFixedSize(20*28, 20*31+100);
    map = new Map(this);
    pacman = new PacMan(map, this);
    blinky = new Blinky(pacman, map, this);
}
