#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "Living.h"
#include <vector>
#include <iostream>
#include <cmath>


using namespace std;



float Point:: euclidean(const Point &point){
    int x2 = this->x - point.x;
    int y2 = this->y - point.y;

    x2 = x2*x2;
    y2 = y2*y2;

    int distance = x2 + y2;

    return sqrt(distance);
}

void Living::setPoint(const Point &p) {
    inMap.setX(p.getX());
    inMap.setY(p.getY());
}

void Living::setPoint(int x, int y) {
    inMap.setX(x);
    inMap.setY(y);
}

void Living::moveUp(){
    inMap.setY(inMap.getY()+1);
}

void Living::moveDown(){
    inMap.setY(inMap.getY()-1);
}

void Living::moveLeft(){
    inMap.setX(inMap.getX()-1);
}

void Living::moveRight(){
    inMap.setX(inMap.getX()+1);
}

void Living::setPoint(vector<Point> &starting) {
    srand(time(nullptr));

    int size = (int) starting.size();
    int rand_int = rand()%size;

    this->inMap.setX(starting[rand_int].getX());
    this->inMap.setY(starting[rand_int].getY());

    starting.erase(starting.begin()+rand_int);

}

Living::Living() : inMap(0,0){

}

Point Living::getPoint() {
    return this->inMap;
}

Living::~Living() {

}


Point::Point(int x, int y) : x(x), y(y) {}

int Point::getX() const {
    return x;
}

void Point::setX(int x) {
    Point::x = x;
}

int Point::getY() const {
    return y;
}

void Point::setY(int y) {
    Point::y = y;
}

Point::~Point() {

}

void Point::print() {
    cout<<y<<","<<x<<endl;

}

Monster::Monster() : Living(){
}

Monster::~Monster(){

}

Goblin::Goblin() : Monster() {

}

Goblin::~Goblin() {

}

Traal::Traal() : Monster() {

}

Traal::~Traal(){

}

Poter::Poter() : Living() {

}

Poter::~Poter() {

}
