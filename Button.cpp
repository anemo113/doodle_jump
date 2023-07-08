#include "Button.h"
#include <iostream>
using namespace std;


Button::Button(QString str, Controller * bController)
{
    action = str;
    buttonController = bController;

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

}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // To Do
    if(action == "Play") intro();

    if(action == "Help") cout << 2 << endl;

    if(action == "Exit")  exit(1);

    if(action == "Back") menu(buttonController);

}
