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

    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

    QList <Edge*> input_edges;
    QList <Edge*> output_edges;

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    int x,y;
    qreal x_center, y_center;
protected:

    int type; // 1 - rect, 2 - ellipsoid, 3 - romb , 4 - open trapezoid, 5 - close trapezoid;
    QString textContent;
};

#endif // FORM_H
