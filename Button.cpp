#include "Button.h"
#include <iostream>
using namespace std;


Button::Button(QString str)
{
    action = str;

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
    if(action == "Play") cout << 1 << endl;

    if(action == "Help") cout << 2 << endl;

    if(action == "Exit")  exit(1);

    if(action == "Back") cout << 4 << endl;

}
