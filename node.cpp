#include "node.h"

Node::Node()
{
    Pressed = false;
    setFlag(ItemIsMovable);
    setFlag(ItemIsSelectable);
    x = 0, y = 0;
    type = 6;
    x_center = 4;
    y_center = 4;
    output_connections.resize(1);
    output_connections[0].x_connect = 4;
    output_connections[0].y_connect = 4;
}

QRectF Node::boundingRect() const
{
    return QRectF(0,0,8,8);
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

        if(Selected){
            brush.setColor(Qt::blue);
        }

        if(isSelected()){
            brush.setColor(Qt::green);
        }

        painter->fillRect(item,brush);
        painter->drawRect(item);
}
