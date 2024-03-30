#ifndef ENEMY_H
#define ENEMY_H
#include <QObject>
#include <QGraphicsItem>
class enemy: public QObject, public QGraphicsPixmapItem
{
public:
    double damage; //Damage done by enemies
    enemy();
    void move();
    void hit();

};

#endif // ENEMY_H
