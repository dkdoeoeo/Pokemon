
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include "Pokemon.h"
#include "Move.h"

using namespace std;

class Player
{
private:
    int selectPokemon;//current pokemon index
    vector<Pokemon> pokemons;
    int potion;
    int superPotion;
    int hyperPotion;
    int maxPotion;

public:
    vector<Pokemon>& getPokemons();
    int getSelectPokemon();
    void setSelectPokemon(int input);
    void resizePokemons(int input);
    void appendPokemons(Pokemon input);
    void resizePokemonMove(int input);
    void appendPokemonMove(Pokemon input);
    void setAllPotion(int input);//set amount of each Potion
    void usePotion();
    void useSuperPotion();
    void useHyperPotion();
    void useMaxPotion();
};

#endif // PLAYER_H
