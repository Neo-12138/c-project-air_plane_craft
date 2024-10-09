#include "score.h"
#include <QFont>
#include "gamesetting.h"



score::score(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    reset();
}

void score::reset()
{
    my_score = 0;
    setPlainText("分  数："+QString::number(my_score));
    setDefaultTextColor(Qt::green);
    setFont(QFont("楷书", GameSetting::font_size, QFont::Bold));//"courier New"
    setPos(x(),GameSetting::font_size * 2);
}

void score::increase()
{
    ++my_score;
    setPlainText("分  数："+QString::number(my_score));
}
