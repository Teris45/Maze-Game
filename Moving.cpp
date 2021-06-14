//
// Created by lst on 14/6/21.
//

#include "Moving.h"

#include <cmath>

#include <utility>

using namespace std;



void Moving::Move(Traal &traal, Poter &poter, const vector<vector<int>> &maze){
    vector<Point> possibleMoveSet;

    Point p = traal.getPoint();

    possibleMoveSet = get_possible_moveset(p,maze);

    possibleMoveSet.push_back(p);

    p = getShortestEuclidean(poter,possibleMoveSet);





}
vector<Point> Moving :: get_possible_moveset(const Point &p, const vector<vector<int>> &maze){
    vector<Point> possibleMoveSet;

    int y = p.getY();
    int x = p.getX();

    if(maze[y+1][x] > 0) {
        Point p1(x,y+1);
        possibleMoveSet.push_back(p1);
    }

    if(maze[y-1][x] > 0) {
        Point p1(x,y-1);
        possibleMoveSet.push_back(p1);
    }

    if(maze[y][x+1] > 0) {
        Point p1(x+1,y);
        possibleMoveSet.push_back(p1);
    }

    if(maze[y][x-1] > 0) {
        Point p1(x-1,y);
        possibleMoveSet.push_back(p1);
    }


    return possibleMoveSet;
}

void Moving::Move(Goblin &goblin, Poter &poter, const vector<vector<int>> &maze) {

}

void Moving::Move(Poter &poter, const vector<vector<int>> &maze) {

}
Point Moving::getShortestEuclidean(Poter &poter, const vector<Point> &possibleMoveSet) {
    int flag_first = 0;
    Point *ret = nullptr;
    int minEucl = 0;

    for(auto p: possibleMoveSet){

    }
}

