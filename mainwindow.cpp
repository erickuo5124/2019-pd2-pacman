#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("Pac Man"));
    ui->mainToolBar->hide();
    this->setStyleSheet("background-color: black;");
    this->setFixedSize(20*28, 20*31+100);

    setup();

    resetButton = new QPushButton(this);
    resetButton->setGeometry(360, 640, 50, 50);
    resetButton->setText("reset");
    resetButton->setStyleSheet("QPushButton { background-color: white; font-size: 20px; }");
    connect(resetButton, SIGNAL(clicked(bool)), this, SLOT(resetClicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setup(){
    map = new Map(this);
    pacman = new PacMan(map, this);
    blinky = new Blinky(pacman, map, this);
    pinky = new Pinky(pacman, map, this);
    inky = new Inky(pacman, map, this);
    clyde = new Clyde(pacman, map, this);
}

void MainWindow::resetClicked(){
    qDebug()<< "reset" << endl;
    blinky->reset();
    pinky->reset();
    inky->reset();
    clyde->reset();
    map->reset();
    pacman->reset();
    pacman->setFocus();
}
