
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Pokemon.h"
#include <map>
#include "Player.h"

using namespace std;

class Game
{
private:
    Player human;
    Player computer;
    map<string, vector<string>> allMoves;
    map<string, Pokemon> allPokemons;
    vector<std::vector<double>> typeEffectiveness;
public:
    Game();
    void executeComputerMove(string computerMove, int playType);
    void loadPokemonFile(string pokemonFile);//load pokemon file
    void loadMoveFile(string moveFile);//load move file
    void loadGameFile(string gameFile);//load game file
    void ExecuteCommandFile(string testFile);//implement test case
    void Battle(string humanMove, string computerMove, int playType);//Battle command
    void Bag(string potion, string ownPokemon, string computerMove, int playType);//Bag command
    void pokemon(string ownPokemon, string computerMove);//Pokemon command
    void attackPokemon(string move, string target,int playType);
    void status(ostream& oStream = cout);//Status command
    void check(ostream& oStream = cout);//Check command
    void run();//Run command
    double getTypeEffectiveness(string atkType, string defType);
};

#endif // GAME_H
