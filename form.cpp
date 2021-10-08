#include "form.h"

Form::Form()
{
    Pressed = false;
    setFlag(ItemIsMovable);
    setFlag(ItemIsSelectable);
    x = 100, y = 100;
}

Form::Form(QString text){
    Pressed = false;
    setFlag(ItemIsMovable);
    setFlag(ItemIsSelectable);
    x = 100, y = 100;
    textContent = text;
}

void Form::setText(QString _text){
    textContent = _text;
}

QRectF Form::boundingRect() const
{
    return QRectF(0,0,250,50);
}

void Form::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = true;
    setSelected(false);
    update();
    QGraphicsItem::mousePressEvent(event);
}

void Form::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = false;
    setSelected(false);
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
