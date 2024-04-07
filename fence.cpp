#include "fence.h"
#include "enemy.h"
#include <QGraphicsView>
fence::fence() {
    health = 100;
    setPixmap(QPixmap(":/fence.webp").scaled(100,100)); // added constructor for fence, including the health and picture
    setPos(0,300);
}
double fence::getHealth()const{
    return health;
}//getter function for fence health
bool fence::isDestroyed()const{
    if(health==0){
        return true;
    }
    return false;
}// returns true if the fence health is zero, meaning the fence is destroyed
bool fence::Damaged(int amount){
    QList<QGraphicsItem*>colliding_items=collidingItems();
    for (int i = 0 ; i < colliding_items.size() ; i++){
        if(typeid(*(colliding_items[i]))==typeid(enemy)){
                health-=amount;
        }
        return true;
    }
    if(isDestroyed()){
        scene()->removeItem(this);
        delete this;
    }// function for applying damage to fence, decreasing health of fence with every damage
}

