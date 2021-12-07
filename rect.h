#ifndef RECT_H
#define RECT_H

#include <form.h>

/// @brief This is the heir from Form, also this class is acting like Rect(using to different actions)

class Rect : public Form
{
public:
    Rect(QString _text = "");

/// @brief function that allows scene to paint this element
/// @param painter -- scene paint tool
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // RECT_H
