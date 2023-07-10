#include "Platform.h"


Platform::Platform(QGraphicsScene *platformScene, QGraphicsItem *parent, QTimer *timer)
    : QObject(), QGraphicsPixmapItem(parent) , platformScene(platformScene)
{
    // set picture
    setPixmap(QPixmap(":/images/platform1.png"));

    // add to scene
    platformScene->addItem(this);
    setPos(200, 430);


    // connect timer to move
    // connect(timer,SIGNAL(timeout()),this,SLOT(movetoDown()));
}


void Platform::movetoDown()
{
    // move down
    setPos(x(), y() + 5);

    // remove and delete
    if(y() > 750) {
        platformScene->removeItem(this);
        delete this;
    }
}
