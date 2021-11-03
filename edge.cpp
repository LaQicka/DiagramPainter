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
    for(int i=0;i<start->output_connections.size();i++){
        if(start->output_connections[i].edge == this){
            start->output_connections[i].edge = nullptr;
            start->output_connections[i].isBusy = false;
            break;
        }
    }
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

    QPair <int,int> st,en;
    st = start->getPos(this);
    en = end->getPos(this);

    QLineF line(st.first,st.second,en.first,en.second);

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
