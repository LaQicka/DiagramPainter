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
    for(int i=0;i<input_connections.size();i++){
        if(!input_connections[i].isBusy){
            input_connections[i].edge = edge;
            input_connections[i].isBusy = true;
            input_edges.append(edge);
            return;
         }
    }
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

bool Form::existInputSlots()
{
    bool flag = 1;
    for(int i=0;i<input_connections.size() && flag;i++)flag = input_connections[i].isBusy;
    return !flag;
}

bool Form::existOutputSlots()
{
    bool flag = 1;
    for(int i=0;i<output_connections.size() && flag;i++)flag = output_connections[i].isBusy;
    return !flag;
}

QPair<int, int> Form::getPos(Edge *edge)
{
    QPair <int,int> ans;

    for(int i=0;i<input_connections.size();i++){
        if(input_connections[i].edge == edge){
            ans.first = this->x + input_connections[i].x_connect;
            ans.second = this->y + input_connections[i].y_connect;
            return ans;
        }
    }

    for(int i=0;i<output_connections.size();i++){
        if(output_connections[i].edge == edge){
            ans.first = x + output_connections[i].x_connect;
            ans.second = y + output_connections[i].y_connect;
            return ans;
        }
    }

    return ans;
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
