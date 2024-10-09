#include "bullet.h"
#include <QPixmap>
#include "gamesetting.h"
#include <QGraphicsScene>
#include <QDebug>


using namespace GameSetting;


bullet::bullet(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/image/res/hero_bullet_7.png"));
    setScale(bulletScale);//设置图片比例

    startTimer(bulletTimer);
}

void bullet::timerEvent(QTimerEvent *event)
{
    setPos(x(),y()-bulletSpeed);
    if (y()+boundingRect().height()<0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
