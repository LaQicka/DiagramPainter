#include "edge.h"

void Edge::setStart(Form *node)
{
    start = node;
    start->addOutputEdge(this);
    adjust();
}

void Edge::setEnd(Form *node)
{
    end = node;
    end->addInputEdge(this);
    adjust();
}

void Edge::deleteStart()
{
    end->input_edges.removeAll(this);
    start = nullptr;
}

void Edge::deleteEnd()
{
    start->output_edges.removeAll(this);
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

    QLineF line(start->x+125,start->y+50,end->x+125,end->y);

    painter->setPen(Qt::black);
    painter->drawLine(line);
}

Form *Edge::startNode() const
{
    return start;
}

Form *Edge::endNode() const
{
    return end;
}
