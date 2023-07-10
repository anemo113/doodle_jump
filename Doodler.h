#ifndef DOODLER_H
#define DOODLER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <cstdlib>

class Doodler : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    QGraphicsScene *doodlerScene;

public:
    Doodler(QGraphicsScene *doodlerScene,QGraphicsItem *parent, QTimer *timer);
    void keyPressEvent(QKeyEvent * keyEvent);
};

#endif // DOODLER_H
