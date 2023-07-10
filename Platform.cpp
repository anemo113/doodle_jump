#include "Platform.h"


float Platform::speed = 9;
int Platform::doodler_xPos;

Platform::Platform(QGraphicsScene *platformScene, QGraphicsItem *parent, QTimer *timer, int x, int y)
    : QObject(), QGraphicsPixmapItem(parent) , platformScene(platformScene)
{
    // set picture
    setPixmap(QPixmap(":/images/platform1.png"));
    setPos(x, y);

    // add to scene
    platformScene->addItem(this);

    // connect timer to move
    connect(timer,SIGNAL(timeout()),this,SLOT(movetoDown()));
}

void Platform::movetoDown()
{

    if(((y() <= 589) && (y() >= 550)) && (((doodler_xPos <= x() + 49) && (x() - 40 <= doodler_xPos)))){
        speed = 9;
    }

    speed -= 0.05;

    // move down
    setPos(x(), y() + speed);

    // returning back the out of box item
    if(y() > 750){
        setPos(rand() % 500, y() - 700);
    }
}
