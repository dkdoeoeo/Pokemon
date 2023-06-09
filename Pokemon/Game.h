
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Pokemon.h"
#include <map>
#include "Player.h"
#include <QString>
#define testMode 1
#define playMode 2
#define playerWin 1
#define computerWin 2

using namespace std;

class Game
{
public:
    Player human;
    Player computer;
    map<string, vector<string>> allMoves;
    map<string, Pokemon> allPokemons;
    vector<std::vector<double>> typeEffectiveness;
    bool ifGameOver = false;
    int whoWin = 0;
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
    void split(string Words[], QString Name);//to split Qbject name
};

#endif // GAME_H
