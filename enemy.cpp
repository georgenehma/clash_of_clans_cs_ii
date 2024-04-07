#include "enemy.h"
#include <QTimer>
#include <QList>
#include <QGraphicsItem>
#include<QGraphicsScene>
#include <iostream>
using namespace std;

enemy::enemy(castle*& cast): QObject(), QGraphicsPixmapItem(), cast(cast) {
    setPixmap(QPixmap(":/enemy.jpeg").scaled(100,100));
    setPos(0,500);
    castle_x=this->cast->x();
    castle_y=this->cast->y();
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(hit()));
    connect(timer, SIGNAL(timeout()),this,SLOT(move_horizontal()));
    connect(timer, SIGNAL(timeout()),this,SLOT (move_vertical()));

    timer->start(4000);


}
void enemy::move_horizontal(){
    if(x()!= castle_x){
        setPos(x()+100,y());
    }
}
void enemy::move_vertical(){
    if(y() != castle_y){
        setPos(x(),y()-100);
    }
}
void enemy::hit(){
    QList<QGraphicsItem*>colliding_items=collidingItems();
    for (int i = 0 ; i < colliding_items.size() ; i++){
        if (typeid(*(colliding_items[i]))==typeid(castle)){
            while(cast->health>0){
                cast->reduce_health(damage);
            }
        }
        else{
            scene()->removeItem(colliding_items[i]);
        }
    }


}
