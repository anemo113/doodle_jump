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

    // create timer
    ctimer = new QTimer();
    ctimer->start(40);
}

Controller::~Controller()
{
    delete holder;
    delete scene;
}

void Controller::addPlatform(int x, int y)
{
    platformList.push_back(new Platform(scene,holder,ctimer, x, y));
}

void Controller::addDoodler()
{
    doodlerList.push_back(new Doodler(scene,holder,ctimer));
    doodlerList.last()->setFlag(QGraphicsItem::ItemIsFocusable);
    doodlerList.last()->setFocus();
}
