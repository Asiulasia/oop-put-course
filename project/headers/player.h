#include <iostream>
#include <string>
using namespace std;

class Board;

class Player
{
protected:
    string name;
    char chosen;
    int points;
public:
    string Name(){ return name; };
    Player(string n, char c, int p);
    void Points();
    void addPoints();
    friend class Board;
};
