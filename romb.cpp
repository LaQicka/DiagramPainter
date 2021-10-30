#include "romb.h"

void Romb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

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

    QPolygonF item;
    item << QPoint(anchor_x,anchor_y+25) << QPoint(anchor_x+125,anchor_y+50) << QPoint(anchor_x+250,anchor_y+25) << QPoint(anchor_x+125,anchor_y) << QPoint(anchor_x,anchor_y+25);
    painter->setBrush(brush);
    painter->drawPolygon(item);
    painter->drawText(boundingRect(), Qt::AlignCenter, textContent);
}
