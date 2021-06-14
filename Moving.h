#ifndef MOVING_H
#define MOVING_H

#include "Living.h"
#include "Engine.h"
class MyMoving {
public:
    MyMoving();
    void Move(Monster &monster, Poter &poter, const vector<vector<int>> &maze);
    void Move(Goblin &goblin, Poter &poter,const vector<vector<int>> &maze);
    void Move(Poter &poter,const vector<vector<int>> &maze);

    static vector<Point> get_possible_moveset(const Point &p, const vector<vector<int>> &maze);

    static Point getShortestEuclidean(Poter &poter, const vector<Point> &possibleMoveSet);
};


#endif