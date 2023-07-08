#include "Menu.h"

void menu(Controller * menuController){
    menuController->addButton(200, 375, "Play");
    menuController->addButton(200, 475, "Help");
    menuController->addButton(200, 575, "Exit");
}
