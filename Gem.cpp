//
// Created by lst on 15/6/21.
//

#include <ctime>
#include <cstdlib>
#include "Gem.h"

Gem::Gem() : inMap(0,0) {

}

void Gem::setPoint(vector<Point> &startingPoints) {
    srand(time(nullptr));

    int size = (int) startingPoints.size();
    int rand_int = rand()%size;

    this->inMap.setX(startingPoints[rand_int].getX());
    this->inMap.setY(startingPoints[rand_int].getY());


    startingPoints.erase(startingPoints.begin()+0);


}

int Gem::getY() {
    return inMap.getY();

}

int Gem::getX() {
    return inMap.getX();
}
