#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QDebug>

class enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    enemy(QGraphicsItem *parent = nullptr);

    ~enemy()
    {
        qDebug()<<"enemy析构";
    }

    // QObject interface
protected:
    void timerEvent(QTimerEvent *event);
};

#endif // ENEMY_H
