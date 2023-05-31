
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <map>
#include "Player.h"

using namespace std;

class Game
{
private:
    Player human;
    Player computer;
    map<string, vector<string>> allMoves;
public:
    void loadPokemonFile(string pokemonFile);//load pokemon file
    void loadMoveFile(string moveFile);//load move file
    void loadGameFile(string gameFile);//load game file
    void ExecuteCommandFile(string testFile);//implement test case
    void Battle(string humanMove, string computerMove, int playType);//Battle command
    void Bag(string potion, string ownPokemon, string computerMove, int playType);//Bag command
    void pokemon(string ownPokemon, string computerMove);//Pokemon command
    void status();//Status command
    void check();//Check command
    void run();//Run command
};

#endif // GAME_H
