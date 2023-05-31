#include <fstream>
#include <string>
#include <sstream>
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

// Intent: load move library, also set move attributes to pokemons moves
// Pre: file name
// Post: load move library
void Game::loadMoveFile(string moveFile)
{
    ifstream iFile("../MoveLib.txt");
    if(!iFile.is_open())
    {
        cout << "open MoveLib.txt failed\n";
        return;
    }

    string moveName; //name of move
    vector<string> moveAttributes; //vector that stores all the attributes
    string tempAttribute; //temporary attribute
    string lineOfAttributes; //store all of the attributes of a move, including all the white space
    stringstream ss; //string stream to parse lineOfAttributes

    //read in all the moves into std::map allMoves
    while (iFile >> moveName) { //read in move name

        //get all the line of attributes into lineOfAttributes
        getline(iFile, lineOfAttributes);
        iFile.ignore(1,'\n');

        moveAttributes.clear();
        ss.str(lineOfAttributes);
        while(ss >> tempAttribute) // parse lineOfAttributes
        {
            moveAttributes.push_back(tempAttribute);
        }

        //append the moves into std::map allMoves
        allMoves.insert(allMoves.end(),{moveName, moveAttributes});
    }

    std::map<string, vector<string>>::iterator iter; //allMoves map iterator

    //for human
    //assign the attributes to moves of the pokemons
    for (int var = 0; var < human.getPokemons().size(); ++var) {
        for (int i = 0; i < human.getPokemons().at(var).getMoves().size(); ++i) {
            moveName = human.getPokemons().at(var).getMoves()[i].getName();
            iter = allMoves.find(moveName);

            human.getPokemons().at(var).getMoves()[i].setType(iter->second.at(0));
            human.getPokemons().at(var).getMoves()[i].setPS(iter->second.at(1));
            human.getPokemons().at(var).getMoves()[i].setPower(stoi(iter->second.at(2)));
            human.getPokemons().at(var).getMoves()[i].setAccuracy(stoi(iter->second.at(3)));
            human.getPokemons().at(var).getMoves()[i].setPP(stoi(iter->second.at(4)));

            //if 6 attributes, the move has addtional effect. Assign if true;
            if(iter->second.size() == 6)
            {
                human.getPokemons().at(var).getMoves()[i].setCon(iter->second.at(5));
            }
        }
    }

    //for computer
    //assign the attributes to moves of the pokemons
    for (int var = 0; var < computer.getPokemons().size(); ++var) {
        for (int i = 0; i < computer.getPokemons().at(var).getMoves().size(); ++i) {
            moveName = computer.getPokemons().at(var).getMoves()[i].getName();
            iter = allMoves.find(moveName);

            computer.getPokemons().at(var).getMoves()[i].setType(iter->second.at(0));
            computer.getPokemons().at(var).getMoves()[i].setPS(iter->second.at(1));
            computer.getPokemons().at(var).getMoves()[i].setPower(stoi(iter->second.at(2)));
            computer.getPokemons().at(var).getMoves()[i].setAccuracy(stoi(iter->second.at(3)));
            computer.getPokemons().at(var).getMoves()[i].setPP(stoi(iter->second.at(4)));

            //if 6 attributes, the move has addtional effect. Assign if true;
            if(iter->second.size() == 6)
            {
                computer.getPokemons().at(var).getMoves()[i].setCon(iter->second.at(5));
            }
        }
    }
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

    //input player's (i.e human) game data
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

    //input computer's game data
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

