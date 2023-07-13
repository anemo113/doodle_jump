#include "Platform.h"

float Platform::speed = 9;
int Platform::score = 0;
int Platform::doodler_xPos;

Platform::Platform(QGraphicsScene *platformScene, QGraphicsItem *parent, QTimer *timer, int x, int y,QString s)
    : QObject(), QGraphicsPixmapItem(parent) , platformScene(platformScene) , type(s) , type2(s)
{
    speed = 9;
    score = 0;
    m = rand()%5+1; k=1; n=1;

    // set picture
    if(type == "Green") {
        setPixmap(QPixmap(":/images/platform1.png"));
        setPos(x, y);
        platformScene->addItem(this);
        strength = 5;
        connect(timer,SIGNAL(timeout()),this,SLOT(Move()));
    }

    if(type == "Brown") {
        setPixmap(QPixmap(":/images/platform2.png"));
        setPos(x,y);
        platformScene->addItem(this);
        strength = 1;
        connect(timer,SIGNAL(timeout()),this,SLOT(Move()));
    }

    if(type == "Move") {
        setPixmap(QPixmap(":/images/platform3.png"));
        setPos(x,y);
        platformScene->addItem(this);
        strength = -1;
        connect(timer,SIGNAL(timeout()),this,SLOT(Move()));
    }

    if(type == "Spring") {
        setPixmap(QPixmap(":/images/platform4.png"));
        setPos(x,y);
        platformScene->addItem(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(Move()));
        strength = -1;
    }

    if(type == "Rocket") {
        setPixmap(QPixmap(":/images/platform5.png"));
        setPos(x,y);
        platformScene->addItem(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(Move()));
        strength = -1;
    }

    if(s == "Speed") {
        setPixmap(QPixmap(":/images/platform6.png"));
        setPos(x,y);
        platformScene->addItem(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(Move()));
        strength = -1;
    }
}

void Platform::Move()
{

    if(speed < 0)
        if(((y() <= 589) && (y() >= 550)) && (((doodler_xPos <= x() + 49) && (x() - 40 <= doodler_xPos)))){
            if(type == "Green" || type == "Brown" || type == "Move") speed = 10;
            else if(type == "Spring") speed = 30;
            else if(type == "Rocket") speed = 40;
            else if(type == "Speed") speed = 20;
            strength--;
        }

    speed -= 0.05;

    // move
    if(type == "Move") {
        if(right) {
            setPos(x() + 4, y() + speed);
            if(x() > 535) right = false;
        }
        if(!right) {
            setPos(x() - 4, y() + speed);
            if(x() < 15) right = true;
        }
    }
    else
        setPos(x(), y() + speed);


    // returning back the out of box item
    if(y() > 750 || strength == 0) {

        if(type2 == "Spring" || type2 == "Rocket" || type2 == "Speed") {
            if(k%m == 0 && n < 10) {
                if(type2 == "Spring") { type = "Spring"; this->setPixmap(QPixmap(":/images/platform4.png")); }
                if(type2 == "Rocket") { type = "Rocket"; this->setPixmap(QPixmap(":/images/platform5.png")); }
                if(type2 == "Speed") { type = "Speed"; this->setPixmap(QPixmap(":/images/platform6.png")); }
                n++;
            }
            else { type = "Green"; this->setPixmap(QPixmap(":/images/platform1.png")); }
            k++;
        }

        setPos(rand() % 500, y() - 750);

        if(type == "Green") strength = 5;
        if(type == "Brown") strength = 1;

        score++;
    }

    if(score >= 0){
        if(y() < -20) {

            if(type2 == "Spring" || type2 == "Rocket" || type2 == "Speed") {
                if(k%m == 0 && n < 10) {
                    if(type2 == "Spring") { type = "Spring"; this->setPixmap(QPixmap(":/images/platform4.png")); }
                    if(type2 == "Rocket") { type = "Rocket"; this->setPixmap(QPixmap(":/images/platform5.png")); }
                    if(type2 == "Speed") { type = "Speed"; this->setPixmap(QPixmap(":/images/platform6.png")); }
                    n++;
                }
                else { type = "Green"; this->setPixmap(QPixmap(":/images/platform1.png")); }
                k++;
            }

            setPos(rand() % 500, y() + 750);

            if(type == "Green") strength = 5;
            if(type == "Brown") strength = 1;

            score--;
        }
    }
}
