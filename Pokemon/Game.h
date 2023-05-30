
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Player.h"

using namespace std;

class Game
{
private:
    Player human;
    Player computer;
public:
    void loadPokemonFile(string pokemonFile);//load pokemon file
    void loadMoveFile(string moveFile);//load move file
    void loadGameFile(string gameFile);//load game file
    void ExecuteCommandFile(string testFile);//implement test case
    void Battle(string humanMove, string computerMove);
    void Bag(string potion);
    void
};

#endif // GAME_H
