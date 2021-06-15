//
// Created by lst on 15/6/21.
//

#ifndef GEM_H
#define GEM_H

#include "Living.h"

class Gem {
private:
    Point inMap;
public:
    Gem();
    void setPoint(vector<Point> &startingPoints);

    int getY();

    int getX();
};


#endif