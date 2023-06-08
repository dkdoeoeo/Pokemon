
#ifndef MOVE_H
#define MOVE_H
#include <iostream>

using namespace std;

class Move
{
private:
    string name = "";
    string type = "";
    string PS = "";
    int power = 0;
    int accuracy = 0;
    int PP = 0;
    string con = "";
public:
    void setName(string input);
    void setType(string input);
    void setPS(string input);
    void setPower(int input);
    void setAccuracy(int input);
    void setPP(int input);
    void setCon(string input);
    string getName();
    string getType();
    string getPS();
    int getPower();
    int getAccuracy();
    int getPP();
    string getCon();
};

#endif // MOVE_H
