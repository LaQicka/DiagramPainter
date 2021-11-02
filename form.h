#ifndef FORM_H
#define FORM_H

#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QString>
#include <QDebug>
#include <edge.h>

class Edge;
class Form : public QGraphicsItem
{
private:
    struct Connection{
        int x_connect;
        int y_connect;
        bool isBusy = 0;
        Edge* edge;
    };
public:    
    Form();
    Form(QString _text);
    ~Form();

    QRectF boundingRect() const;
    bool Pressed;
    bool Selected = false;

    int getType(){ return type; }
    void setText(QString text);

    void addInputEdge(Edge* edge);
    void addOutputEdge(Edge* edge);

    bool existInputSlots();
    bool existOutputSlots();

    QPair <int,int> getPos(Edge* edge);

    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

    QList <Edge*> input_edges;
    QList <Edge*> output_edges;
    QVector <Connection> input_connections;
    QVector <Connection> output_connections;

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    int x,y;
    qreal x_center, y_center;
protected:

    int type; // 1 - rect, 2 - ellipsoid, 3 - romb , 4 - open trapezoid, 5 - close trapezoid;
    QString textContent;
};

#endif // FORM_H
