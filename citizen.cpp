#include "citizen.h"
#include <QTimer>
#include <QList>
#include <QGraphicsView>
#include "enemy.h"
#include "fence.h"
citizen::citizen() {
    setPixmap(QPixmap("").scaled(100,100));
    health = 100;
    repair_health=100;
    f = new fence();
}//constructor
double citizen::getHealth(){
    return health;
}//getter function for health
double citizen::getRepairHealth(){
    return repair_health;
}//getter function for repairHelath
void citizen::move_horizontal(){
    if(x()<=600){
            setPos(x()+100,y());
    }
}//moving citizens horizontally
void citizen::move_vertical(){
    if(y()<=600){
        setPos(x(),y()-100);
    }
}//vertically
void citizen::damaged(){
    QList<QGraphicsItem*>colliding_items=collidingItems();
    for (int i = 0 ; i < colliding_items.size() ; i++){
        if(typeid(*(colliding_items[i]))==typeid(enemy)){
         scene()->removeItem(this);
        delete this;
}
    }
}// a function that removes citizens if they collide with enemy

void citizen::repair(){
    int amountDamaged = 20;
    if(f->Damaged(amountDamaged)){
        //fence position
        int fenceX = f->x();
        int fenceY=f->y();
        // distance between fence and citizen
        int distanceX = fenceX - x();
        int distanceY=fenceY - y();

    }

}//a function that moves the citizen towards the fence when it is damaged and initiates the repairing action when it collides
