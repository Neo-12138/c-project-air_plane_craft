#include <QGraphicsScene>
#include <QGraphicsView>
#include <QApplication>
#include <QIcon>

#include "gamesetting.h"
#include "player.h"
#include "score.h"
#include "health.h"
#include <QtMultimedia>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationDisplayName("飞机大战");//设置app名字
    QApplication::setWindowIcon(QIcon(":/image/res/hero.png"));//设置app图标

    // 创建player
    player *user = new player;

    //创建场景
    QGraphicsScene *scene = new QGraphicsScene;
    scene->addItem(user);//添加飞机对象
    scene->setSceneRect(0,0,GameSetting::sceneWidth,GameSetting::sceneHight);//设置背景图片其实位置和大小
    scene->setBackgroundBrush(QImage(":/image/res/img_bg_level_1.jpg"));//设置路径

    //创建分数文字item
    scene->addItem(&score::getinstance());

    //创建健康值文字item
    scene->addItem(&health::getinstance());

    scene->setStickyFocus(true);//设置焦点一直在飞机上

    //创建摄像机
    QGraphicsView view(scene);
    view.setFixedSize(GameSetting::sceneWidth,GameSetting::sceneHight);//设置app界面大小不能更改
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//关闭上下滚轮
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//关闭左右滚轮
    view.show();

    //添加bgm
    QMediaPlayer bgMusic;
    bgMusic.setMedia(QUrl("qrc:/sound/res/bg.wav"));
    bgMusic.setVolume(5);  //音量
    bgMusic.play();


    return a.exec();
}
