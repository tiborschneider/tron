#include "track.h"

Track::Track(int ax, int ay)
{
    setLine(ax, ay, ax, ay);
}

int Track::getStartX() const
{
    return this->line().x1();
}

int Track::getStartY() const
{
    return this->line().x2();
}
