#include "edge.h"

void Edge::setStart(Form *node)
{
    start = node;
    start->addOutputEdge(this);
    if(start->getType() == 3){
        for(int i=0;i<start->output_connections.size();i++){
            if(i == 0 && start->output_connections[i].edge == this) textContent = "true";
            else if(textContent.isEmpty()) textContent = "false";
        }
    }
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
    textContent.clear();
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

    QLineF line(mapFromItem(start,0,0), mapFromItem(end, 0, 0));

    prepareGeometryChange();
    source = line.p1()+start->getPos(this);
    dest = line.p2()+end->getPos(this);
}

QRectF Edge::boundingRect() const
{
    if(start == nullptr || end == nullptr)return QRectF();

    return QRectF(source, QSizeF(dest.x()-source.x(),dest.y()-source.y())).normalized();
}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    if(start == nullptr || end == nullptr)return;

    QLineF line(source,dest);
    painter->setPen(Qt::black);
    painter->drawLine(line);
    painter->drawText(source,textContent);
}

Form *Edge::startNode() const
{
    return start;
}

Form *Edge::endNode() const
{
    return end;
}
