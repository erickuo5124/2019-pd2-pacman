#ifndef MOVEABLEITEM_H
#define MOVEABLEITEM_H

#include <QWidget>
#include <QLabel>
#include <QMovie>
#include <QList>

class MoveableItem : public QWidget
{
    Q_OBJECT

public:
    MoveableItem(QWidget *parent = nullptr);
    virtual void move() = 0;

protected:
    QPixmap picture;
    QList<QPixmap> pics;
    QLabel *character;
};

#endif // MOVEABLEITEM_H
