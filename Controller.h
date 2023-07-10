#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>
#include <Platform.h>
#include <Doodler.h>

class Controller : public QObject
{
    Q_OBJECT
    friend class View;
    friend class Menu;
private:
    QGraphicsScene *scene;
    QTimer *ctimer;
    QGraphicsRectItem *holder;
    QList <Platform *> platformList;
    QList <Doodler *> doodlerList;

public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();
    void addPlatform(int x, int y, int doodler_x);
    void addDoodler();

signals:

};

#endif // CONTROLLER_H
