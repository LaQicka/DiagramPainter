#ifndef EDGE_H
#define EDGE_H

#include <QGraphicsItem>
#include <form.h>
#include <cmath>

class Form;
class Edge : public QGraphicsItem
{
public:

    void setStart(Form* node);
    void setEnd(Form* node);
    void deleteStart();
    void deleteEnd();

    void adjust();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    Form *startNode() const;
    Form *endNode() const;
    Form* start = nullptr;
    Form* end = nullptr;

private:

};

#endif // EDGE_H
