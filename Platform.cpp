#include "Platform.h"


Platform::Platform(QGraphicsScene *platformScene, QGraphicsItem *parent, QTimer *timer)
    : QObject(), QGraphicsPixmapItem(parent) , platformScene(platformScene)
{
    // set picture
    setPixmap(QPixmap(":/images/platform1.png"));

    // add to scene
    platformScene->addItem(this);
    setPos(rand()%485, 0);


    // connect timer to move
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
}


void Platform::move()
{
    // move down
    setPos(x(), y() + 50);

    // remove and delete
    if(y() > 750) {
        platformScene->removeItem(this);
        delete this;
    }
}
