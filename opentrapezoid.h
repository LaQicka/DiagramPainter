#ifndef OPENTRAPEZOID_H
#define OPENTRAPEZOID_H

#include "form.h"

/// @brief This is the heir from Form, also this class is acting like Upper Trapezoid(using to start of "for" circle)

class OpenTrapezoid : public Form
{
public:
    OpenTrapezoid(QString _text = "");

/// @brief function that allows scene to paint this element
/// @param painter -- scene paint tool
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    int anchor_x = 0, anchor_y = 0;
};

#endif // OPENTRAPEZOID_H
