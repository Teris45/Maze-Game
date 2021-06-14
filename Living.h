
#ifndef LIVING_H
#define LIVING_H
#include <vector>

using namespace std;

class Point{

private:
    int x;
    int y;

public:

    Point(int x, int y);

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    virtual ~Point();

};


class Living {
private:

    Point inMap;

public:
    Living();

    void setPoint(vector<Point> &startingPoints);

    void setPoint(int x, int y);

    Point getPoint();

    void moveUp();

    void moveDown();

    void moveLeft();

    void moveRight();

    virtual ~Living();

    void setPoint(const Point &p);
};

class Poter: public Living{

public:
    Poter();

    ~Poter() override;
};

class Goblin: public Living {
public:
    Goblin();

    ~Goblin() override;
};

class Traal: public Living {
public:
    Traal();

    ~Traal() override;

};

#endif