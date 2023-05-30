
#ifndef POKEMONLIB_H
#define POKEMONLIB_H
#include <iostream>
#include <vector>

using namespace std;

class PokemonLib
{
private:
    string name;
    vector<string> types;
    int hp;
    int atk;
    int def;
    int spAtk;
    int spDef;
    int speed;
public:
    void setName(string input);
    void setTypes(string input);
    void setHp(int input);
    void setAtk(int input);
    void setDef(int input);
    void setSpAtk(int input);
    void setSpDef(int input);
    void setSpeed(int input);
};

#endif // POKEMONLIB_H
