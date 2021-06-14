#include <iostream>
#include "Engine.h"

int main() {
    auto* engine = new Engine("maze.txt");
    engine->printMaze();
    return 0;
}
