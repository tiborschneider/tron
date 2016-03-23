#ifndef RACER_H
#define RACER_H

#include <QGraphicsRectItem>
#include "definitions.h"

class Track;

class Racer : public QGraphicsRectItem
{
public:
    Racer(Player aPlayer);
    void start();
    inline unsigned int getXPos() const;
    int getX() const;
    int getY() const;
    Track* getCurrentTrack() const;
    void rotateClock();
    void rotateReverse();
    void move();

private:
    Player player;
    Direction direction;
    Track* currentTrack;
    
};

#endif // RACER_H
