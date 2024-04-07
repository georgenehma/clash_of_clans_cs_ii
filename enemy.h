#ifndef ENEMY_H
#define ENEMY_H
#include <QObject>
#include <QGraphicsItem>
#include "castle.h"
class enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    double damage=100; //Damage done by enemies
    double heath;
    int castle_x=300; //Castle's x position
    int castle_y=300; //Castle's y position
    enemy(castle*& cast);
    castle* cast;
public slots:
    void move_horizontal();
    void move_vertical();
    void hit();

};

#endif // ENEMY_H

