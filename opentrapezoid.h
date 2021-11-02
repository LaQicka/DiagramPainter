#ifndef OPENTRAPEZOID_H
#define OPENTRAPEZOID_H

#include "form.h"

class OpenTrapezoid : public Form
{
public:
    OpenTrapezoid();
    OpenTrapezoid(QString text) : Form(text){ type = 4; }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    int anchor_x = 0, anchor_y = 0;
};

#endif // OPENTRAPEZOID_H
