#include "Moving.h"
#include <cmath>
#include <utility>

using namespace std;

MyMoving::MyMoving(){}


void MyMoving::Move(Monster &monster, Poter &poter, const vector<vector<int>> &maze){
    vector<Point> possibleMoveSet;

    Point p = monster.getPoint();

    possibleMoveSet = get_possible_moveset(p,maze);

    possibleMoveSet.push_back(p);

    p = getShortestEuclidean(poter,possibleMoveSet);


    monster.getPoint().setX(p.getX());
    monster.getPoint().setY(p.getY());



}
vector<Point> MyMoving :: get_possible_moveset(const Point &p, const vector<vector<int>> &maze){
    vector<Point> possibleMoveSet;

    int y = p.getY();
    int x = p.getX();

    if(maze[y+1][x] == DIADROMOS || maze[y+1][x] == POTERAKOS ) {
        Point p1(x,y+1);
        possibleMoveSet.push_back(p1);
    }

    if(maze[y-1][x] == DIADROMOS || maze[y-1][x] == POTERAKOS) {
        Point p1(x,y-1);
        possibleMoveSet.push_back(p1);
    }

    if(maze[y][x+1] == DIADROMOS || maze[y][x+1] == POTERAKOS) {
        Point p1(x+1,y);
        possibleMoveSet.push_back(p1);
    }

    if(maze[y][x-1] == DIADROMOS || maze[y][x-1] == POTERAKOS) {
        Point p1(x-1,y);
        possibleMoveSet.push_back(p1);
    }


    return possibleMoveSet;
}

void MyMoving::Move(Goblin &goblin, Poter &poter, const vector<vector<int>> &maze) {

}

void MyMoving::Move(Poter &poter, const vector<vector<int>> &maze) {

}
Point MyMoving::getShortestEuclidean(Poter &poter, const vector<Point> &possibleMoveSet) {
    int flag_first = 0;
    Point *ret = nullptr;
    float minEucl = 0;

    for(auto p: possibleMoveSet){
        if(flag_first == 0){
            ret = &p;
            minEucl = p.euclidean(poter.getPoint());
            flag_first = 1;
        }
        else{
            float temp = p.euclidean(poter.getPoint());
            if(temp<minEucl){
                minEucl = temp;
                ret = &p;
            }
        }

    }

    return *ret;

}

