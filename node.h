#ifndef NODE_H
#define NODE_H

#include <form.h>

class Node : public Form
{
public:
    Node();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // NODE_H
