#include "node.h"

Node::~Node()
{
    foreach(Edge* edge, edges){
        if(edge->startNode() == this) edge->deleteStart();

        else edge->deleteEnd();
    }
}

QRectF Node::boundingRect() const
{
    return QRectF(0,0,10,10);
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QRectF item = boundingRect();
    QBrush brush(Qt::white);

    if(Pressed){
        brush.setColor(Qt::red);
    }
    else{
        brush.setColor(Qt::white);
    }

    if(isSelected()){
        brush.setColor(Qt::green);
    }

    painter->fillRect(item,brush);
    painter->drawRect(item);
}

void Node::addEdge(Edge *edge)
{
    edges.append(edge);
}

QVariant Node::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change)
    {
        case ItemPositionChange:
            foreach(Edge* edge, edges) edge->adjust();
            break;
        default:
            break;
    }

    return QGraphicsItem::itemChange(change,value);
}

void Node::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    x = mapToScene(event->pos()).x() - 5;
    y = mapToScene(event->pos()).y() - 5;
    x -= x%5;
    y -= y%5;
    this->setPos(x,y);
}

