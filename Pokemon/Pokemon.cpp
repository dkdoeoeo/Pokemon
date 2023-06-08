#include "Pokemon.h"

Pokemon::Pokemon()
{

}

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

void Pokemon::setIfFainted(bool input)
{
    ifFainted = input;
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

void Pokemon::setCon(string con, int input)
{
    if(con == "PAR")
    {
        this->con[0] += input;
    }
    else if(con == "BRN")
    {
        this->con[1] += input;
    }
    else if(con == "PSN")
    {
        this->con[2] += input;
    }

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

int Pokemon::getCon(string con)
{
    if(con == "PAR")
    {
        return this->con[0];
    }
    else if(con == "BRN")
    {
        return this->con[1];
    }
    else if(con == "PSN")
    {
        return this->con[2];
    }

    return -1;
}

int Pokemon::getIfFainted()
{
    return ifFainted;
}

const int Pokemon::getLevel()
{
    return level;
}
