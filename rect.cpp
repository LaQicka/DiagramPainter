#include "rect.h"

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

    if(isSelected()){
        brush.setColor(Qt::green);
    }

    painter->fillRect(item,brush);
    painter->drawRect(item);
    painter->drawText(boundingRect(), Qt::AlignCenter, textContent);
}

