#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "circlepathitem.h"
#include "squarepathitem.h"
#include <QGraphicsEllipseItem>
#include <QKeyEvent>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(this)),
    timer(new QTimer(this))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);

    itemList = { new CirclePathItem({200, 300}, 100), new SquarePathItem({600, 300}, 100) };

    // Keyword: range-based for-loop
    for (const auto &i : itemList) {
        // Use function pointer of parent class to connect signal & slot.
        connect(timer, &QTimer::timeout, i, &MovableItem::move);
        scene->addItem(i);
    }

    timer->setInterval(20);

    // If there are overloaded signal or slots,
    // you will need to select one of them.
    // QOverload is a helper to do this action.
    // Check "https://stackoverflow.com/questions/16794695/" for more detail.
    connect(ui->pushButton, &QPushButton::pressed, timer, QOverload<>::of(&QTimer::start));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Escape:
        this->close();
        break;
    default:
        break;
    }
}

void MainWindow::showEvent(QShowEvent *event)
{
    scene->setSceneRect(ui->graphicsView->rect());
    QMainWindow::showEvent(event);
}
