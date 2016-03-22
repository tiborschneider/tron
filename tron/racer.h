#ifndef RACER_H
#define RACER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include "definitions.h"

class Racer : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Racer(Player aPlayer);
    void start();
    inline unsigned int getXPos() const;
    inline unsigned int getX() const;
    inline unsigned int getY() const;
    void rotateClock();
    void rotateReverse();

public slots:
    void move();

private:
    Player player;
    Direction direction;
    QTimer* timer;
    
};

#endif // RACER_H
