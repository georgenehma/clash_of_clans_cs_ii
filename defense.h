#ifndef DEFENSE_H
#define DEFENSE_H
#include <QObject>
#include <QGraphicsPixmapItem>

class defense: public QObject, public QGraphicsPixmapItem
{
public:
    double damage;
    defense();
    void shoot();

};

#endif // DEFENSE_H
