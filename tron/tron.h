#ifndef TRON_H
#define TRON_H

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QTimer>
#include "definitions.h"

class Map;
class Racer;
class Track;

class Tron: public QGraphicsScene
{
    Q_OBJECT
public:
    Tron();
    ~Tron();
    void start();
    void gameOver(Player winner);
    void keyPressEvent(QKeyEvent* event);

public slots:
    void move();

private:
    Map* map;
    QGraphicsView* view;
    Racer* racerBlue;
    Racer* racerRed;
    Track** pTrackBlue;
    Track** pTrackRed;
    int numTrackBlue;
    int numTrackRed;
    QTimer* timer;
};

#endif // TRON_H
