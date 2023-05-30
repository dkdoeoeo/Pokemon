
#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include <vector>
#include "Move.h"

using namespace std;

class Pokemon
{
private:
    string name;
    vector<string> types;
    vector<Move> moves;
    int hp;
    int atk;
    int def;
    int spAtk;
    int spDef;
    int speed;
    string con;
public:
    void setName(string input);
    void setHp(int input);
    void setAtk(int input);
    void setDef(int input);
    void setSpAtk(int input);
    void setSpDef(int input);
    void setSpeed(int input);
    void resizeTypes(int input);
    void resizeMoves(int input);
    void appendTypes(string input);
    void appendMoves(Move input);
    string getName();
    vector<string> getTypes();
    vector<Move> getMoves();
    int getHp();
    int getAtk();
    int getDef();
    int getSpAtk();
    int getSpDef();
    int getSpeed();
    string getCon();
};

#endif // POKEMON_H
