#ifndef FENCE_H
#define FENCE_H
#include <QObject>
#include <QGraphicsItem>
class fence: public QObject, public QGraphicsPixmapItem
{
private:
    double health; //health per fence
public:
    fence();
    double getHealth()const;//getter for health
    void Damaged(int amount);// function for applying damage to fence, decreasing health of fence
    bool isDestroyed()const;// boolean function to check if the fence is destroyed or not
};

#endif // FENCE_H
