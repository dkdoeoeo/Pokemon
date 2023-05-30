#include <fstream>
#include "Game.h"
#define testMode 1
#define playMode 2
// Intent: Execute test mode
// Pre: file name
// Post: Execute test mode
void Game::ExecuteCommandFile(string testFile)
{

}

// Intent: load pokemon library
// Pre: file name
// Post: load pokemon library
void Game::loadPokemonFile(string pokemonFile)
{

}

// Intent: load move library
// Pre: file name
// Post: load move library
void Game::loadMoveFile(string moveFile)
{

}

// Intent: load game data, number of pokemons, number of moves, name of moves,
// Pre: file name
// Post: load game data
void Game::loadGameFile(string gameFile)
{
    ifstream iFile("../GameData.txt");
    if(!iFile.is_open())
    {
        cout << "open GameData.txt failed\n";
        return;
    }

    int numOfPokemons_Player = 0;
    int numOfPokemons_Comp = 0;
    int numOfplayerPokemonMove = 0;
    int numOfCompPokemonMove = 0;
    string pokemonMove;
    string pokemonName;

    iFile >> numOfPokemons_Player;
    human.resizePokemons(numOfPokemons_Player);

    for (int var = 0; var < numOfPokemons_Player; ++var) {
        iFile >> pokemonName;
        iFile >> numOfplayerPokemonMove;
        human.getPokemons()[var].setName(pokemonName);

        for (int i = 0; i < numOfplayerPokemonMove; ++i) {
            iFile >> pokemonMove;
            Move curMove;
            curMove.setName(pokemonMove);
            human.getPokemons()[var].appendMoves(curMove);
        }

    }

    iFile >> numOfPokemons_Comp;
    computer.resizePokemons(numOfPokemons_Comp);

    for (int var = 0; var < numOfPokemons_Comp; ++var) {
        iFile >> pokemonName;
        iFile >> numOfCompPokemonMove;
        computer.getPokemons()[var].setName(pokemonName);

        for (int i = 0; i < numOfCompPokemonMove; ++i) {
            iFile >> pokemonMove;
            Move curMove;
            curMove.setName(pokemonMove);
            computer.getPokemons()[var].appendMoves(curMove);
        }

    }

    iFile.close();
}


// Intent: Battle command
// Pre: player’s Pokémon move and opponent’s
// Post: Execute Battle command
void Game::Battle(string humanMove, string computerMove, int playType)
{
    if(playType == testMode)
    {

    }
    else if(playType == playMode)
    {

    }
}

// Intent: Battle command
// Pre: name of the potion, player’s Pokémon and opponent’s move
// Post: heal pokemon
void Game::Bag(string potion, string ownPokemon, string computerMove, int playType)
{
    if(playType == testMode)
    {

    }
    else if(playType == playMode)
    {

    }
}

// Intent: Pokemon command
// Pre: player’s Pokémon and opponent’s move
// Post: switch pokemon
void Game::pokemon(string ownPokemon, string computerMove)
{

}

// Intent: Status command
// Pre: no
// Post: output both sides pokemon status
void Game::status()
{

}

// Intent: Check command
// Pre: no
// Post: output current pokemon moves and PP
void Game::check()
{

}

// Intent: Run command
// Pre: no
// Post: quit game
void Game::run()
{

}

