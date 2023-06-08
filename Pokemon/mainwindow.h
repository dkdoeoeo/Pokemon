
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPalette>



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
};

#endif // MAINWINDOW_H
