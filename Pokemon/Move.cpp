#include "Move.h"

void Move::setName(string input)
{
    name = input;
}

void Move::setType(string input)
{
    type = input;
}

void Move::setPS(string input)
{
    PS = input;
}

void Move::setPower(int input)
{
    power = input;
}

void Move::setAccuracy(int input)
{
    accuracy = input;
}

void Move::setPP(int input)
{
    PP = input;
}

void Move::setCon(string input)
{
    con = input;
}

string Move::getName()
{
    return name;
}

string Move::getType()
{
    return type;
}

string Move::getPS()
{
    return PS;
}

int Move::getPower()
{
    return power;
}

int Move::getAccuracy()
{
    return accuracy;
}

int Move::getPP()
{
    return PP;
}

string Move::getCon()
{
    return con;
}
