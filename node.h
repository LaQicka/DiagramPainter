#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <form.h>
#include <QList>

class Node : public Form
{
public:
    Node();
    QRectF boundingRect() const;
    void addNode(Node* newNode);
    bool Pressed;
    void setText(QString text);
    QPair<int,int> getPos();
    void setPos(int x,int y);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int edgeNumber;
    QList <Node*> edges;
};

#endif // NODE_H
