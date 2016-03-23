#include "tron.h"
#include "map.h"
#include "racer.h"
#include "track.h"
#include <QKeyEvent>
#include <iostream>
#include <QPoint>

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

void Tron::gameOver(Player winner)
{
    timer->stop();
    switch (winner)
    {
    case red:
        std::cout << "Red Lost!" << std::endl;
        break;
    adadadddfdefault:
        std::cout << "Blue Lost!" << std::endl;
        break;
    }
}

void Tron::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_A)
    {
        pTrackBlue[numTrackBlue] = new Track(racerBlue->getX(), racerBlue->getY());
        this->addItem(pTrackBlue[numTrackBlue]);
        racerBlue->rotateReverse(pTrackBlue[numTrackBlue++]);
    }
    else if (event->key() == Qt::Key_D)
    {
        pTrackBlue[numTrackBlue] = new Track(racerBlue->getX(), racerBlue->getY());
        this->addItem(pTrackBlue[numTrackBlue]);
        racerBlue->rotateClock(pTrackBlue[numTrackBlue++]);
    }
    else if (event->key() == Qt::Key_Left)
    {
        pTrackRed[numTrackRed] = new Track(racerRed->getX(), racerRed->getY());
        this->addItem(pTrackRed[numTrackRed]);
        racerRed->rotateReverse(pTrackRed[numTrackRed++]);
    }
    else if (event->key() == Qt::Key_Right)
    {
        pTrackRed[numTrackRed] = new Track(racerRed->getX(), racerRed->getY());
        this->addItem(pTrackRed[numTrackRed]);
        racerRed->rotateClock(pTrackRed[numTrackRed++]);
    }
}

void Tron::move()
{
    racerBlue->move();
    racerRed->move();
    QPoint pBlue(racerBlue->getX(), racerBlue->getY());
    QPoint pRed(racerRed->getX(), racerRed->getY());

    //check, if racers moved into borders
    if (racerBlue->getX() >= WIDTH - 3 * BORDER ||
        racerBlue->getX() < -BORDER ||
        racerBlue->getY() >= HEIGHT - BORDER ||
        racerBlue->getY() < BORDER)
    {
        this->gameOver(blue);
    }

    if (racerRed->getX() >= WIDTH - 3 * BORDER ||
        racerRed->getX() < -BORDER ||
        racerRed->getY() >= HEIGHT - BORDER ||
        racerRed->getY() < BORDER)
    {
        this->gameOver(red);
    }

    //check, if racers moved into track
    //blue track
    for (int i = 0; i < numTrackBlue - 1; i++)
    {
        if (pTrackBlue[i]->contains(pBlue))
            this->gameOver(blue);
        if (pTrackBlue[i]->contains(pRed))
            this->gameOver(red);
    }

    //check current blue Track against Red Player
    if (pTrackBlue[numTrackBlue - 1]->contains(pRed))
        this->gameOver(red);

    //red Track
    for (int i = 0; i < numTrackRed - 1; i++)
    {
        if (pTrackRed[i]->contains(pBlue))
            this->gameOver(blue);
        if (pTrackRed[i]->contains(pRed))
            this->gameOver(red);
    }

    //check current red Track against Blue player
    if (pTrackRed[numTrackRed - 1]->contains(pBlue))
        this->gameOver(blue);
}
