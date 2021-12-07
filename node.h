#ifndef NODE_H
#define NODE_H

#include <form.h>

/// @brief This is the heir from Form, also this class is acting like angle connector to edges

class Node : public Form
{
public:
    Node();

/// @brief function that return element render borders
    QRectF boundingRect() const;

/// @brief function that allows scene to paint this element
/// @param painter -- scene paint tool
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // NODE_H
