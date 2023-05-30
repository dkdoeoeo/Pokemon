
#ifndef MOVELIB_H
#define MOVELIB_H
#include <iostream>

using namespace std;

class MoveLib
{
private:
    string name;
    string type;
    string PS;
    int power;
    int accuracy;
    int PP;
    string Con;
public:
    void setName(string input);
    void setType(string input);
    void setPS(string input);
    void setPower(int input);
    void setAccuracy(int input);
    void setPP(int input);
    void setCon(string input);
};

#endif // MOVELIB_H
