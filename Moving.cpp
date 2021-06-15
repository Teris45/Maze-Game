#include "Moving.h"
#include <cmath>
#include <utility>
#include <iostream>
#include <ncurses.h>

using namespace std;

MyMoving::MyMoving()= default;


Point MyMoving::Move(Traal monster, Poter &poter, vector<vector<int>> &maze){
    vector<Point> possibleMoveSet;


    Point p = monster.getPoint();
    mvaddch(p.getY(),p.getX(),' ');

    possibleMoveSet = get_possible_moveset(p,maze);

    possibleMoveSet.push_back(p);

    p = getShortestEuclidean(poter,possibleMoveSet);

    mvaddch(p.getY(),p.getX(),'T');


    return p;
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

Point MyMoving::Move(Goblin &goblin, Poter &poter, const vector<vector<int>> &maze) {
    vector<Point> possibleMoveSet;


    Point p = goblin.getPoint();
    mvaddch(p.getY(),p.getX(),' ');

    possibleMoveSet = get_possible_moveset(p,maze);

    possibleMoveSet.push_back(p);

    p = getShortestEuclidean(poter,possibleMoveSet);

    mvaddch(p.getY(),p.getX(),'G');


    return p;
}

Point MyMoving::getShortestEuclidean(Poter &poter, const vector<Point> &possibleMoveSet) {
    int flag_first = 0;
    Point p(0,0);
    float min_euclidean = 0.0;
    for(Point points:possibleMoveSet){
        if(flag_first == 0){
            flag_first = 1;
            p.setY(points.getY());
            p.setX(points.getX());
            min_euclidean = points.euclidean(poter.getPoint());
        }
        else{
            float temp = points.euclidean(poter.getPoint());
            if(temp<min_euclidean){
                p.setY(points.getY());
                p.setX(points.getX());
            }
        }
    }

    return p;

}

bool MyMoving::checkMove(Poter& poter, vector<vector<int>> &maze, int i) {

    int py = poter.getPoint().getY();
    int px = poter.getPoint().getX();
    if(i==KEY_UP){
        int maze_el = maze[py-1][px];
        if(maze_el == DIADROMOS || maze_el == GEM || maze_el == PERGAMINI) {
            mvaddch(py,px,' ');
            mvaddch(py-1,px,'P');
            return true;

        }
        else if(maze_el == TRAALINAKOS || maze_el == GOBLINAKOS){
            mvaddch(py,px,' ');
            return true;
        }
    }
    else if(i == KEY_DOWN){
        int maze_el = maze[py+1][px];
        if(maze_el == DIADROMOS || maze_el == GEM || maze_el == PERGAMINI) {
            mvaddch(py,px,' ');
            mvaddch(py+1,px,'P');
            return true;

        }
        else if(maze_el == TRAALINAKOS || maze_el == GOBLINAKOS){
            mvaddch(py,px,' ');
            return true;

        }
    }
    else if(i==KEY_RIGHT){
        int maze_el = maze[py][px+1];
        if(maze_el == DIADROMOS || maze_el == GEM || maze_el == PERGAMINI) {
            mvaddch(py,px,' ');
            mvaddch(py,px+1,'P');
            return true;

        }
        else if(maze_el == TRAALINAKOS || maze_el == GOBLINAKOS){
            mvaddch(py,px,' ');
            return true;
        }
    }
    else if(i==KEY_LEFT){
        int maze_el = maze[py][px-1];
        if(maze_el == DIADROMOS || maze_el == GEM || maze_el == PERGAMINI) {
            mvaddch(py,px,' ');
            mvaddch(py,px-1,'P');
            return true;
        }
        else if(maze_el == TRAALINAKOS || maze_el == GOBLINAKOS){
            mvaddch(py,px,' ');
            return true;
        }
    }
    return false;
}


