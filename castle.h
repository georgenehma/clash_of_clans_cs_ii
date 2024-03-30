#ifndef CASTLE_H
#define CASTLE_H
#include <QObject>
#include <QGraphicsItem>

class castle: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    castle();
    double health;
};

#endif // CASTLE_H
