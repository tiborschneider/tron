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
    void rotateClock();
    void rotateReverse();

public slots:
    void move();

private:
    Player player;
    unsigned int ax;
    unsigned int ay;
    Direction direction;
    QTimer* timer;
    
};

#endif // RACER_H
