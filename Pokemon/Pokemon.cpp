#include "Pokemon.h"

void Pokemon::setName(string input)
{
    name = input;
}

void Pokemon::setHp(int input)
{
    hp = input;
}

void Pokemon::setAtk(int input)
{
    atk = input;
}

void Pokemon::setDef(int input)
{
    def = input;
}

void Pokemon::setSpAtk(int input)
{
    spAtk = input;
}

void Pokemon::setSpDef(int input)
{
    spDef = input;
}

void Pokemon::setSpeed(int input)
{
    speed = input;
}

void Pokemon::resizeTypes(int input)
{
    types.resize(input);
}

void Pokemon::resizeMoves(int input)
{
    moves.resize(input);
}

void Pokemon::appendTypes(string input)
{
    types.push_back(input);
}

void Pokemon::appendMoves(Move input)
{
    moves.push_back(input);
}

string Pokemon::getName()
{
    return name;
}

vector<string> Pokemon::getTypes()
{
    return types;
}

vector<Move>& Pokemon::getMoves()
{
    return moves;
}

int Pokemon::getHp()
{
    return hp;
}

int Pokemon::getAtk()
{
    return atk;
}

int Pokemon::getDef()
{
    return def;
}

int Pokemon::getSpAtk()
{
    return spAtk;
}

int Pokemon::getSpDef()
{
    return spDef;
}

int Pokemon::getSpeed()
{
    return speed;
}

string Pokemon::getCon()
{
    return con;
}
