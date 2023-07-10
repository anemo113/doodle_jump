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
private:
    QGraphicsScene *platformScene;
    static float speed;
    static int doodler_xPos;

public:
    Platform(QGraphicsScene *platformScene,QGraphicsItem *parent, QTimer *timer, int x, int y);

public slots:
    void movetoDown(); // To Do
};

#endif // PLATFORM_H
