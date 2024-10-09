#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>

class bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bullet(QGraphicsItem *parent = nullptr);

    // QObject interface
protected:
    void timerEvent(QTimerEvent *event);
};

#endif // BULLET_H
