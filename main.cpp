#include <iostream>
#include "Engine.h"
#include <unistd.h>
int main(int argc, char *argv[]) {
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    clear();

    char name[10];
    addstr("Enter Player's name: ");

    getstr(name);



    noecho();

    if(argc<3)
        throw "NOT ENOUGH ARGUMENTS";

    auto* engine = new Engine(argv[1],argv[2],name);
    engine->printMaze();
    refresh();
    sleep(1);

    while(!engine->getGameEnded()){
        engine->gameLoop();
    }

    engine->updateHG(argv[2]);
//    engine->makeMove();

//    refresh();
    //    engine->printMaze();

//    sleep(2);

    delete engine;
    return 0;
}
