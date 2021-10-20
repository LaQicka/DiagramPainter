#include "form.h"

Form::Form()
{
    Pressed = false;
    setFlag(ItemIsMovable);
    setFlag(ItemIsSelectable);
    x = 0, y = 0;
    x_center = 125;
    y_center = 25;
}

Form::Form(QString text){
    Pressed = false;
    setFlag(ItemIsMovable);
    setFlag(ItemIsSelectable);
    x = 0, y = 0;
    x_center = 125;
    y_center = 25;
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

void Form::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    x = mapToScene(event->pos()).x() - x_center;
    y = mapToScene(event->pos()).y() - y_center;
    x -= x%5;
    y -= y%5;
    this->setPos(x,y);
}
