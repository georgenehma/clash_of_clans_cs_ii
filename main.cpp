#include <QApplication>
#include <QFile>
#include <vector>
#include<QTextStream>
#include <QTextStream>
#include <QFile>
#include <QString>
#include<castle.h>
#include<citizen.h>
#include<enemy.h>
#include<fence.h>
#include<defense.h>

using namespace std;
void read_file(vector<vector<int>>& data, int rows, int columns);
//Precondition: Receives a 2D vector and the dimensions one wishes to set it to
//Postcondition: If the file is successfully read it returns true, otherwise it returns false

void instantiate_items(vector<vector<int>> data, vector<defense*>& defense, vector<castle*>& castles, vector<enemy*>& enemies);
//Precondition: Receives a 2d vector containing 0 for empty land, 1 for clan castle, 2 for defense unit, 3 for fence. It also receives three vectors of pointers towards these different objects
//Postcondition: instantiates these items by calling their respective constructors and fills

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

}

void read_file(vector<vector<int>>& data, int rows, int columns){
    for (int i = 0 ; i < rows ; i++){
        data[i].resize(columns);
    }
    QFile file("path"); //Add path
    QFile in(&file);
    for (size_t i = 0; i < data.size(); i++)  //Source: https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/
    {
        for (size_t j = 0; j < data[i].size(); j++)
        {
            QString::number(data[i][j]);

        }
    }
    in.close();

}

void instantiate_items(vector<vector<int>> data, vector<defense*>& defense, vector<castle*>& castles,  vector<enemy*>& enemies){
    for (size_t i = 0; i < data.size(); i++)  //Source: https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/
    {
        for (size_t j = 0; j < data[i].size(); j++)
        {
            if (data[i][j]==1){
                //castle* inst_castle = new castle;
                //castles.push_back(inst_castle);
            }
            else if(data[i][j]==2){
                //defense* inst_defense = new defense;
                //defense.push_back(inst_defense);

            }
            else if(data[i][j]==3){
                //enemy* inst_enemy = new enemy;
                //enemy.push_back(inst_defense);

            }

        }
    }
}
