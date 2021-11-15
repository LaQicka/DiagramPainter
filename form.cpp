#include "form.h"

Form::Form(QString _text)
{
    Pressed = false;
    setFlag(ItemIsMovable);
    setFlag(ItemIsSelectable);
    x = 0, y = 0;
    input.first = 125;
    input.second = 0;
    x_center = 125;
    y_center = 25;
    textContent = _text;
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
    for(int i=0;i<output_connections.size();i++){
        if(!output_connections[i].isBusy){
            output_connections[i].edge = edge;
            output_connections[i].isBusy = true;
            output_edges.append(edge);
            return;
         }
    }
}

bool Form::existOutputSlots()
{
    bool flag = 1;
    for(int i=0;i<output_connections.size() && flag;i++)flag = output_connections[i].isBusy;
    return !flag;
}

QPointF Form::getPos(Edge *edge)
{
    QPointF ans;
    if(type == 6) {
        ans.setX(2);
        ans.setY(2);
        return ans;
    }
    foreach(Edge* ed, input_edges){
        if(ed == edge){
            ans.setX(input.first);
            ans.setY(input.second);
            return ans;
        }
    }

    for(int i=0;i<output_connections.size();i++){
        if(output_connections[i].edge == edge){
            ans.setX(output_connections[i].x_connect);
            ans.setY(output_connections[i].y_connect);
            return ans;
        }
    }

    return ans;
}

QVariant Form::itemChange(GraphicsItemChange change, const QVariant &value)
{
    foreach(Edge* edge, input_edges) edge->adjust();
    foreach(Edge* edge, output_edges) edge->adjust();
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
