#include "Controller.h"

Controller::Controller(QObject *parent)
    : QObject{parent}
{
    // create scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 550, 750);

    // create holder
    holder = new QGraphicsRectItem();
    holder->setRect(0, 0, 550, 750);


}

Controller::~Controller()
{
    delete holder;
    delete scene;
}
