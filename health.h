#ifndef HEALTH_H
#define HEALTH_H

#include <QObject>
#include <QGraphicsTextItem>
#include "gamesetting.h"

class health : public QGraphicsTextItem
{
    Q_OBJECT
public:
    health(QGraphicsItem *parent = nullptr);

    int get_health()
    {
        return health_value;
    }

    static health& getinstance()
    {
        static health obj;
        return obj;
    }

    void reduce();//健康值减少
    void reset();//重设分数

private:
    int health_value = GameSetting::playerHealth;
};

#endif // HEALTH_H
