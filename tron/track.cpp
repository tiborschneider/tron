#include "track.h"

Track::Track(int ax, int ay)
{
    this->setLine(ax, ay, ax, ay);
    this->setZValue(-1);
}

int Track::getStartX() const
{
    return this->line().x1();
}

int Track::getStartY() const
{
    return this->line().y1();
}
