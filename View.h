#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QTimer>
#include "Menu.h"


class View : public QGraphicsView
{
    Q_OBJECT

private:
    QTimer *viewTimer;
    Controller *viewController;

public:
    explicit View();
    ~View();

signals:

};

#endif // VIEW_H
