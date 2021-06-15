//
// Created by lst on 15/6/21.
//

#ifndef HIGHSCORE_H
#define HIGHSCORE_H

//#include <cstdlib>
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

class names{
public:
    char name[10]{};
    names();
    void setname(string myname);
    void load(ifstream& inf);
    void save(ofstream &of);
};

class HighScore {
private:
    names name[5]{};
    int score[5]{};
public:
    HighScore();
    void save(ofstream& of);
    void load(ifstream& inf);
    char* toStr();
    HighScore& operator<<(string name);
    HighScore& operator<<(int score);

    ~HighScore();
};


#endif //HIGHSCORE_H
