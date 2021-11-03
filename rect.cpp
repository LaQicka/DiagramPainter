#include "rect.h"

Rect::Rect() : Form()
{
    type = 2;
    output_connections.resize(1);
    output_connections[0].x_connect = 125;
    output_connections[0].y_connect = 50;
}

void Rect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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

    if(Selected){
        brush.setColor(Qt::blue);
    }

    if(isSelected()){
        brush.setColor(Qt::green);
    }

    painter->fillRect(item,brush);
    painter->drawRect(item);
    painter->drawText(boundingRect(), Qt::AlignCenter, textContent);
}


