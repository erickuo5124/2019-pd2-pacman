#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>

namespace Ui {
class MainWindow;
}

class QGraphicsScene;
class QTimer;
class MovableItem;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event);
    void showEvent(QShowEvent *event);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    QList<MovableItem *> itemList;
};

#endif // MAINWINDOW_H
