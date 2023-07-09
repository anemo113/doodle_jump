#include <QApplication>
#include "View.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    View *myView = new View();
    myView->show();
    myView->menu();

    return a.exec();
}
