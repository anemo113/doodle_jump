#ifndef DOODLER_H
#define DOODLER_H

#include <QObject>
#include <QGraphicsPixmapItem>>

class Doodler : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Doodler(QObject *parent = nullptr);

signals:

};

#endif // DOODLER_H
