#include "romb.h"

void Romb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
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

    QPolygonF item;
//    painter->fillRect(item,brush);
//    painter->drawRect(item);
    item << QPoint(anchor_x,anchor_y+25) << QPoint(anchor_x+125,anchor_y+50) << QPoint(anchor_x+250,anchor_y+25) << QPoint(anchor_x+125,anchor_y) << QPoint(anchor_x,anchor_y+25);
    painter->setBrush(brush);
    painter->drawPolygon(item);
    painter->drawText(boundingRect(), Qt::AlignCenter, textContent);
}
