#include "Platform.h"


Platform::Platform(QGraphicsScene *platformScene, QGraphicsItem *parent, QTimer *timer, int x, int y, int doodler_x)
    : QObject(), QGraphicsPixmapItem(parent) , platformScene(platformScene)
{
    speed = 1;

    // set picture
    setPixmap(QPixmap(":/images/platform1.png"));
    xPos = x;
    yPos = y;
    doodler_xPos = doodler_x;
    setPos(xPos, yPos);

    // add to scene
    platformScene->addItem(this);

    // connect timer to move
    connect(timer,SIGNAL(timeout()),this,SLOT(movetoDown()));
}


void Platform::movetoDown()
{

    if((y() <= 589) && (((doodler_xPos <= x() + 49) && (x() - 40 <= doodler_xPos)))){
        speed = 5;
    }

    speed -= 0.17;

    // move down
    setPos(x(), y() + speed);
    xPos = x();
    yPos = y();

    // remove and delete
    if(y() > 750) {
        platformScene->removeItem(this);
        delete this;
    }
}
