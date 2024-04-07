#ifndef CASTLE_H
#define CASTLE_H
#include <QObject>
#include <QGraphicsItem>

class castle: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    castle();
    double health=100; //Change later !!
    int get_x(); //Get y position
    int get_y(); //Get x position
    void reduce_health(int damage);
    ~castle();

};

#endif // CASTLE_H

