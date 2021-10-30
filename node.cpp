#include "node.h"

//Node::~Node()
//{
//    foreach(Edge* edge, edges){
//        if(edge->startNode() == this) edge->deleteStart();

//        else edge->deleteEnd();
//    }
//}

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

    if(1){
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




