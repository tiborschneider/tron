#include "racer.h"
#include "track.h"
#include <QBrush>
#include <iostream>

Racer::Racer(Player aPlayer)
    :player(aPlayer)
{
    int ax, ay;
    ax = 250;
    if (player == blue)
    {
        ay = 120;
        direction = up;
        this->setBrush(QBrush(Qt::blue)); //set Color
        currentTrack = new Track(ax + PDELTA, ay);
        this->rotateClock(currentTrack);
        this->rotateClock(currentTrack);
    }
    else
    {
        ay = 380;
        direction = up;
        this->setBrush(QBrush(Qt::red)); //set Color
        currentTrack = new Track(ax + PDELTA, ay);
    }
    this->setRect(0, 0, PWIDTH, PHEIGHT);
    this->setPos(ax, ay);
}

int Racer::getX() const
{
    return x() + PDELTA;
}

int Racer::getY() const
{
    return y();
}

Track* Racer::getCurrentTrack() const
{
    return currentTrack;
}

void Racer::rotateReverse(Track *nextTrack)
{
    this->setTransformOriginPoint(PDELTA, 0);
    this->setRotation(rotation()-90);
    currentTrack = nextTrack;
    switch (direction)
    {
    case left:
        direction = down;
        break;
    case down:
        direction = right;
        break;
    case right:
        direction = up;
        break;
    case up:
        direction = left;
        break;
    }
}

void Racer::rotateClock(Track *nextTrack)
{
    this->setTransformOriginPoint(PDELTA, 0);
    this->setRotation(rotation()+90);
    currentTrack = nextTrack;
    switch (direction)
    {
    case left:
        direction = up;
        break;
    case down:
        direction = left;
        break;
    case right:
        direction = down;
        break;
    case up:
        direction = right;
        break;
    }
}

void Racer::move()
{
    switch (direction)
    {
    case right:
        this->setPos(x()+1, y());
        break;
    case up:
        this->setPos(x(), y()-1);
        break;
    case left:
        this->setPos(x()-1, y());
        break;
    case down:
        this->setPos(x(), y()+1);
        break;
    }
    currentTrack->setLine(currentTrack->getStartX(), currentTrack->getStartY(), this->getX(), this->getY());
}
