#include "edge.h"

void Edge::setStart(Node *node)
{
    start = node;
    start->addEdge(this);
    adjust();
}

void Edge::setEnd(Node *node)
{
    end = node;
    end->addEdge(this);
    adjust();
}

void Edge::deleteStart()
{
    start = nullptr;
}

void Edge::deleteEnd()
{
    end = nullptr;
}

void Edge::adjust()
{
    if(start == nullptr || end == nullptr) return;

    QLineF line(mapFromItem(start, 0, 0), mapFromItem(end, 0, 0));

    prepareGeometryChange();

}

QRectF Edge::boundingRect() const
{

    if(start == nullptr || end == nullptr) return QRectF();

    return QRectF(0,0,100,100);
}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    if(start == nullptr || end == nullptr) return;

    QLineF line(start->x,start->y,end->x,end->y);

    painter->setPen(Qt::black);
    painter->drawLine(line);
}

Node *Edge::startNode() const
{
    return start;
}

Node *Edge::endNode() const
{
    return end;
}
