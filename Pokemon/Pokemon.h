
#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include <vector>
#include "Move.h"

using namespace std;

class Pokemon
{
private:
    string name = "";
    vector<string> types;
    vector<Move> moves;
    int hp = 0;
    int atk = 0;
    int def = 0;
    int spAtk = 0;
    int spDef = 0;
    int speed = 0;
    bool ifFainted = false;
    int con[3] = {0};
    const int level = 50;
public:
    void setName(string input);
    void setHp(int input);
    void setAtk(int input);
    void setDef(int input);
    void setSpAtk(int input);
    void setSpDef(int input);
    void setSpeed(int input);
    void setIfFainted(bool input);
    void setCon(string con, int input);
    void clearTypes();
    void clearMoves();
    void appendTypes(string input);
    void appendMoves(Move input);
    string getName();
    vector<string> getTypes();
    vector<Move>& getMoves();
    int getHp();
    int getAtk();
    int getDef();
    int getSpAtk();
    int getSpDef();
    int getSpeed();
    int getCon(string con);
    int getIfFainted();
    const int getLevel();
};

#endif // POKEMON_H
