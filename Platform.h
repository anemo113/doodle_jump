#ifndef PLATFORM_H
#define PLATFORM_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <cstdlib>
#include "Doodler.h"

class Platform : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    friend class Doodler;
    //friend class Doodler2;
private:
    QGraphicsScene *platformScene;
    QTimer *platformTimer;
    static float speed;
    static int hitpoints;
    static int platformSecond;
    static int doodler_xPos;
    static bool shield;
    static bool endGame;
    QString type,type2;
    int strength;
    int m,k,n;
    bool right = true;

public:
    Platform(QGraphicsScene *platformScene,QGraphicsItem *parent, QTimer *timer, int x, int y,QString s);
    void endOfGame();

public slots:
    void Move();
    void countSecond();
};

#endif // PLATFORM_H
