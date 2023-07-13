#include <QApplication>
#include <cstdlib>
#include <ctime>
#include "View.h"

    int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // seed random number generator
    srand( time(0) );

    // create the game
    View *myView = new View();
    myView->show();
    myView->menu();

    return a.exec();
}
