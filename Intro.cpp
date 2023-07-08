#include "Intro.h"

void intro()
{
    Controller *introController;
    introController = new Controller();
    introController->addButton(0, 0, "Back", introController);
}
