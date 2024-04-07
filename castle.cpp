#include "castle.h"
#include <QGraphicsScene>
#include <QMessageBox>
castle::castle() {
    setPixmap(QPixmap(":/castle.jpeg").scaled(100,100));
}
void castle::reduce_health(int damage){
    health-=damage;
    if (health<=0){
        this->~castle();
    }
}

castle::~castle(){
    scene()->removeItem(this);
    QMessageBox* msg=new QMessageBox;
    msg->setText(QString("Game over!"));
    msg->show();
}
