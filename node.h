#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QPainter>

#include <form.h>

class Node : public QGraphicsItem
{
public:
    //Node() : Form(){type = 6;}
    //~Node();
    //Node(QString text) : Form(text){ type = 2; }
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    //void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

};

#endif // NODE_H
