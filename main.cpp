#include <QApplication>
#include <QFile>
#include <vector>
#include<QTextStream>
#include <QTextStream>
#include <QFile>
#include <QString>
#include <QGraphicsView>
#include "castle.h"
#include "citizen.h"
#include "enemy.h"
#include "fence.h"
#include "defense.h"
#include <iostream>
#include <QUrl>
using namespace std;

using namespace std;
void read_file(vector<vector<int>>& data, int rows, int columns);
//Precondition: Receives a 2D vector and the dimensions one wishes to set it to
//Postcondition: If the file is successfully read it returns true, otherwise it returns false

void instantiate_items(vector<vector<int>> data, vector<defense*>& defense, vector<castle*>& castles, vector<fence*>& fences);
//Precondition: Receives a 2d vector containing 0 for empty land, 1 for clan castle, 2 for defense unit, 3 for fence. It also receives three vectors of pointers towards these different objects
//Postcondition: instantiates these items by calling their respective constructors and fills


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsView * view= new QGraphicsView; //Creates a view
    view->setFixedSize(600,600); //Sets size of the view
    QGraphicsScene* scene = new QGraphicsScene; //Creates a scene
    scene->setSceneRect(0,0,600,600); //Sets dimensions of the scene from a starting point (i.e. 0,0 the origin which is the top left corner)
    view->setScene(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);  //Turns off horizontal scroll bar
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //Turns off vertical scroll bar
    view->show();


    //vector<vector<int>> data;
    // const QString filename = QCoreApplication::applicationDirPath() + "/text.txt";
    //QFile file(":/text.txt");
    //QTextStream in(&file);
    //QString something;
    //in>>something;


    //read_file(data, 6, 6);
    vector<int> first(6,0);
    vector<vector<int>> data(6,first);
    data={{2,2,2,0,2,3}, {2,2,2,0,2,3}, {2,2,2,0,2,3}, {2,2,2,1,2,3}, {2,2,2,0,2,3}, {2,2,2,0,2,3}};


    //for (int i = 0; i < data.size(); i++)  //Source: https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/
    //{
    //for (int j = 0; j < data[i].size(); j++)
    //{
    //data[i][j]=(i)%3+1;


    //}
    //}
    vector<defense*> defenses;
    vector<castle*> castles;
    vector<fence*> fences;
    instantiate_items(data, defenses, castles, fences);
    vector<QGraphicsPixmapItem*> all_items; //This vector contains all items in game
    all_items.insert(all_items.end(), castles.begin(), castles.end());
    all_items.insert(all_items.end(), fences.begin(), fences.end());
    all_items.insert(all_items.end(), defenses.begin(), defenses.end());
    for (size_t i = 0 ; i < all_items.size() ; i++){ //Adding all items to the scene
        scene->addItem(all_items[i]);
    }
    enemy enem(castles[0]);
    scene->addItem(&enem);
    return a.exec();





}

void read_file(vector<vector<int>>& data, int rows, int columns){
    vector<int> first_dimension(rows,0);
    vector<vector<int>> second_dimension(columns,first_dimension);
    data=second_dimension; //Data becomes a vector containing all 0s with the specified dimensions
    QFile file(":text.qrc/text.txt"); //Add path
    QTextStream in(&file);
    for (int i = 0; i < data.size(); i++)  //Source: https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/
    {
        for (int j = 0; j < data[i].size(); j++)
        {
            QString number;
            in>>number;
            data[i][j]=number.toInt(); //Here we copy the information in the file to the 2d vector


        }
    }
    file.close();

}

void instantiate_items(vector<vector<int>> data, vector<defense*>& defenses, vector<castle*>& castles,  vector<fence*>& fences){
    for (int i = 0; i < data.size(); i++)  //Source: https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/
    {
        for (int j = 0; j < data[i].size(); j++)
        {
            if (data[i][j]==1){
                castle* inst_castle = new castle;
                inst_castle->setPos(i*100, j*100);
                castles.push_back(inst_castle);
            }
            else if(data[i][j]==2){
                defense* inst_defense = new defense;
                inst_defense->setPos(i*100, j*100);
                defenses.push_back(inst_defense);

            }
            else if(data[i][j]==3){
                fence* inst_fence = new fence;
                inst_fence->setPos(i*100, j*100);
                fences.push_back(inst_fence);

            }

        }
        cout<<endl;
    }
}

