#include <fstream>
#include <string>
#include <random>
#include <sstream>
#include <algorithm>
#include "Game.h"
#define testMode 1
#define playMode 2
// Intent: Game Contructor
// Pre: none
// Post: init the type effecteiveness chart
Game::Game()
{
    typeEffectiveness =
        {
            {1,	1,	1,	1,	1,	((double)1/2),	1,	0,	((double)1/2),	1,	1,	1,	1,	1,	1,	1,	1,	1},
            {2,	1,	((double)1/2),	((double)1/2),	1,	2,	((double)1/2),	0,	2,	1,	1,	1,	1,	((double)1/2),	2,	1,	2,	((double)1/2)},
            {1,	2,	1,	1,	1,	((double)1/2),	2,	1,	((double)1/2),	1,	1,	2,	((double)1/2),	1,	1,	1,	1,	1},
            {1,	1,	1,	((double)1/2),	((double)1/2),	((double)1/2),	1,	((double)1/2),	0,	1,	1,	2,	1,	1,	1,	1,	1,	2},
            {1,	1,	0,	2,	1,	2,	((double)1/2),	1,	2,	2,	1,	((double)1/2),	2,	1,	1,	1,	1,	1},
            {1,	((double)1/2),	2,	1,	((double)1/2),	1,	2,	1,	((double)1/2),	2,	1,	1,	1,	1,	2,	1,	1,	1},
            {1,	((double)1/2),	((double)1/2),	((double)1/2),	1,	1,	1,	((double)1/2),	((double)1/2),	((double)1/2),	1,	2,	1,	2,	1,	1,	2,	((double)1/2)},
            {0,	1,	1,	1,	1,	1,	1,	2,	1,	1,	1,	1,	1,	2,	1,	1,	((double)1/2),	1},
            {1,	1,	1,	1,	1,	2,	1,	1,	((double)1/2),	((double)1/2),	((double)1/2),	1,	((double)1/2),	1,	2,	1,	1,	2},
            {1,	1,	1,	1,	1,	((double)1/2),	2,	1,	2,	((double)1/2),	((double)1/2),	2,	1,	1,	2,	((double)1/2),	1,	1},
            {1,	1,	1,	1,	2,	2,	1,	1,	1,	2,	((double)1/2),	((double)1/2),	1,	1,	1,	((double)1/2),	1,	1},
            { 1,	1,	((double)1/2),	((double)1/2),	2,	2,	((double)1/2),	1,	((double)1/2),	((double)1/2),	2,	((double)1/2),	1,	1,	1,	((double)1/2),	1,	1},
            {1,	1,	2,	1,	0,	1,	1,	1,	1,	1,	2,	((double)1/2),	((double)1/2),	1,	1,	((double)1/2),	1,	1},
            {1,	2,	1,	2,	1,	1,	1,	1,	((double)1/2),	1,	1,	1,	1,	((double)1/2),	1,	1,	0,	1},
            {1,	1,	2,	1,	2,	1,	1,	1,	((double)1/2),	((double)1/2),	((double)1/2),	2,	1,	1,	((double)1/2),	2,	1,	1},
            { 1,	1,	1,	1,	1,	1,	1,	1,	((double)1/2),	1,	1,	1,	1,	1,	1,	2,	1,	0},
            {1,	((double)1/2),	1,	1,	1,	1,	1,	2,	1,	1,	1,	1,	1,	2,	1,	1,	((double)1/2),	((double)1/2)},
            {1,	2,	1,	((double)1/2),	1,	1,	1,	1,	((double)1/2),	((double)1/2),	1,	1,	1,	1,	1,	2,	2,	1}
        };
}

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
            pokemon(ownPokemon, computerMove, testMode);
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

        moveAttributes.clear();
        ss.str(lineOfAttributes);
        ss.clear();
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

    for (int var = 0; var < numOfPokemons_Player; ++var)
    {
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
        for (int typecount = 0; typecount < iterPokemon->second.getTypes().size(); ++typecount) {
            human.getPokemons()[var].appendTypes(iterPokemon->second.getTypes().at(typecount));
        }


        //assign pokemons' moves attributes
        for (int i = 0; i < numOfplayerPokemonMove; ++i)
        {
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

    for (int var = 0; var < numOfPokemons_Comp; ++var)
    {
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

        for (int typecount = 0; typecount < iterPokemon->second.getTypes().size(); ++typecount) {
            computer.getPokemons()[var].appendTypes(iterPokemon->second.getTypes().at(typecount));
        }

        //assign pokemons' moves attributes
        for (int i = 0; i < numOfCompPokemonMove; ++i)
        {
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
    if(ifGameOver)
    {
        return;
    }

    if(human.getPokemons().at(human.getSelectPokemon()).getSpeed() < computer.getPokemons().at(computer.getSelectPokemon()).getSpeed())
    {
        attackPokemon(computerMove, "human",playType);
        attackPokemon(humanMove,"computer",playType);
    }
    else
    {
        attackPokemon(humanMove,"computer",playType);
        attackPokemon(computerMove, "human",playType);
    }



    bAndP();
}

// Intent: Battle command
// Pre: name of the potion, player’s Pokémon and opponent’s move, pokemon not fainted
// Post: heal pokemon
void Game::Bag(string potion, string ownPokemon, string computerMove, int playType)
{

    if(ifGameOver)
    {
        return;
    }

    if(playType == testMode)
    {
        Pokemon& selectedPokemon = *std::find_if(human.getPokemons().begin(),
                                                      human.getPokemons().end(),
                                                       [&](Pokemon& temp){return temp.getName() == ownPokemon;});
        if(selectedPokemon.getIfFainted())
        {
            return;
        }

        int pokemonMaxHp = (allPokemons.find(ownPokemon)->second.getHp());

        if(potion == "Potion" && human.ifHavePotion("Potion"))
        {
            cout << "You used a Potion!" << endl;
            cout << selectedPokemon.getName() << " had its Hp restored." << endl;
            if(selectedPokemon.getHp() + 20 > pokemonMaxHp)
            {
                selectedPokemon.setHp(pokemonMaxHp);
            }
            else// selectedPokemon.getHp() + 20 <= pokemonMaxHp
            {
                selectedPokemon.setHp(selectedPokemon.getHp() + 20);
            }
        }
        else if(potion == "SuperPotion" && human.ifHavePotion("SuperPotion"))
        {
            cout << "You used a Super Potion!" << endl;
            cout << selectedPokemon.getName() << " had its Hp restored." << endl;
            if(selectedPokemon.getHp() + 60 > pokemonMaxHp)
            {
                selectedPokemon.setHp(pokemonMaxHp);
            }
            else// selectedPokemon.getHp() + 60 <= pokemonMaxHp
            {
                selectedPokemon.setHp(selectedPokemon.getHp() + 60);
            }
        }
        else if(potion == "HyperPotion" && human.ifHavePotion("HyperPotion"))
        {
            cout << "You used a Hyper Potion!" << endl;
            cout << selectedPokemon.getName() << " had its Hp restored." << endl;
            if(selectedPokemon.getHp() + 120 > pokemonMaxHp)
            {
                selectedPokemon.setHp(pokemonMaxHp);
            }
            else// selectedPokemon.getHp() + 120 <= pokemonMaxHp
            {
                selectedPokemon.setHp(selectedPokemon.getHp() + 120);
            }
        }
        else if(potion == "MaxPotion" && human.ifHavePotion("MaxPotion"))
        {
            cout << "You used a Max Potion!" << endl;
            cout << selectedPokemon.getName() << " had its Hp restored." << endl;
            selectedPokemon.setHp(pokemonMaxHp);
        }
    }
    else if(playType == playMode)
    {
        Pokemon& selectedPokemon = *std::find_if(human.getPokemons().begin(),
                                                 human.getPokemons().end(),
                                                 [&](Pokemon& temp){return temp.getName() == ownPokemon;});
        if(selectedPokemon.getIfFainted())
        {
            return;
        }
        int pokemonMaxHp = (allPokemons.find(ownPokemon)->second.getHp());

        if(potion == "Potion" && human.ifHavePotion("Potion"))
        {
            human.usePotion();
            cout << "You used a Potion!" << endl;
            cout << selectedPokemon.getName() << " had its Hp restored." << endl;
            if(selectedPokemon.getHp() + 20 > pokemonMaxHp)
            {
                selectedPokemon.setHp(pokemonMaxHp);
            }
            else// selectedPokemon.getHp() + 20 <= pokemonMaxHp
            {
                selectedPokemon.setHp(selectedPokemon.getHp() + 20);
            }
        }
        else if(potion == "SuperPotion" && human.ifHavePotion("SuperPotion"))
        {
            human.useSuperPotion();
            cout << "You used a Super Potion!" << endl;
            cout << selectedPokemon.getName() << " had its Hp restored." << endl;
            if(selectedPokemon.getHp() + 60 > pokemonMaxHp)
            {
                selectedPokemon.setHp(pokemonMaxHp);
            }
            else// selectedPokemon.getHp() + 60 <= pokemonMaxHp
            {
                selectedPokemon.setHp(selectedPokemon.getHp() + 60);
            }
        }
        else if(potion == "HyperPotion" && human.ifHavePotion("HyperPotion"))
        {
            human.useHyperPotion();
            cout << "You used a Hyper Potion!" << endl;
            cout << selectedPokemon.getName() << " had its Hp restored." << endl;
            if(selectedPokemon.getHp() + 120 > pokemonMaxHp)
            {
                selectedPokemon.setHp(pokemonMaxHp);
            }
            else// selectedPokemon.getHp() + 120 <= pokemonMaxHp
            {
                selectedPokemon.setHp(selectedPokemon.getHp() + 120);
            }
        }
        else if(potion == "MaxPotion" && human.ifHavePotion("MaxPotion"))
        {
            human.useMaxPotion();
            cout << "You used a Max Potion!" << endl;
            cout << selectedPokemon.getName() << " had its Hp restored." << endl;
            selectedPokemon.setHp(pokemonMaxHp);
        }
    }


    attackPokemon(computerMove, "human", playType);

    bAndP();
}

// Intent: Pokemon command
// Pre: player’s Pokémon and opponent’s move
// Post: switch pokemon
void Game::pokemon(string ownPokemon, string computerMove, int playType)
{
    if(ifGameOver)
    {
        return;
    }

    //pokemon to swap to
    int pokemonToSwapIndex = -1;

    for (int var = 0; var < human.getPokemons().size(); ++var)
    {
        if(human.getPokemons().at(var).getName() == ownPokemon)
        {
            pokemonToSwapIndex = var;
            break;
        }
    }
    Pokemon& pokemonToSwap = human.getPokemons().at(pokemonToSwapIndex);

    //check if pokemonToSwap fainted or the same pokemon
    if(pokemonToSwap.getIfFainted() || pokemonToSwapIndex == human.getSelectPokemon())
    {
        return;
    }
    else
    {
        //<Pokémon>, switch out!
        //Come back!
        //Go! <Pokémon>!
        cout << human.getPokemons().at(human.getSelectPokemon()).getName() << " switch out!" << endl;
        cout << "Come back!" << endl;
        cout << "Go! " << pokemonToSwap.getName() << endl;
        human.setSelectPokemon(pokemonToSwapIndex);
    }

    attackPokemon(computerMove, "human", playType);

    bAndP();
}

// Intent: Status command
// Pre: no
// Post: output both sides pokemon status
void Game::status(ostream& oStream)
{
    //Pokémon hp PAR BRN PSN Pokémon hp PAR BRN PSN
    Pokemon& humanSelectPokemon = human.getPokemons().at(human.getSelectPokemon());
    Pokemon& computerSelectPokemon = computer.getPokemons().at(computer.getSelectPokemon());
    vector<string> statuses = {"PAR","BRN","PSN"};
    oStream << humanSelectPokemon.getName() << ' ' << (int)humanSelectPokemon.getHp();

    for (int var = 0; var < 3; ++var)
    {
        if(humanSelectPokemon.getCon(statuses[var]) > 0)
        {
            cout << ' ' << statuses[var];
        }
    }

    oStream << ' ' << computerSelectPokemon.getName() << ' ' << (int)computerSelectPokemon.getHp();

    for (int var = 0; var < 3; ++var)
    {
        if(computerSelectPokemon.getCon(statuses[var]) > 0)
        {
            cout << ' ' << statuses[var];
        }
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
    for (int var = 0; var < numOfMoves; ++var)
    {
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
    exit(0);
}

// Intent: get damage bonus corresponding to the types
// Pre: Types exist
// Post: returns the damage bonus
double Game::getTypeEffectiveness(string atkType, string defType)
{
    vector<string> types =
    {
        "Normal", "Fighting", "Flying", "Poison", "Ground", "Rock",
        "Bug", "Ghost", "Steel", "Fire", "Water", "Grass",
        "Electric", "Psychic", "Ice", "Dragon", "Dark", "Fairy"
    };

    int row = 0;
    int col = 0;

    for (int var = 0; var < types.size(); ++var)
    {
        if(types[var] == atkType)
        {
            row = var;
        }

        if(types[var] == defType)
        {
            col = var;
        }
    }

    return typeEffectiveness[row][col];

}

// Intent: attack current selected pokemon with specified move, and reduced pp
// Pre: target: "human" or "computer"
// Post: decrease pokemon's hp by damage, and check if fainted, and reduce pp
void Game::attackPokemon(string move, string target,int playType)
{
    if(getifGameOver())
    {
        return;
    }
    Pokemon& humanSelectedPokemon = human.getPokemons().at(human.getSelectPokemon());
    Pokemon& computerSelectedPokemon = computer.getPokemons().at(computer.getSelectPokemon());

    //for attacking human
    if(target == "human")
    {
        if(computerSelectedPokemon.getIfFainted())
        {
            return;
        }
        //check if paralyzed
        bool ifPara = false;
        int pararounds = computerSelectedPokemon.getCon("PAR");
        if(pararounds > 0)
        {
            ifPara = rand() % 100 < 25;
            if(playType == testMode){
                ifPara = true;
            }

        }

        if(ifPara)
        {
            cout << "Opposing " << computerSelectedPokemon.getName() << " is paralyzed!" << endl;
            cout << "It can't move!" << endl;
            return;
        }

        Move& selectedMove = *std::find_if(computerSelectedPokemon.getMoves().begin(),
                                           computerSelectedPokemon.getMoves().end(),
                                           [&](Move& tempCompMove){ return tempCompMove.getName() == move;});
        //if hit
        bool ifHit = false;

        if(playType == testMode)
        {
            ifHit = true;
        }
        else
        {
            ifHit = rand() % 100 < selectedMove.getAccuracy();
        }

        if(ifHit && selectedMove.getPP() > 0)
        {
            selectedMove.setPP(selectedMove.getPP() - 1);
            cout << "The opposing " << computerSelectedPokemon.getName() << " used " << move << '!' << endl;
            int damage = 0; //total damage
            bool ifCritical = rand() % 24 < 1; //if critical
            double critical = 1; // critical damage
            double atkDefRatio = 0; // attack defense ratio
            double stab = 1; //STAB
            double totalTypeEffectiveness = 1; //total type effectiveness


            //calculate type Effectiveness
            for (int var = 0; var < humanSelectedPokemon.getTypes().size(); ++var)
            {
                totalTypeEffectiveness *= getTypeEffectiveness(selectedMove.getType(),humanSelectedPokemon.getTypes()[var]);
            }

            //output how effective
            if(selectedMove.getPower() != 0){

                if(totalTypeEffectiveness >= 2)
                {
                    cout << "It's super effective!" << endl;
                }
                else if(totalTypeEffectiveness >= 1/2 && totalTypeEffectiveness > 0)
                {
                    cout << "It's not very effective..." << endl;
                }
                else // if (totalTypeEffectiveness <= 0)
                {
                    cout << "It's not effective!" << endl;
                }
            }

            //calculate attack/defense ratio
            if(selectedMove.getPS() == "Special")
            {
                atkDefRatio = (double)computerSelectedPokemon.getSpAtk() / humanSelectedPokemon.getSpDef();
            }
            else // if(selectedMove.getPS() == "Physical")
            {
                atkDefRatio = (double)computerSelectedPokemon.getAtk() / humanSelectedPokemon.getDef();
            }

            //determine critical rate
            if(playType == testMode)
            {
                ifCritical = false;
            }

            //determine critical damage
            if(ifCritical){
                cout << "A critical hit!" << endl;

                if(playType == testMode)
                {
                    critical = 1;
                }
                else if(playType == playMode)
                {
                    critical = 1.5;
                }
            }

            //determine stab
            for (int var = 0; var < computerSelectedPokemon.getTypes().size(); ++var)
            {
                if(selectedMove.getType() == computerSelectedPokemon.getTypes()[var])
                {
                    stab = 1.5;
                    break;
                }
            }
            if(selectedMove.getPower() == 0)
            {
                damage = 0;
            }
            else
            {
                damage = (((double)110/250) * selectedMove.getPower() * atkDefRatio + 2) * critical * stab * totalTypeEffectiveness;
            }



            //check if fainted
            if(humanSelectedPokemon.getHp() - damage <= 0)
            {
                cout << humanSelectedPokemon.getName() << " has fainted!" << endl;
                humanSelectedPokemon.setHp(0);
                humanSelectedPokemon.setIfFainted(true);

                if(checkIfAllFainted())
                {
                    return;
                }
                return;
            }
            else
            {
                humanSelectedPokemon.setHp(humanSelectedPokemon.getHp() - damage);
            }

            //if addtional effect
            bool ifAdditionalEffect = rand() % 100 < selectedMove.getAccuracy();
            if(playType == testMode)
            {
                ifAdditionalEffect = true;
            }
            if(ifAdditionalEffect && !selectedMove.getCon().empty())
            {

                if(selectedMove.getCon() == "PAR" && humanSelectedPokemon.getCon(selectedMove.getCon()) == 0)
                {
                    humanSelectedPokemon.setSpeed(humanSelectedPokemon.getSpeed() * (0.5));
                }

                humanSelectedPokemon.setCon(selectedMove.getCon(), 10000000);

                if(selectedMove.getCon() == "PAR")
                {
                    cout << humanSelectedPokemon.getName() << " is paralyzed, so it may be unable to move!" << endl;
                }
                else if(selectedMove.getCon() == "BRN")
                {
                    cout << humanSelectedPokemon.getName() << " is burned!" << endl;
                }
                else if(selectedMove.getCon() == "PSN")
                {
                    cout << humanSelectedPokemon.getName() << " is Poisoned!" << endl;
                }
            }

        }
        else
        {
            cout << humanSelectedPokemon.getName() << " avoided the Attack!"<< endl;
        }



    }
    else if(target == "computer") // for attacking computer
    {
        if(humanSelectedPokemon.getIfFainted())
        {
            return;
        }
        //check if paralyzed
        bool ifPara = false;
        int pararounds = humanSelectedPokemon.getCon("PAR");
        if(pararounds > 0)
        {
            ifPara = rand() % 100 < 25;
            if(playType == testMode){
                ifPara = true;
            }
        }

        if(ifPara)
        {
            cout << humanSelectedPokemon.getName() << " is paralyzed!" << endl;
            cout << "It can't move!" << endl;
            return;
        }

        Move& selectedMove = *std::find_if(humanSelectedPokemon.getMoves().begin(),
                                           humanSelectedPokemon.getMoves().end(),
                                           [&](Move& tempCompMove){ return tempCompMove.getName() == move;});
        //if hit
        bool ifHit = false;
        if(playType == testMode)
        {
            ifHit = true;
        }
        else
        {
            ifHit = rand() % 100 < selectedMove.getAccuracy();
        }

        if(ifHit && selectedMove.getPP() > 0){
            selectedMove.setPP(selectedMove.getPP() - 1);
            cout << humanSelectedPokemon.getName() << " used " << move << '!' << endl;
            int damage = 0; //total damage
            bool ifCritical = rand() % 24 < 1; //if critical
            double critical = 1; // critical damage
            double atkDefRatio = 0; // attack defense ratio
            double stab = 1; //STAB
            double totalTypeEffectiveness = 1; //total type effectiveness


            //calculate type Effectiveness
            for (int var = 0; var < computerSelectedPokemon.getTypes().size(); ++var) {
                totalTypeEffectiveness *= getTypeEffectiveness(selectedMove.getType(),computerSelectedPokemon.getTypes()[var]);
            }
            //output how effective
            if(totalTypeEffectiveness >= 2)
            {
                cout << "It's super effective!" << endl;
            }
            else if(totalTypeEffectiveness >= 1/2 && totalTypeEffectiveness > 0)
            {
                cout << "It's not very effective..." << endl;
            }
            else // if (totalTypeEffectiveness <= 0)
            {
                cout << "It's not effective!" << endl;
            }

            //calculate attack/defense ratio
            if(selectedMove.getPS() == "Special")
            {
                atkDefRatio = (double)humanSelectedPokemon.getSpAtk() / computerSelectedPokemon.getSpDef();
            }
            else // if(selectedMove.getPS() == "Physical")
            {
                atkDefRatio = (double)humanSelectedPokemon.getAtk() / computerSelectedPokemon.getDef();
            }

            //determine critical rate
            if(playType == testMode)
            {
                ifCritical = false;
            }
            //determine critical damage
            if(ifCritical){
                cout << "A critical hit!" << endl;
                if(playType == testMode)
                {
                    critical = 1;
                }
                else if(playType == playMode)
                {
                    critical = 1.5;
                }
            }
            //determine stab
            for (int var = 0; var < humanSelectedPokemon.getTypes().size(); ++var) {
                if(selectedMove.getType() == humanSelectedPokemon.getTypes()[var])
                {
                    stab = 1.5;
                    break;
                }
            }
            if(selectedMove.getPower() == 0)
            {
                damage = 0;
            }
            else
            {
                damage = (((double)110/250) * selectedMove.getPower() * atkDefRatio + 2) * critical * stab * totalTypeEffectiveness;
            }
            //check if fainted
            if(computerSelectedPokemon.getHp() - damage <= 0)
            {
                cout << "Opposing " << computerSelectedPokemon.getName() << " has fainted!" << endl;
                computerSelectedPokemon.setHp(0);
                computerSelectedPokemon.setIfFainted(true);

                if(checkIfAllFainted())
                {
                    return;
                }
                return;

            }
            else
            {
                computerSelectedPokemon.setHp(computerSelectedPokemon.getHp() - damage);
            }

            //if addtional effect
            bool ifAdditionalEffect = rand() % 100 < selectedMove.getAccuracy();
            if(playType == testMode)
            {
                ifAdditionalEffect = true;
            }
            if(ifAdditionalEffect && !selectedMove.getCon().empty())
            {

                if(selectedMove.getCon() == "PAR" && computerSelectedPokemon.getCon(selectedMove.getCon()) == 0)
                {
                    computerSelectedPokemon.setSpeed(computerSelectedPokemon.getSpeed() * (0.5));
                }

                computerSelectedPokemon.setCon(selectedMove.getCon(), 10000000);

                if(selectedMove.getCon() == "PAR")
                {
                    cout << "Opposing " << computerSelectedPokemon.getName() << " is paralyzed, so it may be unable to move!" << endl;
                }
                else if(selectedMove.getCon() == "BRN")
                {
                    cout << "Opposing " << computerSelectedPokemon.getName() << " is burned!" << endl;
                }
                else if(selectedMove.getCon() == "PSN")
                {
                    cout << "Opposing " << computerSelectedPokemon.getName() << " is Poisoned!" << endl;
                }
            }

        }
        else
        {
            cout << "Opposing " << computerSelectedPokemon.getName() << " avoided the Attack!"<< endl;
        }
    }
}

// Intent: Apply all the B&P effects
// Pre: if pokemon has B&P effect
// Post: B&P effects applied
void Game::bAndP()
{
    if(getifGameOver())
    {
        return;
    }
    vector<string> statuses = {"BRN", "PSN", "PAR"};
    int computerPokemonMaxHp = allPokemons.find(computer.getPokemons().at(computer.getSelectPokemon()).getName())->second.getHp();
    int humanPokemonMaxHp = allPokemons.find(human.getPokemons().at(human.getSelectPokemon()).getName())->second.getHp();
    Pokemon& humanSelectedPokemon = human.getPokemons().at(human.getSelectPokemon());
    Pokemon& computerSelectedPokemon = computer.getPokemons().at(computer.getSelectPokemon());
    int damage = 0;

    if(humanSelectedPokemon.getIfFainted())
    {
        for (int num = 0; num < human.getPokemons().size(); ++num) {
            if(!human.getPokemons().at(num).getIfFainted())
            {
                human.setSelectPokemon(num);
                break;
            }
        }

    }
    if(computerSelectedPokemon.getIfFainted())
    {
        for (int num = 0; num < computer.getPokemons().size(); ++num) {
            if(!computer.getPokemons().at(num).getIfFainted())
            {
                computer.setSelectPokemon(num);
                break;
            }
        }
    }

    //human
    //burn
    if(human.getPokemons().at(human.getSelectPokemon()).getCon("BRN") > 0)
    {
        humanSelectedPokemon.setCon("BRN",humanSelectedPokemon.getCon("BRN") - 1);
        damage = humanPokemonMaxHp / 16;
        cout << humanSelectedPokemon.getName() << " is hurt by its burn!" << endl;
        if(humanSelectedPokemon.getHp() - damage <= 0)
        {
            cout << humanSelectedPokemon.getName() << " has fainted!" << endl;
            humanSelectedPokemon.setHp(0);
            for (int num = 0; num < human.getPokemons().size(); ++num) {
                if(!human.getPokemons().at(num).getIfFainted())
                {
                    human.setSelectPokemon(num);
                    break;
                }
            }
            if(checkIfAllFainted())
            {
                return;
            }

        }
        else
        {
            humanSelectedPokemon.setHp(humanSelectedPokemon.getHp() - damage);
        }
    }
    //Poison
    if(human.getPokemons().at(human.getSelectPokemon()).getCon("PSN") > 0)
    {
        humanSelectedPokemon.setCon("PSN",humanSelectedPokemon.getCon("PSN") - 1);
        damage = humanPokemonMaxHp / 16;
        cout << humanSelectedPokemon.getName() << " is hurt by its poison!" << endl;
        if(humanSelectedPokemon.getHp() - damage <= 0)
        {
            cout << humanSelectedPokemon.getName() << " has fainted!" << endl;
            humanSelectedPokemon.setHp(0);
            for (int num = 0; num < human.getPokemons().size(); ++num) {
                if(!human.getPokemons().at(num).getIfFainted())
                {
                    human.setSelectPokemon(num);
                    break;
                }
            }
            if(checkIfAllFainted())
            {
                return;
            }

        }
        else
        {
            humanSelectedPokemon.setHp(humanSelectedPokemon.getHp() - damage);
        }
    }
    //Paralysis
    if(human.getPokemons().at(human.getSelectPokemon()).getCon("PAR") > 0)
    {

        humanSelectedPokemon.setCon("PSN",humanSelectedPokemon.getCon("PSN") - 1);
        if(humanSelectedPokemon.getCon("PSN") == 0)
        {
            int originalSpeed = allPokemons.find(human.getPokemons().at(human.getSelectPokemon()).getName())->second.getSpeed();
            humanSelectedPokemon.setSpeed(originalSpeed);
        }
    }


    //computer
    //BURN
    if(computer.getPokemons().at(computer.getSelectPokemon()).getCon("BRN") > 0)
    {
        computerSelectedPokemon.setCon("BRN",computerSelectedPokemon.getCon("BRN") - 1);
        damage = computerPokemonMaxHp / 16;
        cout << "Opposing " << computerSelectedPokemon.getName() << " is hurt by its burn!" << endl;
        if(computerSelectedPokemon.getHp() - damage <= 0)
        {
            cout << "Opposing " << computerSelectedPokemon.getName() << " has fainted!" << endl;
            computerSelectedPokemon.setHp(0);
            for (int num = 0; num < computer.getPokemons().size(); ++num) {
                if(!computer.getPokemons().at(num).getIfFainted())
                {
                    computer.setSelectPokemon(num);
                    break;
                }
            }
            if(checkIfAllFainted())
            {
                return;
            }


        }
        else
        {
            computerSelectedPokemon.setHp(computerSelectedPokemon.getHp() - damage);
        }
    }
    //Poison
    if(computer.getPokemons().at(computer.getSelectPokemon()).getCon("PSN") > 0)
    {
        computerSelectedPokemon.setCon("PSN",computerSelectedPokemon.getCon("PSN") - 1);
        damage = computerPokemonMaxHp / 16;
        cout << "Opposing " << computerSelectedPokemon.getName() << " is hurt by its poison!" << endl;
        if(computerSelectedPokemon.getHp() - damage <= 0)
        {
            cout << "Opposing " << computerSelectedPokemon.getName() << " has fainted!" << endl;
            computerSelectedPokemon.setHp(0);
            for (int num = 0; num < computer.getPokemons().size(); ++num) {
                if(!computer.getPokemons().at(num).getIfFainted())
                {
                    computer.setSelectPokemon(num);
                    break;
                }
            }
            if(checkIfAllFainted())
            {
                return;
            }

        }
        else
        {
            computerSelectedPokemon.setHp(computerSelectedPokemon.getHp() - damage);
        }
    }
    //Paralysis
    if(computer.getPokemons().at(computer.getSelectPokemon()).getCon("PAR") > 0)
    {
        computerSelectedPokemon.setCon("PSN",computerSelectedPokemon.getCon("PSN") - 1);
        if(computerSelectedPokemon.getCon("PSN") == 0)
        {
            int originalSpeed = allPokemons.find(computer.getPokemons().at(computer.getSelectPokemon()).getName())->second.getSpeed();
            computerSelectedPokemon.setSpeed(originalSpeed);
        }
    }


}

// Intent: check if all fainted
// Pre: none
// Post: gameOver if all fainted
bool Game::checkIfAllFainted()
{
    bool ifAllFainted = true;
    for (Pokemon& iter : human.getPokemons()) {
        if(!iter.getIfFainted())
        {
            ifAllFainted = false;
            break;
        }
    }

    if(ifAllFainted)
    {
        cout << "You Lose!" << endl;
        ifGameOver = true;
        return true;
    }

    ifAllFainted = true;

    for (Pokemon& iter : computer.getPokemons()) {
        if(!iter.getIfFainted())
        {
            ifAllFainted = false;
            break;
        }
    }

    if(ifAllFainted)
    {
        cout << "You Win!" << endl;
        ifGameOver = true;
        return true;
    }

    return false;
}

// Intent: get if game over
// Pre: none
// Post: return if game over
bool Game::getifGameOver()
{
    return ifGameOver;
}
