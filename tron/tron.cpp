#include "tron.h"
#include "map.h"
#include "racer.h"
#include <QKeyEvent>
#include <iostream>

Tron::Tron()
{
    //configure interrupt for keyboard input
    this->setFocus();

    //add Components
    this->map = new Map();
    this->racerBlue = new Racer(blue);
    this->racerRed = new Racer(red);

    //add Components to scene
    this->addItem(map);
    this->addItem(racerBlue);
    this->addItem(racerRed);

    //add View
    this->view = new QGraphicsView(this);
    view->setFixedSize(WIDTH + 20, HEIGHT + 20);
    //view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setWindowTitle("Pong");
    view->show();
}


Tron::~Tron()
{
    delete this->view;
    delete this->map;
}

void Tron::start()
{
    racerBlue->start();
    racerRed->start();
    //racerRed->move();
    std::cout << "(" << racerRed->x() << ", " << racerRed->y() << "), (" << racerBlue->x() << ", " << racerBlue->y() << ")" << std::endl;
    //racerRed->rotateClock();
    std::cout << "(" << racerRed->x() << ", " << racerRed->y() << "), (" << racerBlue->x() << ", " << racerBlue->y() << ")" << std::endl;
}

void Tron::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_A)
        racerBlue->rotateReverse();
    else if (event->key() == Qt::Key_D)
        racerBlue->rotateClock();
    else if (event->key() == Qt::Key_Left)
        racerRed->rotateReverse();
    else if (event->key() == Qt::Key_Right)
        racerRed->rotateClock();
}
