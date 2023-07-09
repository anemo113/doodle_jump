#include "Button.h"

Button::Button(QString str)
{
    if(str == "Play") {
     setPixmap(QPixmap(":/images/playButton.png"));
    }

    if(str == "Help") {
     setPixmap(QPixmap(":/images/helpButton.png"));
    }

    if(str == "Exit") {
     setPixmap(QPixmap(":/images/exitButton.png"));
    }

    if(str == "Back") {
     setPixmap(QPixmap(":/images/backButton.png"));
    }

    if(str == "SinglePlayer") {
     setPixmap(QPixmap(":/images/singleButton.png"));
    }

    if(str == "MultiPlayer") {
     setPixmap(QPixmap(":/images/multiButton.png"));
    }
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}
