#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "gamesetting.h"
#include <QSoundEffect>


class QGraphicsTextItem; //前置声明

using namespace GameSetting;

class player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    player(QGraphicsItem *parent = nullptr);

protected:
    virtual void keyPressEvent(QKeyEvent *event);//重写基类按压函数

//    virtual void mouthMoveEvent(QGraphicsSceneMouseEvent *event);//重写基类鼠标函数
//    virtual void mouthPressEvent(QGraphicsSceneMouseEvent *event);//重写基类鼠标函数

private:
    void enemySpawn();
    void gameOver();


    // QObject interface
protected:
    virtual void timerEvent(QTimerEvent *event);

private:
    bool playing = true;

    QSoundEffect bulletSound; //声音对象

    QGraphicsTextItem *massageItem = nullptr; //文本对象
};

#endif // PLAYER_H
