
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include "Pokemo.h"
#include "Move.h"

using namespace std;

class Player
{
private:
    int seletPokemon;//current pokemon index
    vector<Pokemon> pokemons;
public:
    void setSeletPokemon(int input);
    void resizePokemons(int input);
    void appendPokemons(Pokemon input);
    void resizePokemonMove(int input);
    void appendPokemonMove(Pokemon input);
};

#endif // PLAYER_H
