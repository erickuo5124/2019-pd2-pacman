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
    QLabel *label = new QLabel();
    QPixmap pixmap(":/resource/img/wall.png");
    label->setGeometry(100, 100, 30, 30);
    label->setText("awe");
    label->setPixmap(pixmap);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setup(){
    this->setFixedSize(20*28, 20*31);
    map = new Map(this);
    pacman = new PacMan(map, this);
}
