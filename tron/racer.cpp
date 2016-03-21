#include "racer.h"
#include <QBrush>
#include <iostream>

Racer::Racer(Player aPlayer)
    :player(aPlayer)
{
    if (player == blue)
    {
        ax = WIDTH / 2 - 20;
        ay = 50;
        direction = down;
        this->setBrush(QBrush(Qt::blue)); //set Color
        this->setRect(getXPos(), ay, PWIDTH, PHEIGHT);
        this->setTransformOriginPoint(ax, ay);
        this->setRotation(180);
    }
    else
    {
        ax = WIDTH / 2 + 20;
        ay = HEIGHT - 50;
        direction = up;
        this->setBrush(QBrush(Qt::red)); //set Color
        //set Rectangle
        this->setRect(getXPos(), ay, PWIDTH, PHEIGHT);
    }

    //setup Interrupt
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
}

void Racer::start()
{
    timer->start(50);
}

unsigned int Racer::getXPos() const
{
    return ax - PDELTA;
}

void Racer::rotateClock()
{
    this->setTransformOriginPoint(ax, ay);
    this->setRotation(rotation()-90);
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

void Racer::rotateReverse()
{
    this->setTransformOriginPoint(ax, ay);
    this->setRotation(rotation()+90);
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

void Racer::move()
{
    std::cout << "move()" << std::endl;
    switch (direction)
    {
    case right:
        this->setPos(x()+1, y());
        this->x++;
        break;
    case up:
        this->setPos(x(), y()-1);
        this->y--;
        break;
    case left:
        this->setPos(x()-1, y());
        this->x--;
        break;
    case down:
        this->setPos(x(), y()+1);
        this->y++;
        break;
    }
}
