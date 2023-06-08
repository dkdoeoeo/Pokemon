
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPalette>
#include <QSoundEffect>
#include <QtWidgets>
#include <QFont>
#include "Game.h"

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

    string getComputeRandomMove();

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
    QPixmap *iconBackground;//Background icon
    QPixmap *iconPAR;//PAR icon
    QPixmap *iconBRN;//BRN icon
    QPixmap *iconPSN;//PSN icon
    QSoundEffect *startSound;//BGM
    QSoundEffect *clickSound;//click sound
    QProgressBar *playerHp;
    QProgressBar *computerHp;
    QPushButton *Battle;
    QPushButton *Pokemon;
    QPushButton *Bag;
    QPushButton *Run;
    QLabel *playerName;
    QLabel *computerName;
    QLabel *playerPokemon;
    QLabel *computerPokemon;
    QLabel *playerHpText;
    QLabel *computerHpText;
    QLabel *playerPSN;
    QLabel *playerBRN;
    QLabel *playerPAR;
    QLabel *computerPSN;
    QLabel *computerBRN;
    QLabel *computerPAR;

};

#endif // MAINWINDOW_H
