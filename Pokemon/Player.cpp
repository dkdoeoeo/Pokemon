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
    potion = input;
    superPotion = input;
    hyperPotion = input;
    maxPotion = input;
}

void Player::usePotion()
{
    potion--;
}

void Player::useSuperPotion()
{
    superPotion--;
}

void Player::useHyperPotion()
{
    hyperPotion--;
}

void Player::useMaxPotion()
{
    maxPotion--;
}

bool Player::ifHavePotion(string input)
{
    if(input == "Potion" && potion > 0)
    {
        return true;
    }
    else if(input == "SuperPotion" && superPotion > 0)
    {
        return true;
    }
    else if(input == "HyperPotion" && hyperPotion > 0)
    {
        return true;
    }
    else if(input == "MaxPotion" && maxPotion> 0)
    {
        return true;
    }
    return false;
}
