
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPalette>
#include <QSoundEffect>
#include <QtWidgets>
#include <QFont>
#include "Game.h"
#include <QPropertyAnimation>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initIcon();//initialize all icon

    void initSound();//initialize all sound

    void loadFiles();//load all file

    void connectItem();//connect all Item

    void initProgressBar();//initialize all ProgressBar

    void update();//update

    string getComputeRandomMove();//return Compute Random Move

    void chooseHealPokemon(string type);//choose to heal whitch Pokemon

    void setAnimation();//set Animation

    void displayGameResult();//game over window

private slots:
    void on_Battle_clicked();

    void on_Pokemon_clicked();

    void on_Bag_clicked();

    void on_Run_clicked();

private:
    Ui::MainWindow *ui;
    QPixmap *iconBlastoise;//Blastoise icon
    QPixmap *iconCharizard;//Charizard icon
    QPixmap *iconVenusaur;//Venusaur icon
    QPixmap *iconPotion;//Potion icon
    QPixmap *iconSuperPotion;//SuperPotion icon
    QPixmap *iconHyperPotion;//HyperPotion icon
    QPixmap *iconMaxPotion;//MaxPotion icon
    QPixmap iconBackground{"./images/Background.png"};//Background icon
    QPixmap *iconPAR;//PAR icon
    QPixmap *iconBRN;//BRN icon
    QPixmap *iconPSN;//PSN icon
    QPixmap *iconDragon;//Dragon icon
    QPixmap *iconFire;//Fire icon
    QPixmap *iconFlying;//Flying icon
    QPixmap *iconSteel;//Steel icon
    QPixmap *iconWater;//Water icon
    QPixmap *iconPoison;//Poison icon
    QPixmap *iconGrass;//Grass icon
    QSoundEffect *startSound;//BGM
    QSoundEffect *clickSound;//click sound
    QProgressBar *playerHp;//player Hp
    QProgressBar *computerHp;//computer Hp
    QPushButton *Battle;//battle button
    QPushButton *Pokemon;//pokemon button
    QPushButton *Bag;//bag button
    QPushButton *Run;//run button
    QLabel *playerName;//display player current pokemon name
    QLabel *computerName;//display computer current pokemon name
    QLabel *playerPokemon;//display player current pokemon image
    QLabel *computerPokemon;//display computer current pokemon image
    QLabel *playerHpText;//display player current pokemon Hp information
    QLabel *computerHpText;//display computer current pokemon Hp information
    QLabel *playerPSN;//display player current pokemon if PSN
    QLabel *playerBRN;//display player current pokemon if BRN
    QLabel *playerPAR;//display player current pokemon if PAR
    QLabel *computerPSN;//display computer current pokemon if PSN
    QLabel *computerBRN;//display computer current pokemon if BRN
    QLabel *computerPAR;//display computer current pokemon if PAR
    QPropertyAnimation *animation;
protected:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        painter.drawPixmap(rect(), iconBackground.scaled(size()));
    }
};

#endif // MAINWINDOW_H
