#include "node.h"

Node::Node()
{
    setFlag(ItemIsMovable);
    setFlag(ItemIsSelectable);
    x = 0, y = 0;
    x_center = 5;
    y_center = 5;
    edgeNumber = 0;
}

QRectF Node::boundingRect() const
{
    return QRectF(0,0,10,10);
}

void Node::addNode(Node *newNode)
{
    this->edges.push_back(newNode);
}

QPair<int, int> Node::getPos()
{
    QPair<int,int> pos;
    pos.first = x;
    pos.second = y;
    return pos;
}

void Node::setPos(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QRectF item = boundingRect();
    QBrush brush(Qt::black);

    painter->setPen(Qt::black);
    painter->fillRect(item,brush);
    painter->drawRect(item);

    for(int i=0;i<edges.size();i++){
        QPair<int,int> pos = edges[i]->getPos();
        QLine line(x,y,pos.first,pos.second);
        painter->drawLine(line);
        qDebug()<<x<<"-"<<y<<" "<<pos.first<<"-"<<pos.second;
    }
}

