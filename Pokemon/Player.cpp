#include "Player.h"

vector<Pokemon>& Player::getPokemons()
{
    return pokemons;
}

int Player::getSelectPokemon()
{
    return selectPokemon;
}
void Player::setSelectPokemon(int input)
{
    selectPokemon = input;
}

void Player::resizePokemons(int input)
{
    pokemons.resize(input);
}

void Player::appendPokemons(Pokemon input)
{
    pokemons.push_back(input);
}

void Player::setAllPotion(int input)
{

}

void Player::usePotion()
{

}

void Player::useSuperPotion()
{

}

void Player::useHyperPotion()
{

}

void Player::useMaxPotion()
{

}
