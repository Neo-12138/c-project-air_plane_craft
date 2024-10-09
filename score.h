#ifndef SCORE_H
#define SCORE_H

#include <QObject>
#include <QGraphicsTextItem>


class score : public QGraphicsTextItem
{
    Q_OBJECT
public:
    score(QGraphicsItem *parent = nullptr);
    static score& getinstance()
    {
        static score obj;
        return obj;
    }

    void increase();//增加分数
    void reset();//重设分数

private:


    int my_score = 0;
};

#endif // SCORE_H
