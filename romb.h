#ifndef ROMB_H
#define ROMB_H

#include <QGraphicsItem>
#include <QPainter>
#include "form.h"
#include <QString>

class Romb : public Form
{
public:
    Romb(QString _text = "");

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    int anchor_x = 0, anchor_y = 0;
};

#endif // ROMB_H
