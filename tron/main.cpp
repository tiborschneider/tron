#include <QApplication>
#include "tron.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Tron tronGame;
    tronGame.start();
    
    return a.exec();
}
