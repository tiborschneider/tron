#include "racer.h"
#include "track.h"
#include <QBrush>
#include <iostream>

Racer::Racer(Player aPlayer)
    :player(aPlayer)
{
    int ax, ay;
    if (player == blue)
    {
        ax = 250;
        ay = 220;
        direction = down;
        currentTrack = new Track(ax, ay);
        this->setBrush(QBrush(Qt::blue)); //set Color
        this->setRect(0, 0, PWIDTH, PHEIGHT);
        this->setTransformOriginPoint(0, 0);
        this->setRotation(+180);
        this->setPos(ax + PWIDTH, ay);
    }
    else
    {
        ax = 250;
        ay = 280;
        direction = up;
        currentTrack = new Track(ax, ay);
        this->setBrush(QBrush(Qt::red)); //set Color
        this->setRect(0, 0, PWIDTH, PHEIGHT);
        this->setPos(ax, ay);
    }
}

int Racer::getX() const
{
    switch (direction)
    {
    case up:
        return x() + PDELTA;
        break;
    case down:
        return x() - PDELTA;
        break;
    case left:
        return x();
        break;
    default:
        return x();
        break;
    }
}

int Racer::getY() const
{
    switch (direction)
    {
    case up:
        return y();
        break;
    case down:
        return y();
        break;
    case left:
        return y() - PDELTA;
        break;
    default:
        return y() + PDELTA;
        break;
    }
}

Track* Racer::getCurrentTrack() const
{
    return currentTrack;
}

void Racer::rotateReverse()
{
    this->setTransformOriginPoint(PDELTA, 0);
    this->setRotation(rotation()-90);
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

void Racer::rotateClock()
{
    this->setTransformOriginPoint(PDELTA, 0);
    this->setRotation(rotation()+90);
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
}
