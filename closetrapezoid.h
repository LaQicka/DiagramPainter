#ifndef CLOSETRAPEZOID_H
#define CLOSETRAPEZOID_H

#include "form.h"

/// @brief This is the heir from Form, also this class is acting like Down Trapezoid(using to end "for" circle)

class CloseTrapezoid : public Form
{
public:
    CloseTrapezoid(QString _text = "");

/// @brief function that allows scene to paint this element
/// @param painter -- scene paint tool
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    int anchor_x = 0, anchor_y = 0;
};

#endif // CLOSETRAPEZOID_H
