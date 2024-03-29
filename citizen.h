#ifndef CITIZEN_H
#define CITIZEN_H
#include <QObject>
#include <QGraphicsItem>
class citizen: public QObject, public QGraphicsPixmapItem
{
public:
    double health; //Health of the citizen worker
    double repair_health; //Health given to the object when it is repaired
    citizen();
    void move();
    void repair();

};

#endif // CITIZEN_H
