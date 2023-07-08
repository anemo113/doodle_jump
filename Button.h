#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class Button: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QString action;
public:
    //constructor
    Button(QString str);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:

};

#endif // BUTTON_H
