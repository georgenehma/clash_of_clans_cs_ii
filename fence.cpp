#include "fence.h"

fence::fence() {
    health = 100;
    setPixmap(QPixmap(":/fence.webp").scaled(100,100)); // added constructor for fence, including the health and picture
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
void fence::Damaged(int amount){
    health-=amount;
    if(isDestroyed()){
        delete this;
    }// function for applying damage to fence, decreasing health of fence with every damage
}

