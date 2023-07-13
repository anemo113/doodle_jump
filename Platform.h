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
    static float speed;
    static int score;
    static int doodler_xPos;
    QString type,type2;
    int strength;
    int m,k,n;
    bool right = true;

public:
    Platform(QGraphicsScene *platformScene,QGraphicsItem *parent, QTimer *timer, int x, int y,QString s);

public slots:
    void Move(); // To Do
};

#endif // PLATFORM_H
