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

Form::~Form()
{
    foreach(Edge* edge, input_edges){
        if(edge->startNode() == this) edge->deleteStart();
        else edge->deleteEnd();
    }
    foreach(Edge* edge, output_edges){
        if(edge->startNode() == this) edge->deleteStart();
        else edge->deleteEnd();
    }
}

void Form::setText(QString _text){
    textContent = _text;
}

void Form::addInputEdge(Edge *edge)
{
    input_edges.append(edge);
}

void Form::addOutputEdge(Edge *edge)
{
    output_edges.append(edge);
}

QVariant Form::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change)
    {
        case ItemPositionChange:
            foreach(Edge* edge, input_edges) edge->adjust();
            foreach(Edge* edge, output_edges) edge->adjust();
            break;
        default:
            break;
    }

    return QGraphicsItem::itemChange(change,value);
}

QRectF Form::boundingRect() const
{
    return QRectF(0,0,250,50);
}

void Form::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = true;
    setSelected(true);
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
