#ifndef ELLIPSOID_H
#define ELLIPSOID_H

#include <QGraphicsItem>
#include <QPainter>
#include <form.h>

class Ellipsoid : public Form
{
public:
    Ellipsoid(QString _text = "");

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // ELLIPSOID_H
