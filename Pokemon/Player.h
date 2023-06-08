
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include "Pokemon.h"

using namespace std;

class Player
{
public:
    int selectPokemon = 0;//current pokemon index
    vector<Pokemon> pokemons;
    int potion = 3;
    int superPotion = 3;
    int hyperPotion = 3;
    int maxPotion = 3;

public:
    vector<Pokemon>& getPokemons();
    int getSelectPokemon();
    void setSelectPokemon(int input);
    void resizePokemons(int input);
    void appendPokemons(Pokemon input);
    void setAllPotion(int input);//set amount of each Potion
    void usePotion();
    void useSuperPotion();
    void useHyperPotion();
    void useMaxPotion();
    bool ifHavePotion(string input);
};

#endif // PLAYER_H
