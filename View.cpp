#include "View.h"

View::View() : QGraphicsView()
{
    // ceate viewController
    viewController = new Controller();

    // create scene
    setScene(viewController->scene);

    // set background image
    setBackgroundBrush(QBrush(QImage(":/images/background.png")));

    //set fixed size
    setFixedSize(550,750);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    menu(viewController);

}

View::~View()
{
    delete viewTimer;
    delete viewController;
}
