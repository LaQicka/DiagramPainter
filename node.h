#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QList>
#include <QPainter>

#include <form.h>
#include <edge.h>
#include <mainscene.h>

class Edge;
class Node : public Form
{
public:

    ~Node();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void addEdge(Edge* edge);

    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

    MainScene* scene;
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
private:
public:
QList <Edge*> edges;
};

#endif // NODE_H
