
#ifndef GAME_H
#define GAME_H
#include <iostream>

using namespace std;

class Game
{
public:
    void loadPokemonFile(string pokemonFile);//load pokemon file
    void loadMoveFile(string moveFile);//load move file
    void loadGameFile(string gameFile);//load game file
    void ExecuteCommandFile(string testFile);//implement test case
};

#endif // GAME_H
