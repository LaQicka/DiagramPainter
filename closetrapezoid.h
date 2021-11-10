#ifndef CLOSETRAPEZOID_H
#define CLOSETRAPEZOID_H

#include "form.h"

class CloseTrapezoid : public Form
{
public:
    CloseTrapezoid(QString _text = "");

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    int anchor_x = 0, anchor_y = 0;
};

#endif // CLOSETRAPEZOID_H
