#include "health.h"
#include <QFont>
#include "gamesetting.h"



health::health(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    reset();
}



void health::reset()
{
    health_value = GameSetting::playerHealth;

    setPlainText("健康值："+QString::number(health_value));
    setDefaultTextColor(Qt::green);
    setFont(QFont("楷书",GameSetting::font_size,QFont::Bold));//"courier New"
}

void health::reduce()
{
    --health_value;
    setPlainText("健康值："+QString::number(health_value));
}
