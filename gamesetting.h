#ifndef GAMESETTING_H
#define GAMESETTING_H


namespace GameSetting
{
const int sceneWidth = 512;//app的宽度
const int sceneHight = 768;//app的高度
const int font_size = 16;//字体大小

const float playerScale = 1;//玩家飞机的大小可调的倍数
const int playerMoveSpeed = 10;//玩家飞机移动的速度
const int playerHealth = 2;//玩家飞机的血量

const float enemyScale = 1;//敌机的大小可调的倍数
const int enemyTimer = 50;//定时器的间隔
const int enemySpeed = 5;//敌机的下落速度


const float bulletScale = 1;//子弹的可调倍数大小
const int bulletTimer = 50;//定时器的间隔
const int bulletSpeed = 10;//子弹上升速度
}





#endif // GAMESETTING_H
