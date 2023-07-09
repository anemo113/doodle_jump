#include "Doodler.h"

Doodler::Doodler(QObject *parent)
    : QObject{parent}
{
    setPixmap(QPixmap(":/images/Doodler.png"));
}
