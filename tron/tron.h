#ifndef TRON_H
#define TRON_H

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

class Map;
class Racer;

class Tron: public QGraphicsScene
{
public:
    Tron();
    ~Tron();
    void start();
    void keyPressEvent(QKeyEvent* event);

private:
    Map* map;
    QGraphicsView* view;
    Racer* racerBlue;
    Racer* racerRed;
};

#endif // TRON_H
