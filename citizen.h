#ifndef CITIZEN_H
#define CITIZEN_H
#include <QObject>
#include <QGraphicsItem>
#include "enemy.h"
#include "fence.h"
class citizen: public QObject, public QGraphicsPixmapItem
{
private:
    double health; //Health of the citizen worker
    double repair_health; //Health given to the object when it is repaired
    fence* f;
public:
    citizen();
    double getHealth(); //getter function for health
    double getRepairHealth();//getter function for repairHelath
    void move_horizontal();//moving citizens horizontally
    void move_vertical();//vertically
    void damaged();// a function that removes citizens if they collide with enemy
    void repair();// a function that repairs fences and other structure when they collide with them

};

#endif // CITIZEN_H
