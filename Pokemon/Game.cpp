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
    ifstream iFile;
    iFile.open(testFile.c_str());
    if(!iFile.is_open())
    {
        cout << "open " << testFile << " failed\n";
        return;
    }

    string command;

    while(iFile >> command)
    {
        if(command == "PokemonLib.txt")
        {
            loadPokemonFile(command);
        }
        else if(command == "MoveLib.txt")
        {
            loadMoveFile(command);
        }
        else if(command == "GameData.txt")
        {
            loadGameFile(command);
        }
        else if(command == "Battle")
        {
            string humanMove, computerMove;
            iFile >> humanMove >> computerMove;
            Battle(humanMove, computerMove, testMode);
        }
        else if(command == "Bag")
        {
            string potion, ownPokemon, computerMove;
            iFile >> potion >> ownPokemon >> computerMove;
            Bag(potion, ownPokemon, computerMove, testMode);
        }
        else if(command == "Pokemon")
        {
            string ownPokemon, computerMove;
            iFile >> ownPokemon >> computerMove;
            pokemon(ownPokemon, computerMove);
        }
        else if(command == "Status")
        {
            status();
        }
        else if(command == "Check")
        {
            check();
        }
        else if(command == "Run")
        {
            run();
        }
    }
}

// Intent: load pokemon library
// Pre: file name
// Post: load pokemon library
void Game::loadPokemonFile(string pokemonFile)
{
    ifstream iFile(pokemonFile.c_str());
    if(!iFile.is_open())
    {
        cout << "open " << pokemonFile << " failed\n";
        return;
    }

    string pokemonName; //pokemon name
    int pokemonAttribute = 0; //pokemon attribute
    string pokemonType; //pokemon type
    int numOfType = 0; //number of types

    while (iFile >> pokemonName) {

        //read in name
        Pokemon tempPokemon;
        tempPokemon.setName(pokemonName);

        //read in type
        iFile >> numOfType;
        tempPokemon.resizeTypes(numOfType);
        for (int var = 0; var < numOfType; ++var) {
            iFile >> pokemonType;
            tempPokemon.appendTypes(pokemonType);
        }

        //read in leftover attributes
        for (int var = 0; var < 6; ++var) {
            iFile >> pokemonAttribute;

            switch (var) {
            case 0:
                tempPokemon.setHp(pokemonAttribute);
                break;
            case 1:
                tempPokemon.setAtk(pokemonAttribute);
                break;
            case 2:
                tempPokemon.setDef(pokemonAttribute);
                break;
            case 3:
                tempPokemon.setSpAtk(pokemonAttribute);
                break;
            case 4:
                tempPokemon.setSpDef(pokemonAttribute);
                break;
            case 5:
                tempPokemon.setSpeed(pokemonAttribute);
                break;
            }
        }

        //append pokemon to std::map allPokemon;
        allPokemons.insert(allPokemons.end(), {pokemonName, tempPokemon});
    }

    iFile.close();
}

// Intent: load move library, also set move attributes to pokemons moves
// Pre: file name
// Post: load move library
void Game::loadMoveFile(string moveFile)
{
    ifstream iFile(moveFile.c_str());
    if(!iFile.is_open())
    {
        cout << "open " << moveFile << " failed\n";
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

    iFile.close();
}

// Intent: load game data, number of pokemons, number of moves, name of moves,
// Pre: file name
// Post: load game data
void Game::loadGameFile(string gameFile)
{
    ifstream iFile(gameFile.c_str());
    if(!iFile.is_open())
    {
        cout << "open " << gameFile << " failed\n";
        return;
    }

    int numOfPokemons_Player = 0;
    int numOfPokemons_Comp = 0;
    int numOfplayerPokemonMove = 0;
    int numOfCompPokemonMove = 0;
    string pokemonMove;
    string pokemonName;

    //input player's (i.e human) game data
    //assign the attributes to pokemons and the moves of the pokemons
    iFile >> numOfPokemons_Player;
    human.resizePokemons(numOfPokemons_Player);

    std::map<string, vector<string>>::iterator iterMove; //allMoves map iterator
    std::map<string, Pokemon>::iterator iterPokemon; //allMoves map iterator

    for (int var = 0; var < numOfPokemons_Player; ++var) {
        iFile >> pokemonName;
        iFile >> numOfplayerPokemonMove;
        //assign pokemon attributes
        iterPokemon = allPokemons.find(pokemonName);
        human.getPokemons()[var].setName(pokemonName);
        human.getPokemons()[var].setHp(iterPokemon->second.getHp());
        human.getPokemons()[var].setDef(iterPokemon->second.getDef());
        human.getPokemons()[var].setAtk(iterPokemon->second.getAtk());
        human.getPokemons()[var].setSpAtk(iterPokemon->second.getSpAtk());
        human.getPokemons()[var].setSpDef(iterPokemon->second.getSpDef());
        human.getPokemons()[var].setSpeed(iterPokemon->second.getSpeed());

        //assign pokemons' moves attributes
        for (int i = 0; i < numOfplayerPokemonMove; ++i) {
            iFile >> pokemonMove;
            Move curMove;
            curMove.setName(pokemonMove);
            human.getPokemons()[var].appendMoves(curMove);
            iterMove = allMoves.find(pokemonMove);

            human.getPokemons().at(var).getMoves()[i].setType(iterMove->second.at(0));
            human.getPokemons().at(var).getMoves()[i].setPS(iterMove->second.at(1));
            human.getPokemons().at(var).getMoves()[i].setPower(stoi(iterMove->second.at(2)));
            human.getPokemons().at(var).getMoves()[i].setAccuracy(stoi(iterMove->second.at(3)));
            human.getPokemons().at(var).getMoves()[i].setPP(stoi(iterMove->second.at(4)));

            //if 6 attributes, the move has addtional effect. Assign if true;
            if(iterMove->second.size() == 6)
            {
                human.getPokemons().at(var).getMoves()[i].setCon(iterMove->second.at(5));
            }
        }

    }

    //input computer's game data
    //assign the attributes to pokemons and the moves of the pokemons
    iFile >> numOfPokemons_Comp;
    computer.resizePokemons(numOfPokemons_Comp);

    for (int var = 0; var < numOfPokemons_Comp; ++var) {
        iFile >> pokemonName;
        iFile >> numOfCompPokemonMove;
        //assign pokemon attributes
        iterPokemon = allPokemons.find(pokemonName);
        computer.getPokemons()[var].setName(pokemonName);
        computer.getPokemons()[var].setHp(iterPokemon->second.getHp());
        computer.getPokemons()[var].setDef(iterPokemon->second.getDef());
        computer.getPokemons()[var].setAtk(iterPokemon->second.getAtk());
        computer.getPokemons()[var].setSpAtk(iterPokemon->second.getSpAtk());
        computer.getPokemons()[var].setSpDef(iterPokemon->second.getSpDef());
        computer.getPokemons()[var].setSpeed(iterPokemon->second.getSpeed());

        //assign pokemons' moves attributes
        for (int i = 0; i < numOfCompPokemonMove; ++i) {
            iFile >> pokemonMove;
            Move curMove;
            curMove.setName(pokemonMove);
            computer.getPokemons()[var].appendMoves(curMove);

            iterMove = allMoves.find(pokemonMove);
            computer.getPokemons().at(var).getMoves()[i].setType(iterMove->second.at(0));
            computer.getPokemons().at(var).getMoves()[i].setPS(iterMove->second.at(1));
            computer.getPokemons().at(var).getMoves()[i].setPower(stoi(iterMove->second.at(2)));
            computer.getPokemons().at(var).getMoves()[i].setAccuracy(stoi(iterMove->second.at(3)));
            computer.getPokemons().at(var).getMoves()[i].setPP(stoi(iterMove->second.at(4)));

            //if 6 attributes, the move has addtional effect. Assign if true;
            if(iterMove->second.size() == 6)
            {
                computer.getPokemons().at(var).getMoves()[i].setCon(iterMove->second.at(5));
            }
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
void Game::status(ostream& oStream)
{
    //Pokémon hp PAR BRN PSN Pokémon hp PAR BRN PSN
    Pokemon& humanSelectPokemon = human.getPokemons().at(human.getSelectPokemon());
    Pokemon& computerSelectPokemon = computer.getPokemons().at(computer.getSelectPokemon());

    oStream << humanSelectPokemon.getName() << ' ' << humanSelectPokemon.getHp();
    if(!humanSelectPokemon.getCon().empty())
    {
        oStream << ' ' << humanSelectPokemon.getCon();
    }

    oStream << computerSelectPokemon.getName() << ' ' << computerSelectPokemon.getHp();
    if(!computerSelectPokemon.getCon().empty())
    {
        oStream << ' ' << computerSelectPokemon.getCon();
    }

    oStream << endl;
}

// Intent: Check command
// Pre: no
// Post: output current pokemon moves and PP
void Game::check(ostream& oStream)
{
    //number of moves of the selected pokemon
    int numOfMoves = human.getPokemons().at(human.getSelectPokemon()).getMoves().size();

    //selected pokemon
    Pokemon& humanSelectPokemon = human.getPokemons().at(human.getSelectPokemon());

    //iterate through the moves, then output pokemon moves and pp
    for (int var = 0; var < numOfMoves; ++var) {

        oStream << humanSelectPokemon.getMoves().at(var).getName()
                << ' ' << humanSelectPokemon.getMoves().at(var).getPP();

        if(var != numOfMoves - 1)
        {
            oStream << ' ';
        }
    }

    oStream << endl;
}

// Intent: Run command
// Pre: no
// Post: quit game
void Game::run()
{

}

