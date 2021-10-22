#ifndef EDGE_H
#define EDGE_H

#include <QGraphicsItem>
#include <node.h>
#include <cmath>

class Node;
class Edge : public QGraphicsItem
{
public:

    void setStart(Node* node);
    void setEnd(Node* node);
    void deleteStart();
    void deleteEnd();

    void adjust();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    Node *startNode() const;
    Node *endNode() const;

private:
    Node* start = nullptr;
    Node* end = nullptr;

};

#endif // EDGE_H
