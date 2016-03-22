#include "tron.h"
#include "map.h"
#include "racer.h"
#include "track.h"
#include <QKeyEvent>
#include <iostream>

Tron::Tron()
{
    //initialize Array & Counter
    this->pTrackBlue = new Track*[ARRAYSIZE];
    this->pTrackRed = new Track*[ARRAYSIZE];
    this->numTrackBlue = 0;
    this->numTrackRed = 0;

    //configure interrupt for keyboard input
    this->setFocus();

    //add Components
    this->map = new Map();
    this->racerBlue = new Racer(blue);
    this->racerRed = new Racer(red);
    this->pTrackBlue[numTrackBlue++] = racerBlue->getCurrentTrack();
    this->pTrackRed[numTrackRed++] = racerRed->getCurrentTrack();

    //add Components to scene
    this->addItem(map);
    this->addItem(racerBlue);
    this->addItem(racerRed);
    this->addItem(pTrackBlue[0]);
    this->addItem(pTrackRed[0]);

    //add View
    this->view = new QGraphicsView(this);
    view->setFixedSize(WIDTH + 20, HEIGHT + 20);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setWindowTitle("Pong");
    view->show();

    //setup Interrupt
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
}


Tron::~Tron()
{
    delete this->view;
    delete this->map;
}

void Tron::start()
{
    timer->start(16);
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

void Tron::move()
{
    racerBlue->move();
    racerRed->move();

    //check, if racers moved into borders
    if (racerBlue->getX() >= WIDTH - 3 * BORDER ||
        racerBlue->getX() < -BORDER ||
        racerBlue->getY() >= HEIGHT - BORDER ||
        racerBlue->getY() < BORDER)
    {
        timer->stop();
    }

    if (racerRed->getX() >= WIDTH - 3 * BORDER ||
        racerRed->getX() < -BORDER ||
        racerRed->getY() >= HEIGHT - BORDER ||
        racerRed->getY() < BORDER)
    {
        timer->stop();
    }
}
