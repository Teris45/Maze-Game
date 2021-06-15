#include "HighScore.h"

#include <utility>
#include <cstring>

using namespace std;

void names::load(ifstream &inf){
    inf.read(this->name,sizeof(name));
}

void names::save(ofstream &of){
    of.write(this->name,sizeof(name));
}

void names::setname(string myname) {
    for(int i=0;i<10 && i<(int) myname.length();i++){
        name[i] = myname[i];
    }
}

HighScore ::HighScore() {
    for(int & i : score)
        i = -1;
}

void HighScore::save(ofstream &of) {
    for(int i=0;i<5;i++){
        if(score[i]!=-1){
            name[i].save(of);
            string str = to_string(score[i]);
            char *writeable = new char[str.size() + 1];
            copy(str.begin(),str.end(),writeable);
            writeable[str.size()] = '\0';
            of.write(writeable,sizeof(int));

        }
    }

}

void HighScore::load(ifstream &inf) {
    int i=0;
    while (inf.eof()){
        name[i].load(inf);
        char *val = nullptr;
        inf.read(val,sizeof(int));
        this->score[i] = atoi(val);
        i++;
    }

}

HighScore &HighScore::operator<<(string myname) {
    for(int i=0;i<4;i++){
        name[i+1] = name[i];
    }

    name[0].setname(std::move(myname));
    return *this;
}


HighScore &HighScore::operator<<(int myscore) {
    for(int i=0;i<4;i++){
        score[i+1] = score[i];
    }
    score[0] = myscore;
    return *this;
}

char* HighScore::toStr() {
    string str;
    for(int i=0;i<5;i++){
        if(score[i]==-1) {
            continue;
        }
        else {
            if (str.empty()) {
                str = name[i].name + to_string(score[i]) + "\n";
                cout<<str;
            }
            else {
                string str2;
                str2 = name[i].name + to_string(score[i]) + "\n";
                str.append(str2);
            }
        }
    }

    cout<<str;

    char *writeable = new char[str.size() + 1];
    copy(str.begin(),str.end(),writeable);
    writeable[str.size()] = '\0';
    return writeable;
}

HighScore::~HighScore() = default;


names::names() = default;
