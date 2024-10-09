#include "enemy.h"
#include <QPixmap>
#include "gamesetting.h"
#include <QRandomGenerator>
#include <QGraphicsScene>
#include "player.h"
#include "bullet.h"
#include "score.h"
#include "health.h"
#include "unistd.h"
#include <QTimer>



using namespace GameSetting;

enemy::enemy(QGraphicsItem *parent):QGraphicsPixmapItem (parent)
{
    setPixmap(QPixmap(":/image/res/enemy.png"));

    setScale(enemyScale);//设置图片比例

    int max = sceneWidth-boundingRect().width()*playerScale;
    int randomNuber = QRandomGenerator::global()->bounded(1,max);//随机值
    setPos(randomNuber, 0);//设置敌机坐标

    startTimer(enemyTimer);
}

void enemy::timerEvent(QTimerEvent *event)
{
    //碰撞检测
    QList<QGraphicsItem *> item_list = collidingItems();
    for(auto item: item_list)
    {
        //敌机撞到玩家
        if (typeid (*item) == typeid (player))
        {
            //健康值减1
            health::getinstance().reduce();

            scene()->removeItem(this);
            delete this;
            return;
        }
        //敌机撞到玩家的子弹
        if (typeid (*item) == typeid (bullet))
        {
            //需要加分
            score::getinstance().increase();

            scene()->removeItem(item);
            scene()->removeItem(this);

            delete item;
            delete this;
            return;
        }
    }

    setPos(x(), y()+enemySpeed);
    if(y()>sceneHight)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }




}
