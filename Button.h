#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
//#include "Menu.h"

class Controller;
void menu(Controller * menuController);
void intro();

class Button: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QString action;
    Controller * buttonController;
public:
    //constructor
    Button(QString str, Controller * bController);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:

};

#endif // BUTTON_H
