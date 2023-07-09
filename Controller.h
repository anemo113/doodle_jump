#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>

class Controller : public QObject
{
    Q_OBJECT
    friend class View;
private:
    QGraphicsScene *scene;
    QTimer *Timer;
    QGraphicsRectItem *holder;

public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();

signals:

};

#endif // CONTROLLER_H
