#ifndef RECT_H
#define RECT_H

#include <QGraphicsItem>
#include <QPainter>

#include <form.h>

class Rect : public Form
{
public:
    Rect(QString _text = "");

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // RECT_H
