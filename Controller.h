#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>
#include "Button.h"

class Controller : public QObject
{
    Q_OBJECT
    friend class View;
private:
    QGraphicsScene *scene;
    QTimer *Timer;
    QGraphicsRectItem *holder;
    QList<Button *> buttonList;

public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();
    void addButton(int x, int y, QString str);

signals:

};

#endif // CONTROLLER_H
