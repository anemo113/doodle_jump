#include "Doodler.h"
#include "Platform.h"

Doodler::Doodler(QGraphicsScene *doodlerScene, QGraphicsItem *parent, QTimer *timer)
    : QObject() , QGraphicsPixmapItem(parent) , doodlerScene(doodlerScene)
{
    // set picture
    setPixmap(QPixmap(":/images/doodler.png"));

    // add to scene
    doodlerScene->addItem(this);
    setPos(255,550);

    Platform::doodler_xPos = 255;
}

void Doodler::keyPressEvent(QKeyEvent *keyEvent)
{
    //move to right
    if(keyEvent->key() == Qt::Key_Right){
        this->setPixmap(QPixmap(":/images/doodler.png"));
        setPos(x() + 15, y());
    }

    //move to left
    if(keyEvent->key() == Qt::Key_Left){
        this->setPixmap(QPixmap(":/images/doodler2.png"));
        setPos(x() - 15, y());
    }

    if(x() >= 530){
        setPos(x() - 550, y());

    }

    if(x() <= -20){
        setPos(x() + 550, y());
    }
    Platform::doodler_xPos = x();
}



