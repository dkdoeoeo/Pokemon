
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Game.h"

using namespace std;

Game game;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initIcon();
    initSound();
    initProgressBar();
    loadFiles();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initIcon()
{
    iconBlastoise = new QPixmap("./images/Blastoise.png");
    iconCharizard = new QPixmap("./images/Charizard.png");
    iconVenusaur = new QPixmap("./images/Venusaur.png");
    iconPotion = new QPixmap("./images/Potion.png");
    iconSuperPotion = new QPixmap("./images/SuperPotion.png");
    iconHyperPotion = new QPixmap("./images/HyperPotion.png");
    iconMaxPotion = new QPixmap("./images/MaxPotion.png");
    iconPAR = new QPixmap("./images/PAR.png");
    iconBRN = new QPixmap("./images/BRN.png");
    iconPSN = new QPixmap("./images/PSN.png");
    *iconBlastoise = iconBlastoise->scaled(150,150);
    *iconCharizard = iconCharizard->scaled(150,150);
    *iconVenusaur = iconVenusaur->scaled(150,150);
    *iconPotion = iconPotion->scaled(60,60);
    *iconSuperPotion = iconSuperPotion->scaled(60,60);
    *iconHyperPotion = iconHyperPotion->scaled(60,60);
    *iconMaxPotion = iconMaxPotion->scaled(60,60);
    *iconPAR = iconPAR->scaled(60,60);
    *iconBRN = iconBRN->scaled(60,60);
    *iconPSN = iconPSN->scaled(60,60);
    this->setStyleSheet("QWidget {"
                         "background-image: url(./images/Background.png);"
                         "background-repeat: no-repeat;"
                         "background-position: center;"
                         "}");
    this->setFixedSize(800, 500);
}

void MainWindow::initSound()
{
    startSound = new QSoundEffect;
    clickSound = new QSoundEffect;
    startSound->setSource(QUrl::fromLocalFile("./sounds/Bgm.wav"));
    clickSound->setSource(QUrl::fromLocalFile("./sounds/OpenCell.wav"));
    startSound->play();//plat BGM
    startSound->setLoopCount(100);//repeat play
}

void MainWindow::connectItem()
{
    Battle = ui->Battle;
    Pokemon = ui->Pokemon;
    Bag = ui->Bag;
    Run = ui->Run;
    playerName = ui->playerName;
    computerName = ui->computerName;
    playerPokemon = ui->playerPokemon;
    computerPokemon = ui->computerPokemon;
    playerCON = ui->playerCON;
    computerCON = ui->computerCON;
}

void MainWindow::loadFiles()
{
    game.loadPokemonFile("PokemonLib.txt");
    game.loadMoveFile("MoveLib.txt");
    game.loadGameFile("GameData.txt");
}

void MainWindow::initProgressBar()
{
    playerHp = ui->playerHp;
    computerHp = ui->computerHp;
    playerHp->setStyleSheet("QProgressBar {"
                      "    border: 1px solid gray;"
                      "    border-radius: 5px;"
                      "    background-color: black;"
                      "    text-align: center;"
                      "}"

                      "QProgressBar::chunk {"
                      "    background-color: red;"
                      "}");
    computerHp->setStyleSheet("QProgressBar {"
                            "    border: 1px solid gray;"
                            "    border-radius: 5px;"
                            "    background-color: black;"
                            "    text-align: center;"
                            "}"

                            "QProgressBar::chunk {"
                            "    background-color: red;"
                            "}");
}

void MainWindow::update()
{
    string playerPokemon = game.human.getPokemons()[game.human.selectPokemon].getName();
    string computerPokemon = game.computer.getPokemons()[game.computer.selectPokemon].getName();

    if(playerPokemon == "Venusaur")
    {

    }
    else if(playerPokemon == "Charizard")
    {

    }
    else if(playerPokemon == "Blastoise")
    {

    }

    if(computerPokemon == "Venusaur")
    {

    }
    else if(computerPokemon == "Charizard")
    {

    }
    else if(computerPokemon == "Blastoise")
    {

    }
}
