#ifndef ENGINE_H
#define ENGINE_H

#include<cstdlib>
#include<vector>
#include <string>
#include "Living.h"
#include "Moving.h"


using namespace std;

#define WALL 0
#define DIADROMOS 1
#define POTERAKOS 2
#define GOBLINAKOS 3
#define TRAALINAKOS 4
#define PETRADI 5
#define PERGAMINI 6

class Engine {

private:
    //Using vector for parsing undefined maze size
    //Walls will be considered as 0, and routes will be considered as 1.
    vector<vector<int>> maze;

    MyMoving moving;
    Poter poterakos;
    Goblin goblinakos;
    Traal traalinakos;


public:
    Engine(const string& filename);

    void makeMove();

    const vector<vector<int>> &getMaze() const;

    void setMaze(const vector<vector<int>> &maze);

    void printMaze();

    void mapUpdate();

    ~Engine();
};


#endif