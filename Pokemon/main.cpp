
#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "Game.h"

using namespace std;

void RunCommandFile(string testFile, string outputFile);//the game model to read commandFile

int main(int argc, char *argv[])
{
    if (string(argv[1]) == string("CommandFile") && argc == 4)
    {
        RunCommandFile(argv[2], argv[3]);
    }
    else if(argc == 1)
    {
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        return a.exec();
    }
}

// Intent: the game model to read commandFile
// Pre: input commandFileName,outputFileName
// Post: have a output file
void RunCommandFile(string testFile, string outputFileName)
{
    Game game;//create new game
//    ofstream outputFile;
//    outputFile.open(outputFileName);//create output file
//    cout.rdbuf(outputFile.rdbuf());//write cout things into output file
    game.ExecuteCommandFile(testFile);//execute commandFile
//    outputFile.close();//close file
}
