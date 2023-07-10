#ifndef PLATFORM_H
#define PLATFORM_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <cstdlib>

class Platform : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    QGraphicsScene *platformScene;
    int xPos;
    int yPos;
    int doodler_xPos;
    float speed;

public:
    Platform(QGraphicsScene *platformScene,QGraphicsItem *parent, QTimer *timer, int x, int y, int doodler_x);

public slots:
    void movetoDown(); // To Do
};

#endif // PLATFORM_H
