
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
    iconDragon = new QPixmap("./images/Dragon.png");
    iconFire = new QPixmap("./images/Fire.png");
    iconFlying = new QPixmap("./images/Flying.png");
    iconSteel = new QPixmap("./images/Steel.png");
    iconWater = new QPixmap("./images/Water.png");
    iconPoison = new QPixmap("./images/Poison.png");
    iconGrass = new QPixmap("./images/Grass.png");
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
    QDialog *dialog = new QDialog(this);
    dialog->setWindowFlags(dialog->windowFlags() & ~Qt::WindowCloseButtonHint);
    dialog->setWindowTitle("Battle");
    QHBoxLayout *layout = new QHBoxLayout(dialog);

    for(int i = 0; i < game.human.getPokemons()[game.human.selectPokemon].getMoves().size(); i++)
    {
        if(game.human.getPokemons()[game.human.selectPokemon].getMoves()[i].getName() == "DragonClaw")
        {
            //set DragonClaw
            QPushButton *buttonDragonClaw = new QPushButton("DragonClaw",dialog);
            buttonDragonClaw->setIcon(QIcon(*iconDragon));
            buttonDragonClaw->setIconSize(QSize(32, 32));

            connect(buttonDragonClaw, &QPushButton::clicked, [=]()
                    {
                        dialog->close();//close window
                        clickSound->play();
                        game.Battle("DragonClaw",getComputeRandomMove(),playMode);
                        update();
                    });

            layout->addWidget(buttonDragonClaw);
        }
        else if(game.human.getPokemons()[game.human.selectPokemon].getMoves()[i].getName() == "Ember")
        {
            //set Ember
            QPushButton *buttonEmber = new QPushButton("Ember",dialog);
            buttonEmber->setIcon(QIcon(*iconFire));
            buttonEmber->setIconSize(QSize(32, 32));

            connect(buttonEmber, &QPushButton::clicked, [=]()
                    {
                        dialog->close();//close window
                        clickSound->play();
                        game.Battle("Ember",getComputeRandomMove(),playMode);
                        update();
                    });

            layout->addWidget(buttonEmber);
        }
        else if(game.human.getPokemons()[game.human.selectPokemon].getMoves()[i].getName() == "DragonBreath")
        {
            //set DragonBreath
            QPushButton *buttonDragonBreath = new QPushButton("DragonBreath",dialog);
            buttonDragonBreath->setIcon(QIcon(*iconDragon));
            buttonDragonBreath->setIconSize(QSize(32, 32));

            connect(buttonDragonBreath, &QPushButton::clicked, [=]()
                    {
                        dialog->close();//close window
                        clickSound->play();
                        game.Battle("DragonBreath",getComputeRandomMove(),playMode);
                        update();
                    });

            layout->addWidget(buttonDragonBreath);
        }
        else if(game.human.getPokemons()[game.human.selectPokemon].getMoves()[i].getName() == "AirSlash")
        {
            //set AirSlash
            QPushButton *buttonAirSlash = new QPushButton("AirSlash",dialog);
            buttonAirSlash->setIcon(QIcon(*iconFlying));
            buttonAirSlash->setIconSize(QSize(32, 32));

            connect(buttonAirSlash, &QPushButton::clicked, [=]()
                    {
                        dialog->close();//close window
                        clickSound->play();
                        game.Battle("AirSlash",getComputeRandomMove(),playMode);
                        update();
                    });

            layout->addWidget(buttonAirSlash);
        }
        else if(game.human.getPokemons()[game.human.selectPokemon].getMoves()[i].getName() == "Flamethrower")
        {
            //set Flamethrower
            QPushButton *buttonFlamethrower = new QPushButton("Flamethrower",dialog);
            buttonFlamethrower->setIcon(QIcon(*iconFlying));
            buttonFlamethrower->setIconSize(QSize(32, 32));

            connect(buttonFlamethrower, &QPushButton::clicked, [=]()
                    {
                        dialog->close();//close window
                        clickSound->play();
                        game.Battle("Flamethrower",getComputeRandomMove(),playMode);
                        update();
                    });

            layout->addWidget(buttonFlamethrower);
        }
        else if(game.human.getPokemons()[game.human.selectPokemon].getMoves()[i].getName() == "FlashCannon")
        {
            //set FlashCannon
            QPushButton *buttonFlashCannon = new QPushButton("FlashCannon",dialog);
            buttonFlashCannon->setIcon(QIcon(*iconSteel));
            buttonFlashCannon->setIconSize(QSize(32, 32));

            connect(buttonFlashCannon, &QPushButton::clicked, [=]()
                    {
                        dialog->close();//close window
                        clickSound->play();
                        game.Battle("FlashCannon",getComputeRandomMove(),playMode);
                        update();
                    });

            layout->addWidget(buttonFlashCannon);
        }
        else if(game.human.getPokemons()[game.human.selectPokemon].getMoves()[i].getName() == "WaterGun")
        {
            //set WaterGun
            QPushButton *buttonWaterGun = new QPushButton("WaterGun",dialog);
            buttonWaterGun->setIcon(QIcon(*iconWater));
            buttonWaterGun->setIconSize(QSize(32, 32));

            connect(buttonWaterGun, &QPushButton::clicked, [=]()
                    {
                        dialog->close();//close window
                        clickSound->play();
                        game.Battle("WaterGun",getComputeRandomMove(),playMode);
                        update();
                    });

            layout->addWidget(buttonWaterGun);
        }
        else if(game.human.getPokemons()[game.human.selectPokemon].getMoves()[i].getName() == "WaterPulse")
        {
            //set WaterPulse
            QPushButton *buttonWaterPulse = new QPushButton("WaterPulse",dialog);
            buttonWaterPulse->setIcon(QIcon(*iconWater));
            buttonWaterPulse->setIconSize(QSize(32, 32));

            connect(buttonWaterPulse, &QPushButton::clicked, [=]()
                    {
                        dialog->close();//close window
                        clickSound->play();
                        game.Battle("WaterPulse",getComputeRandomMove(),playMode);
                        update();
                    });

            layout->addWidget(buttonWaterPulse);
        }
        else if(game.human.getPokemons()[game.human.selectPokemon].getMoves()[i].getName() == "AquaTail")
        {
            //set AquaTail
            QPushButton *buttonAquaTail = new QPushButton("AquaTail",dialog);
            buttonAquaTail->setIcon(QIcon(*iconWater));
            buttonAquaTail->setIconSize(QSize(32, 32));

            connect(buttonAquaTail, &QPushButton::clicked, [=]()
                    {
                        dialog->close();//close window
                        clickSound->play();
                        game.Battle("AquaTail",getComputeRandomMove(),playMode);
                        update();
                    });

            layout->addWidget(buttonAquaTail);
        }
        else if(game.human.getPokemons()[game.human.selectPokemon].getMoves()[i].getName() == "PoisonPowder")
        {
            //set PoisonPowder
            QPushButton *buttonPoisonPowder = new QPushButton("PoisonPowder",dialog);
            buttonPoisonPowder->setIcon(QIcon(*iconPoison));
            buttonPoisonPowder->setIconSize(QSize(32, 32));

            connect(buttonPoisonPowder, &QPushButton::clicked, [=]()
                    {
                        dialog->close();//close window
                        clickSound->play();
                        game.Battle("PoisonPowder",getComputeRandomMove(),playMode);
                        update();
                    });

            layout->addWidget(buttonPoisonPowder);
        }
        else if(game.human.getPokemons()[game.human.selectPokemon].getMoves()[i].getName() == "SeedBomb")
        {
            //set SeedBomb
            QPushButton *buttonSeedBomb = new QPushButton("SeedBomb",dialog);
            buttonSeedBomb->setIcon(QIcon(*iconGrass));
            buttonSeedBomb->setIconSize(QSize(32, 32));

            connect(buttonSeedBomb, &QPushButton::clicked, [=]()
                    {
                        dialog->close();//close window
                        clickSound->play();
                        game.Battle("SeedBomb",getComputeRandomMove(),playMode);
                        update();
                    });

            layout->addWidget(buttonSeedBomb);
        }
        else if(game.human.getPokemons()[game.human.selectPokemon].getMoves()[i].getName() == "VineWhip")
        {
            //set VineWhip
            QPushButton *buttonVineWhip = new QPushButton("VineWhip",dialog);
            buttonVineWhip->setIcon(QIcon(*iconGrass));
            buttonVineWhip->setIconSize(QSize(32, 32));

            connect(buttonVineWhip, &QPushButton::clicked, [=]()
                    {
                        dialog->close();//close window
                        clickSound->play();
                        game.Battle("VineWhip",getComputeRandomMove(),playMode);
                        update();
                    });

            layout->addWidget(buttonVineWhip);
        }
        else if(game.human.getPokemons()[game.human.selectPokemon].getMoves()[i].getName() == "SolarBeam")
        {
            //set SolarBeam
            QPushButton *buttonSolarBeam = new QPushButton("SolarBeam",dialog);
            buttonSolarBeam->setIcon(QIcon(*iconGrass));
            buttonSolarBeam->setIconSize(QSize(32, 32));

            connect(buttonSolarBeam, &QPushButton::clicked, [=]()
                    {
                        dialog->close();//close window
                        clickSound->play();
                        game.Battle("SolarBeam",getComputeRandomMove(),playMode);
                        update();
                    });

            layout->addWidget(buttonSolarBeam);
        }
    }

    dialog->setLayout(layout);
    dialog->resize(500, 200);
    dialog->exec();//display
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
    dialog->setWindowTitle("Bag");
    QHBoxLayout *layout = new QHBoxLayout(dialog);

    //set Potion
    QPushButton *buttonPotion = new QPushButton(dialog);

    connect(buttonPotion, &QPushButton::clicked, [=]()
            {
                if(game.human.potion != 0)
                {
                    dialog->close();//close window
                    clickSound->play();
                    chooseHealPokemon("Potion");
                }
            });

    layout->addWidget(buttonPotion);

    //set SuperPotion
    QPushButton *buttonSuperPotion = new QPushButton(dialog);

    connect(buttonSuperPotion, &QPushButton::clicked, [=]()
            {
                if(game.human.potion != 0)
                {
                    dialog->close();//close window
                    clickSound->play();
                    chooseHealPokemon("SuperPotion");
                }
            });

    layout->addWidget(buttonSuperPotion);

    //set hyperPotion
    QPushButton *buttonHyperPotion = new QPushButton(dialog);

    connect(buttonHyperPotion, &QPushButton::clicked, [=]()
            {
                if(game.human.potion != 0)
                {
                    dialog->close();//close window
                    clickSound->play();
                    chooseHealPokemon("HyperPotion");
                }
            });

    layout->addWidget(buttonHyperPotion);

    //set maxPotion
    QPushButton *buttonMaxPotion = new QPushButton(dialog);

    connect(buttonMaxPotion, &QPushButton::clicked, [=]()
            {
                if(game.human.potion != 0)
                {
                    dialog->close();//close window
                    clickSound->play();
                    chooseHealPokemon("MaxPotion");
                }
            });

    layout->addWidget(buttonMaxPotion);

    //set icon
    buttonPotion->setIcon(QIcon(*iconPotion));
    buttonPotion->setIconSize(iconPotion->size());
    buttonPotion->setFixedSize(70, 70);
    buttonSuperPotion->setIcon(QIcon(*iconSuperPotion));
    buttonSuperPotion->setIconSize(iconSuperPotion->size());
    buttonSuperPotion->setFixedSize(70, 70);
    buttonHyperPotion->setIcon(QIcon(*iconHyperPotion));
    buttonHyperPotion->setIconSize(iconHyperPotion->size());
    buttonHyperPotion->setFixedSize(70, 70);
    buttonMaxPotion->setIcon(QIcon(*iconMaxPotion));
    buttonMaxPotion->setIconSize(iconMaxPotion->size());
    buttonMaxPotion->setFixedSize(70, 70);
    dialog->setLayout(layout);
    dialog->exec();//display
}

void MainWindow::chooseHealPokemon(string type)
{
    QDialog *dialog = new QDialog(this);
    dialog->setWindowFlags(dialog->windowFlags() & ~Qt::WindowCloseButtonHint);
    dialog->setWindowTitle("Heal");
    QHBoxLayout *layout = new QHBoxLayout(dialog);

    //set Venusaur
    QPushButton *buttonVenusaur = new QPushButton(dialog);

    connect(buttonVenusaur, &QPushButton::clicked, [=]()
            {
                if(game.human.getPokemons()[0].getIfFainted() == 0)
                {
                    dialog->close();//close window
                    clickSound->play();
                    game.Bag(type, "Venusaur", getComputeRandomMove(), playMode);
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
                    game.Bag(type, "Charizard", getComputeRandomMove(), playMode);
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
                    game.Bag(type, "Blastoise", getComputeRandomMove(), playMode);
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

void MainWindow::on_Run_clicked()
{
    clickSound->play();
    qApp->quit();
}

string MainWindow::getComputeRandomMove()
{
    int Max = game.computer.getPokemons()[game.computer.selectPokemon].getMoves().size();
    int random = rand() % Max;
    return game.computer.getPokemons()[game.computer.selectPokemon].getMoves()[random].getName();
}
