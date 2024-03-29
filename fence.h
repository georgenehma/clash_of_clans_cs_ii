#ifndef FENCE_H
#define FENCE_H
#include <QObject>
#include <QGraphicsItem>
class fence: public QObject, public QGraphicsPixmapItem
{
public:
    double health; //health per fence
    fence();
};

#endif // FENCE_H
