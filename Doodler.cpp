#include "Doodler.h"

Doodler::Doodler(QGraphicsScene *doodlerScene, QGraphicsItem *parent, QTimer *timer)
    : QObject() , QGraphicsPixmapItem(parent) , doodlerScene(doodlerScene)
{
    // set picture
    setPixmap(QPixmap(":/images/doodler.png"));

    // add to scene
    doodlerScene->addItem(this);
    setPos(255,550);

}

void Doodler::keyPressEvent(QKeyEvent *keyEvent)
{
    //move to right
    if(keyEvent->key() == Qt::Key_Right){
        setPos(x() + 10, y());
    }

    //move to left
    if(keyEvent->key() == Qt::Key_Left){
        setPos(x() - 10, y());
    }

    if(x() >= 530){
        setPos(x() - 550, y());
    }

    if(x() <= -20){
        setPos(x() + 550, y());
    }
}

