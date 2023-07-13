#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class Button: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    //constructor
    Button(QString str);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:
    void clicked();
};

#endif // BUTTON_H
