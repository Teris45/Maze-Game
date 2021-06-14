//
// Created by lst on 9/6/21.
//

#include <fstream>
#include <iostream>
#include "Engine.h"

Engine::Engine(const string& filename) : poterakos(), goblinakos(), traalinakos(){

    ifstream file(filename);
    string str;

    vector<Point> startingPoints;

    //Iterating through maze, and building it
    int y = 0;
    while (getline(file, str)){
        int x = 0;
        vector<int> line;
        for(char i : str) {
            if (i == '*')
                line.insert(line.end(), 0);
            else if (i == ' ') {
                line.insert(line.end(), 1);
                Point p(x,y);
                startingPoints.push_back(p);
            }
            x++;
        }
        y++;
        this->maze.insert(this->maze.end(),line);

    }
    this->poterakos.setPoint(startingPoints);
    this->goblinakos.setPoint(startingPoints);
    this->traalinakos.setPoint(startingPoints);

    mapUpdate();

}


void Engine::mapUpdate(){
    Point poter = this->poterakos.getPoint();
    Point goblin = this->goblinakos.getPoint();
    Point traal = this->traalinakos.getPoint();

    this->maze[poter.getY()][poter.getX()] = POTERAKOS;
    this->maze[goblin.getY()][goblin.getX()] = GOBLINAKOS;
    this->maze[traal.getY()][traal.getX()] = TRAALINAKOS;

}


void Engine::printMaze(){
    for(auto & it : maze)
    {
        for(int & it1 : it){
            if(it1 == WALL)
                cout<<'*';
            else if(it1 == DIADROMOS)
                cout<<' ';
            else if(it1 == GOBLINAKOS)
                cout<<'G';
            else if(it1 == TRAALINAKOS)
                cout<<'T';
            else if(it1 == POTERAKOS)
                cout<<'P';

        }
        cout<<endl;

    }
}

const vector<vector<int>> &Engine::getMaze() const {
    return maze;
}

void Engine::setMaze(const vector<vector<int>> &maze) {
    this->maze = maze;
}

Engine::~Engine() {

}
