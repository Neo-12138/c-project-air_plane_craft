#include "player.h"
#include <QPixmap>
#include <QDebug>
#include <QKeyEvent>
#include <QFont>
#include "enemy.h"
#include "bullet.h"
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "health.h"
#include "score.h"
#include <QFontMetrics>//计算文字的长度和宽度



player::player(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    bulletSound.setSource(QUrl("qrc:/sound/res/bomb.wav"));
    bulletSound.setVolume(1);  //音量
    setPixmap(QPixmap(":/image/res/heroplane.png"));
    setScale(playerScale);
    setPos(sceneWidth/2-boundingRect().width()*playerScale/2,
           sceneHight-boundingRect().height()*playerScale);
    setFlag(QGraphicsItem::ItemIsFocusable);//聚焦
    setFocus();

    startTimer(1000);
}

void player::keyPressEvent(QKeyEvent *event)//按压事件
{
    switch (event->key())
    {
    case Qt::Key_Left:
        if (pos().x() > 0) // 防止超出左边界
            setPos(x() - playerMoveSpeed, y());
        break;
    case Qt::Key_Right:
        if (pos().x() + boundingRect().width() * playerScale < sceneWidth) // 防止超出右边界
            setPos(x() + playerMoveSpeed, y());
        break;
    case Qt::Key_Up:
        if (pos().y() > 0) // 防止超出上边界
            setPos(x(), y() - playerMoveSpeed);
        break;
    case Qt::Key_Down:
        if (pos().y() + boundingRect().height() * playerScale < sceneHight) // 防止超出下边界
            setPos(x(), y() + playerMoveSpeed);
        break;

    //A D W S 上下左右
    case Qt::Key_A:
        if (pos().x() > 0) // 防止超出左边界
            setPos(x() - playerMoveSpeed, y());
        break;
    case Qt::Key_D:
        if (pos().x() + boundingRect().width() * playerScale < sceneWidth) // 防止超出右边界
            setPos(x() + playerMoveSpeed, y());
        break;
    case Qt::Key_W:
        if (pos().y() > 0) // 防止超出上边界
            setPos(x(), y() - playerMoveSpeed);
        break;
    case Qt::Key_S:
        if (pos().y() + boundingRect().height() * playerScale < sceneHight) // 防止超出下边界
            setPos(x(), y() + playerMoveSpeed);
        break;

    case Qt::Key_R: //重新开始
        if(playing)
        {
            return;
        }

        playing = true;
        health::getinstance().reset();
        score::getinstance().reset();
        massageItem->hide();

        setScale(playerScale);
        setPos(sceneWidth/2-boundingRect().width()*playerScale/2,
               sceneHight-boundingRect().height()*playerScale);
        break;

    case Qt::Key_Space:   //按空格生成子弹
        qDebug()<<"生成了子弹";
        bullet *player_bullet = new bullet;

        int tmp = x() + boundingRect().height() * playerScale/4;//往右偏移半个飞机
        //tmp -= player_bullet->boundingRect().height() * bulletScale/2;//往左偏移半个子弹
        player_bullet->setPos(tmp, y());
        scene()->addItem(player_bullet);
        //播放音效

        bulletSound.play();
        break;
    }
}

//鼠标移动
//void player::mouthMoveEvent(QGraphicsSceneMouseEvent *event)
//{

//}

//鼠标按压
//void player::mouthPressEvent(QGraphicsSceneMouseEvent *event)
//{

//}

void player::enemySpawn()//创建敌机对象
{
    qDebug()<<"生成了敌机";
    enemy *enemyplane = new enemy;
    scene()->addItem(enemyplane);


}

void player::gameOver()
{
    playing = false;
    for(auto item : scene()->items())
    {
        if(typeid (*item) == typeid (enemy))
        {
            scene()->removeItem(item);
            delete item;
        }
    }

    if(massageItem == nullptr)
    {
        massageItem = new QGraphicsTextItem;
        scene()->addItem(massageItem);
        QString massage = "Game Over! 按R键重新开始";
        massageItem->setPlainText(massage);
        massageItem->setDefaultTextColor(Qt::red);

        //设置字体
        QFont font = QFont("楷书", GameSetting::font_size*1.5, QFont::Bold);//"courier New"
        massageItem->setFont(font);

        //计算一段文字的长宽
        QFontMetrics fm(font);
        int masgwidth = fm.horizontalAdvance(massage);

        massageItem->setPos(sceneWidth/2 - masgwidth/2,sceneHight/2);
    }
    else
    {
        massageItem->show();
    }
}

void player::timerEvent(QTimerEvent *event)
{
    if (playing)
    {
        enemySpawn();
    }

    if (health::getinstance().get_health() <= 0)
    {
        gameOver();
    }
}
