#ifndef MOVING_H
#define MOVING_H

#include "Living.h"
#include "maze_element.h"



class MyMoving {
public:
    MyMoving();
    static Point Move(Traal monster, Poter &poter, vector<vector<int>> &maze);
    static Point Move(Goblin &goblin, Poter &poter,const vector<vector<int>> &maze);

    static vector<Point> get_possible_moveset(const Point &p, const vector<vector<int>> &maze);

    static Point getShortestEuclidean(Poter &poter, const vector<Point> &possibleMoveSet);


    static bool checkMove(Poter& poter,  vector<vector<int>> &maze, int i);
};


#endif