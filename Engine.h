#ifndef ENGINE_H
#define ENGINE_H

#include<cstdlib>
#include<vector>
#include <string>
#include "Living.h"
#include "Moving.h"
#include "maze_element.h"
#include "Gem.h"
#include <ncurses.h>

#define NUMGEMS 10
using namespace std;

#include "HighScore.h"

class Engine {

private:
    //Using vector for parsing undefined maze size
    //Walls will be considered as 0, and routes will be considered as 1.
    vector<vector<int>> maze;
    vector<Point> available_points;
    int last_row; //For printing high score
    MyMoving moving;
    Poter poterakos;
    Goblin goblinakos;
    Traal traalinakos;
    Gem gems[NUMGEMS];
    Gem Pergamini;

    HighScore hg;

    string username;

    int cntEatenGems;
    bool poterAlive;

    bool winner;

    bool gameEnded;


public:
    explicit Engine(const string& filename,const string& mybin, char *playersname);

    void gameLoop();

    void makeMove();

    const vector<vector<int>> &getMaze() const;

    void setMaze(const vector<vector<int>> &new_maze);

    void printMaze();

    void updateHG(const string& filename);

//    void mapUpdate();

    bool getGameEnded() const;

    ~Engine();

    void checkEnding();

    void GetInput();

    void moveCheck(int py, int px);

    void setAvailablePoints();
};


#endif