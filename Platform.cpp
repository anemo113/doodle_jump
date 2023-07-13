#include "Platform.h"
#include <iostream>
using namespace std;

float Platform::speed = 9;
int Platform::hitpoints = 0;
int Platform::platformSecond = 0;
bool Platform::shield;
bool Platform::endGame;
int Platform::doodler_xPos;

Platform::Platform(QGraphicsScene *platformScene, QGraphicsItem *parent, QTimer *timer, int x, int y,QString s)
    : QObject(), QGraphicsPixmapItem(parent) , platformScene(platformScene) , type(s) , type2(s)
{
    shield = false;
    endGame = false;
    platformSecond = 0;
    speed = 9;
    hitpoints = 0;
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

    if(type == "Shield") {
        setPixmap(QPixmap(":/images/shield.png"));
        setPos(x,y);
        platformScene->addItem(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(Move()));
        strength = 1;
    }

    if(type == "Heart") {
        setPixmap(QPixmap(":/images/heart.png"));
        setPos(x,y);
        platformScene->addItem(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(Move()));
        strength = 1;
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
            else if(type == "Heart") {speed = 10; hitpoints++;}
            else if(type == "Shield"){
                speed = 10;
                platformSecond = 0;
                platformTimer = new QTimer();
                platformTimer->start(1000);
                connect(platformTimer, SIGNAL(timeout()), this, SLOT(countSecond()));
                shield = true;
            }
            strength--;
        }

    if(endGame == false){
        speed -= 0.05;
    }

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

        if(type2 == "Spring" || type2 == "Rocket" || type2 == "Speed" || type2 == "Shield" || type2 == "Heart") {
            if(k%m == 0 && n < 10) {
                if(type2 == "Spring") { type = "Spring"; this->setPixmap(QPixmap(":/images/platform4.png")); }
                if(type2 == "Rocket") { type = "Rocket"; this->setPixmap(QPixmap(":/images/platform5.png")); }
                if(type2 == "Speed") { type = "Speed"; this->setPixmap(QPixmap(":/images/platform6.png")); }
                if(type2 == "Heart") { type = "Heart"; this->setPixmap(QPixmap(":/images/heart.png")); }
                if(type2 == "Shield"){
                    if(shield == false) { type = "Shield"; this->setPixmap(QPixmap(":/images/shield.png")); }
                    else { type = "Green"; this->setPixmap(QPixmap(":/images/platform1.png")); }
                }
                n++;
            }
            else { type = "Green"; this->setPixmap(QPixmap(":/images/platform1.png")); }
            k++;
        }

        setPos(rand() % 500, -15);

        if(type == "Green") strength = 5;
        if(type == "Shield") strength = 1;
        if(type == "Heart") strength = 1;
        if(type == "Brown") strength = 1;
    }

    if(shield == true && y() < -20){
        if(type2 == "Spring" || type2 == "Rocket" || type2 == "Speed" || type2 == "Shield" || type2 == "Heart") {
            if(k%m == 0 && n < 10) {
                if(type2 == "Spring") { type = "Spring"; this->setPixmap(QPixmap(":/images/platform4.png")); }
                if(type2 == "Rocket") { type = "Rocket"; this->setPixmap(QPixmap(":/images/platform5.png")); }
                if(type2 == "Speed") { type = "Speed"; this->setPixmap(QPixmap(":/images/platform6.png")); }
                if(type2 == "Heart") { type = "Heart"; this->setPixmap(QPixmap(":/images/heart.png")); }
                if(type2 == "Shield"){
                    if(shield == false) { type = "Shield"; this->setPixmap(QPixmap(":/images/shield.png")); }
                    else { type = "Green"; this->setPixmap(QPixmap(":/images/platform1.png")); }
                }
                n++;
            }
            else { type = "Green"; this->setPixmap(QPixmap(":/images/platform1.png")); }
            k++;
        }

        setPos(rand() % 500, y() + 760);

        if(type == "Green") strength = 5;
        if(type == "Shield") strength = 1;
        if(type == "Heart") strength = 1;
        if(type == "Brown") strength = 1;
    }

    //shield protection
    if(shield == true){
        if(platformSecond >= 20){
            platformSecond = 0;
            shield = false;
        }
    }

    //end game
    if(speed <= -38){
        if(shield != true && hitpoints == 0){
            speed = 0;
            endGame = true;
            setPixmap(QPixmap(":/images/endGame.png"));
            setPos(145, 145);
            platformScene->addItem(this);
        }
        else if(hitpoints > 0){
            speed = 40;
            hitpoints--;
        }
    }
}

void Platform::countSecond()
{
    platformSecond++;
}
