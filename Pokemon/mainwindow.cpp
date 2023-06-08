
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
    //iconBackground = new QPixmap("./images/Background.png");
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

void MainWindow::loadFiles()
{
    game.loadPokemonFile("PokemonLib.txt");
    game.loadMoveFile("MoveLib.txt");
    game.loadGameFile("GameData.txt");
}
