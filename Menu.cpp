#include "Menu.h"

void menu(Controller * menuController){
    menuController->addButton(200, 375, "Play", menuController);
    menuController->addButton(200, 475, "Help", menuController);
    menuController->addButton(200, 575, "Exit", menuController);
}
