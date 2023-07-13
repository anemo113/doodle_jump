#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QTimer>
#include "Controller.h"

class View : public QGraphicsView
{
    Q_OBJECT

private:
    QTimer *viewTimer;
    Controller *viewController;
    int seconds;

public:
    explicit View();
    ~View();

public slots:
    void incermentTime();
    void menu();
    void intro();
    void help();
    void singleMode();
    void multiMode();

signals:

};

#endif // VIEW_H
