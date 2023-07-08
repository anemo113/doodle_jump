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

public:
    Platform(QGraphicsScene *platformScene,QGraphicsItem *parent, QTimer *timer);

public slots:
    void move(); // To Do
};

#endif // PLATFORM_H
