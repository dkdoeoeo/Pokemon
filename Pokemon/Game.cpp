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

// Intent: load game data
// Pre: file name
// Post: load game data
void Game::loadGameFile(string gameFile)
{

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

