#ifndef ELLIPSOID_H
#define ELLIPSOID_H

#include <form.h>

/// @brief This is the heir from Form, also this class is acting like Ellipsoid(using to start and end of Diagram)

class Ellipsoid : public Form
{
public:
    Ellipsoid(QString _text = "");

/// @brief function that allows scene to paint this element
/// @param painter -- scene paint tool
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // ELLIPSOID_H
