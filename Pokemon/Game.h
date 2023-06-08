
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Pokemon.h"
#include <map>
#include "Player.h"
#include <QString>
using namespace std;

class Game
{
private:
    Player human;
    Player computer;
    map<string, vector<string>> allMoves;
    map<string, Pokemon> allPokemons;
    vector<std::vector<double>> typeEffectiveness;
    bool ifGameOver = false;
public:
    Game();
    void bAndP();
    void executeComputerMove(string computerMove, int playType);
    void loadPokemonFile(string pokemonFile);//load pokemon file
    void loadMoveFile(string moveFile);//load move file
    void loadGameFile(string gameFile);//load game file
    void ExecuteCommandFile(string testFile);//implement test case
    void Battle(string humanMove, string computerMove, int playType);//Battle command
    void Bag(string potion, string ownPokemon, string computerMove, int playType);//Bag command
    void pokemon(string ownPokemon, string computerMove, int playType);//Pokemon command
    void attackPokemon(string move, string target,int playType);
    void status(ostream& oStream = cout);//Status command
    void check(ostream& oStream = cout);//Check command
    bool checkIfAllFainted();//check if all fainted, also used for if game ended
    void run();//Run command
    double getTypeEffectiveness(string atkType, string defType);
    bool getifGameOver();

};

#endif // GAME_H
