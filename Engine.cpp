//
// Created by lst on 9/6/21.
//

#include <fstream>
#include <iostream>
#include <unistd.h>
#include "Engine.h"
#include "Moving.h"

void Engine :: makeMove(){
    Point old_point = traalinakos.getPoint();
    Point new_point = MyMoving :: Move(traalinakos,poterakos,maze);
    traalinakos.setPoint(new_point.getX(),new_point.getY());
    maze[old_point.getY()][old_point.getX()] = DIADROMOS;
    if(maze[new_point.getY()][new_point.getX()] == POTERAKOS) {
        poterAlive = false;
    }
    maze[new_point.getY()][new_point.getX()] = TRAALINAKOS;

    Point old_point_goblin = goblinakos.getPoint();
    Point new_point_goblin = MyMoving :: Move(goblinakos,poterakos,maze);
    goblinakos.setPoint(new_point_goblin.getX(),new_point_goblin.getY());
    maze[old_point_goblin.getY()][old_point_goblin.getX()] = DIADROMOS;
    if(maze[new_point_goblin.getY()][new_point_goblin.getX()] == POTERAKOS) {
        poterAlive = false;
    }
    maze[new_point_goblin.getY()][new_point_goblin.getX()] = GOBLINAKOS;
}

Engine::Engine(const string& filename,const string& mybin, char *playersname) :moving(), poterakos(), goblinakos(), traalinakos(),hg(),username(playersname){

    curs_set(0);
    addstr("Welcome to the game young Mpampis\n\n");
    refresh();
    sleep(1);

    int xr,yr;
    getyx(stdscr,yr,xr);
    move(yr,0);
    clrtoeol();
    refresh();

    move(0,0);

    sleep(1);
    ifstream file(filename);
    string str;


    //Iterating through maze, and building it
    int y = 0;
    while (getline(file, str)){
        int x = 0;
        auto *line = new vector<int>;
        for(char i : str) {
            if (i == '*')
                line->insert(line->end(), WALL);
            else if (i == ' ') {
                line->insert(line->end(), DIADROMOS);
                Point p(x,y);
                this->available_points.push_back(p);
            }
            x++;
        }
        y++;
        this->maze.insert(this->maze.end(),*line);
    }
    this->last_row = y;
    this->poterakos.setPoint(available_points);
    this->maze[poterakos.getPoint().getY()][poterakos.getPoint().getX()] = POTERAKOS;


    this->goblinakos.setPoint(available_points);
    this->maze[goblinakos.getPoint().getY()][goblinakos.getPoint().getX()] = GOBLINAKOS;


    this->traalinakos.setPoint(available_points);
    this->maze[traalinakos.getPoint().getY()][traalinakos.getPoint().getX()] = TRAALINAKOS;

    for(auto & gem : this->gems) {
        gem.setPoint(available_points);
        this->maze[gem.getY()][gem.getX()] = GEM;
    }

    this->poterAlive = true;
    this->cntEatenGems = 0;
    this->winner = false;
    this->gameEnded = false;

//    mapUpdate();

    file.close();

    ifstream file2(mybin,ios::binary | ios::in);

    char c = file2.get();
    if(c==EOF){
        file2.close();
    }
    else{
        file2.close();
        ifstream  file3(mybin,ios::binary | ios::in);
        hg.load(file3);
        cout<<hg.toStr();
        file3.close();
    }


}

/*
void Engine::mapUpdate(){
    Point poter = this->poterakos.getPoint();
    Point goblin = this->goblinakos.getPoint();
    Point traal = this->traalinakos.getPoint();

    this->maze[poter.getY()][poter.getX()] = POTERAKOS;
    this->maze[goblin.getY()][goblin.getX()] = GOBLINAKOS;
    this->maze[traal.getY()][traal.getX()] = TRAALINAKOS;
    this->maze[gems.getY()][gems.getX()] = GEM;

}
*/

void Engine::printMaze(){
    for(auto & it : maze)
    {
        for(auto & it1 : it){
            if(it1 == WALL)
                addch('*');
            else if(it1 == DIADROMOS)
                addch(' ');
            else if(it1 == GOBLINAKOS)
                addch('G');
            else if(it1 == TRAALINAKOS)
                addch('T');
            else if(it1 == POTERAKOS)
                addch('P');
            else if(it1 == GEM)
                addch('0');

        }
        addch('\n');

    }

    addstr("------------------------------------------\n");
    addstr("HIGH SCORES\n");
    const char *str = hg.toStr();
    addstr(str);

}



const vector<vector<int>> &Engine::getMaze() const {
    return maze;
}

void Engine::setMaze(const vector<vector<int>> &new_maze) {
    this->maze = new_maze;
}

Engine::~Engine() {
    endwin();
}

void Engine::gameLoop() {
    Engine::GetInput();
    Engine::checkEnding();
    Engine::makeMove();
    Engine::checkEnding();
    refresh();
}

void Engine::GetInput() {
    bool flag = true;
    Point oldPoter = poterakos.getPoint();
    while(flag) {
        int ch = getch();
        switch (ch) {
            bool n;
            case KEY_UP:
                n = MyMoving::checkMove(poterakos,maze,ch);
                if(n){
                    flag = false;
                    this->moveCheck(oldPoter.getY()-1,oldPoter.getX());
                    this->maze[oldPoter.getY()][oldPoter.getX()] = DIADROMOS;
                }
                break;
            case KEY_DOWN:
                n = MyMoving::checkMove(poterakos,maze,ch);
                if(n) {
                    flag = false;
                    this->moveCheck(oldPoter.getY() + 1, oldPoter.getX());
                    this->maze[oldPoter.getY()][oldPoter.getX()] = DIADROMOS;

                }
                break;
            case KEY_RIGHT:
                n = MyMoving::checkMove(poterakos,maze,ch);
                if(n){
                    flag = false;
                    this->moveCheck(oldPoter.getY(), oldPoter.getX()+1);
                    this->maze[oldPoter.getY()][oldPoter.getX()] = DIADROMOS;

                }
                break;
            case KEY_LEFT:
                n = MyMoving::checkMove(poterakos,maze,ch);
                if(n){
                    flag = false;
                    this->moveCheck(oldPoter.getY(), oldPoter.getX()-1);
                    this->maze[oldPoter.getY()][oldPoter.getX()] = DIADROMOS;
                }
                break;
            case 27: //ESCAPE
                this->poterAlive = false;
//                cout<<"MPika edw?\n";
                flag = false;
                break;
            case ' ':
                flag = false;
        }
    }
}

void Engine::checkEnding() {
    if(this->winner){
        refresh();
        sleep(1);
        clear();
        move(0,0);
        addstr("YOU ARE THE WINNER\n");
        refresh();
        sleep(1);
        this->gameEnded = true;
    }
    else if(!this->poterAlive){
        refresh();
        sleep(1);
        clear();
        move(0,0);
        addstr("YOU LOST :(\n");
        refresh();
        sleep(1);
        this->gameEnded = true;
    }
}

bool Engine::getGameEnded() const {
    return this->gameEnded;
}


void Engine::moveCheck(int py,int px){

    if(maze[py][px] == GEM){
        this->cntEatenGems++;
        this->poterakos.setPoint(px,py);
        this->maze[py][px] = POTERAKOS;
        if(cntEatenGems == NUMGEMS){
            this->setAvailablePoints();
            this->Pergamini.setPoint(available_points);
            maze[Pergamini.getY()][Pergamini.getX()] = PERGAMINI;
            mvaddch(Pergamini.getY(),Pergamini.getX(),'#');
        }
    }
    else if(maze[py][px] == PERGAMINI){
        this->winner = true;
        this->poterakos.setPoint(px,py);
        this->maze[py][px] = POTERAKOS;

    }
    else if(maze[py][px] == GOBLINAKOS || maze[py][px] == TRAALINAKOS){
        this->poterAlive = false;
    }
    else if(maze[py][px] == DIADROMOS){
        this->poterakos.setPoint(px,py);
        this->maze[py][px] = POTERAKOS;

    }


}

void Engine::setAvailablePoints() {
    this->available_points.clear();
    for(int y = 0; y<(int) maze.size();y++){
        for(int x=0;x<(int) maze[y].size();x++){
            if(maze[y][x] == DIADROMOS){
                Point p1(x,y);
                available_points.push_back(p1);
            }
        }
    }
}

void Engine::updateHG(const string& filename) {

    int score = cntEatenGems * 10;
    if(winner)
        score += 10;
    hg<<this->username<< score;

    ofstream file(filename, ios::binary | ios::out);

    hg.save(file);

    file.close();

}
