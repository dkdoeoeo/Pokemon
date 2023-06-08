
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

Game game;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand(time(NULL));
    ui->setupUi(this);
    initIcon();
    initSound();
    initProgressBar();
    loadFiles();
    connectItem();
    update();
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
    playerHpText = ui->playerHpText;
    computerHpText = ui->computerHpText;
    playerPSN = ui->playerPSN;
    playerBRN = ui->playerBRN;
    playerPAR = ui->playerPAR;
    computerPSN = ui->computerPSN;
    computerBRN = ui->computerBRN;
    computerPAR = ui->computerPAR;
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
    QFont font;
    font.setPointSize(12);  // 設定字體大小為 12
    string player = game.human.getPokemons()[game.human.selectPokemon].getName();
    string computer = game.computer.getPokemons()[game.computer.selectPokemon].getName();
    //set player pokemon hp
    playerHp->setRange(0, game.allPokemons.find(player)->second.getHp());
    playerHp->setValue(game.human.getPokemons()[game.human.selectPokemon].getHp());
    QString playerHpStatue = QString::number(game.human.getPokemons()[game.human.selectPokemon].getHp())
                             + "/" + QString::number(game.allPokemons.find(player)->second.getHp());
    playerHpText->setText(playerHpStatue);
    playerHpText->setFont(font);
    playerHpText->setAlignment(Qt::AlignCenter);
    //set computer pokemon hp
    computerHp->setRange(0, game.allPokemons.find(computer)->second.getHp());
    computerHp->setValue(game.computer.getPokemons()[game.computer.selectPokemon].getHp());
    QString computerHpStatue = QString::number(game.computer.getPokemons()[game.computer.selectPokemon].getHp())
                             + "/" + QString::number(game.allPokemons.find(computer)->second.getHp());
    computerHpText->setText(computerHpStatue);
    computerHpText->setFont(font);
    computerHpText->setAlignment(Qt::AlignCenter);

    //set player pokemon name and icon
    if(player == "Venusaur")
    {
        ui->playerName->setText("Venusaur");
        ui->playerName->setAlignment(Qt::AlignCenter);
        ui->playerName->setFont(font);
        ui->playerPokemon->setPixmap(*iconVenusaur);
        ui->playerPokemon->setAlignment(Qt::AlignCenter);
    }
    else if(player == "Charizard")
    {
        ui->playerName->setText("Charizard");
        ui->playerName->setAlignment(Qt::AlignCenter);
        ui->playerName->setFont(font);
        ui->playerPokemon->setPixmap(*iconCharizard);
        ui->playerPokemon->setAlignment(Qt::AlignCenter);
    }
    else if(player == "Blastoise")
    {
        ui->playerName->setText("Blastoise");
        ui->playerName->setAlignment(Qt::AlignCenter);
        ui->playerName->setFont(font);
        ui->playerPokemon->setPixmap(*iconBlastoise);
        ui->playerPokemon->setAlignment(Qt::AlignCenter);
    }

    //set computer pokemon name and icon
    if(computer == "Venusaur")
    {
        ui->computerName->setText("Venusaur");
        ui->computerName->setAlignment(Qt::AlignCenter);
        ui->computerName->setFont(font);
        ui->computerPokemon->setPixmap(*iconVenusaur);
        ui->computerPokemon->setAlignment(Qt::AlignCenter);
    }
    else if(computer == "Charizard")
    {
        ui->computerName->setText("Charizard");
        ui->computerName->setAlignment(Qt::AlignCenter);
        ui->computerName->setFont(font);
        ui->computerPokemon->setPixmap(*iconCharizard);
        ui->computerPokemon->setAlignment(Qt::AlignCenter);
    }
    else if(computer == "Blastoise")
    {
        ui->computerName->setText("Blastoise");
        ui->computerName->setAlignment(Qt::AlignCenter);
        ui->computerName->setFont(font);
        ui->computerPokemon->setPixmap(*iconBlastoise);
        ui->computerPokemon->setAlignment(Qt::AlignCenter);
    }

    //set player pokemon PAR
    if(game.human.getPokemons()[game.human.selectPokemon].getCon("PAR") != 0)
    {
        cout << game.human.getPokemons()[game.human.selectPokemon].getCon("PAR")<<endl;
        cout << game.human.getPokemons()[game.human.selectPokemon].getCon("BRN")<<endl;
        cout << game.human.getPokemons()[game.human.selectPokemon].getCon("PSN")<<endl;
        playerPAR->setPixmap(*iconPAR);}
    else
        playerPAR->clear();

    //set player pokemon BRN
    if(game.human.getPokemons()[game.human.selectPokemon].getCon("BRN") != 0)
        playerBRN->setPixmap(*iconBRN);
    else
        playerBRN->clear();

    //set player pokemon PSN
    if(game.human.getPokemons()[game.human.selectPokemon].getCon("PSN") != 0)
        playerPSN->setPixmap(*iconPSN);
    else
        playerPSN->clear();

    //set computer pokemon PAR
    if(game.computer.getPokemons()[game.computer.selectPokemon].getCon("PAR") != 0)
        computerPAR->setPixmap(*iconPAR);
    else
        computerPAR->clear();

    //set computer pokemon BRN
    if(game.computer.getPokemons()[game.computer.selectPokemon].getCon("BRN") != 0)
        computerBRN->setPixmap(*iconBRN);
    else
        computerBRN->clear();

    //set computer pokemon PSN
    if(game.computer.getPokemons()[game.computer.selectPokemon].getCon("PSN") != 0)
        computerPSN->setPixmap(*iconPSN);
    else
        computerPSN->clear();
}

void MainWindow::on_Battle_clicked()
{

}

void MainWindow::on_Pokemon_clicked()
{
    QDialog *dialog = new QDialog(this);
    dialog->setWindowFlags(dialog->windowFlags() & ~Qt::WindowCloseButtonHint);
    dialog->setWindowTitle("Pokemon");
    QHBoxLayout *layout = new QHBoxLayout(dialog);

    //set Venusaur
    QPushButton *buttonVenusaur = new QPushButton(dialog);

    connect(buttonVenusaur, &QPushButton::clicked, [=]()
    {
        if(game.human.getPokemons()[0].getIfFainted() == 0)
        {
            dialog->close();//close window
            clickSound->play();
            game.pokemon("Venusaur",getComputeRandomMove(),playMode);
            update();
        }
    });

    layout->addWidget(buttonVenusaur);

    //set Charizard
    QPushButton *buttonCharizard = new QPushButton(dialog);

    connect(buttonCharizard, &QPushButton::clicked, [=]()
            {
                if(game.human.getPokemons()[1].getIfFainted() == 0)
                {
                    dialog->close();//close window
                    clickSound->play();
                    game.pokemon("Charizard",getComputeRandomMove(),playMode);
                    update();
                }
            });

    layout->addWidget(buttonCharizard);

    //set Blastoise
    QPushButton *buttonBlastoise = new QPushButton(dialog);

    connect(buttonBlastoise, &QPushButton::clicked, [=]()
            {
                if(game.human.getPokemons()[2].getIfFainted() == 0)
                {
                    dialog->close();//close window
                    clickSound->play();
                    game.pokemon("Blastoise",getComputeRandomMove(),playMode);
                    update();
                }
            });

    layout->addWidget(buttonBlastoise);

    //set icon
    buttonVenusaur->setIcon(QIcon(*iconVenusaur));
    buttonVenusaur->setIconSize(iconVenusaur->size());
    buttonVenusaur->setFixedSize(150, 150);
    buttonCharizard->setIcon(QIcon(*iconCharizard));
    buttonCharizard->setIconSize(iconCharizard->size());
    buttonCharizard->setFixedSize(150, 150);
    buttonBlastoise->setIcon(QIcon(*iconBlastoise));
    buttonBlastoise->setIconSize(iconBlastoise->size());
    buttonBlastoise->setFixedSize(150, 150);
    dialog->setLayout(layout);
    dialog->resize(500, 200);
    dialog->exec();//display
}

void MainWindow::on_Bag_clicked()
{
    QDialog *dialog = new QDialog(this);
    dialog->setWindowFlags(dialog->windowFlags() & ~Qt::WindowCloseButtonHint);
    dialog->setWindowTitle("Pokemon");
    QHBoxLayout *layout = new QHBoxLayout(dialog);

    //set Potion
    QPushButton *buttonPotion = new QPushButton(dialog);

    connect(buttonPotion, &QPushButton::clicked, [=]()
            {
                if(game.human.getPokemons()[0].getIfFainted() != 0)
                {
                    dialog->close();//close window
                    clickSound->play();
                    game.pokemon("Venusaur",getComputeRandomMove(),playMode);
                    update();
                }
            });

    layout->addWidget(buttonPotion);
}

void chooseHealPokemon()
{

}

void MainWindow::on_Run_clicked()
{

}

string MainWindow::getComputeRandomMove()
{
    int Max = game.computer.getPokemons()[game.computer.selectPokemon].getMoves().size();
    int random = rand() % Max;
    return game.computer.getPokemons()[game.computer.selectPokemon].getMoves()[random].getName();
}
