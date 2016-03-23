#ifndef TRACK_H
#define TRACK_H

#include <QGraphicsLineItem>

class Track: public QGraphicsLineItem
{
public:
    Track(int ax, int ay);
    int getStartX() const;
    int getStartY() const;
};

#endif // TRACK_H
