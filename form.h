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
/// @brief class that is the heir of QGraphicsItem and parent for different scene elements
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
    Form(QString _text = "");
    ~Form();

/// @brief function that return element render borders
    QRectF boundingRect() const;
    bool Pressed;
    bool Selected = false;

/// @brief return type of element
    int getType(){ return type; }

/// @brief set text content of element
/// @param text -- new text content
    void setText(QString text);

/// @brief function to adding input edge to element
/// @param edge -- pointer to this edge
    void addInputEdge(Edge* edge);

/// @brief function to adding output edge to element
/// @param edge -- pointer to this edge
    void addOutputEdge(Edge* edge);

    void deleteInputEdge(Edge* edge);

    void deleteOutputEdge(Edge* edge);

/// @brief bool function that help others detect if exist input slots for edges
    bool existInputSlots();

/// @brief bool function that help others detect if exist output slots for edges
    bool existOutputSlots();

/// @brief function that returns scene position of connecting slot
/// @param edge -- pointer to this edge
    QPointF getPos(Edge* edge);

/// @brief function that allows to catch changing of element
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

    QList <Edge*> input_edges;
    QList <Edge*> output_edges;
    QPair<int,int> input;
    QVector <Connection> output_connections;

/// @brief function that allows to catch pressing of mouse button
/// @param event -- scene mouse event
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

/// @brief function that allows to catch pressing of mouse button
/// @param event -- scene mouse event
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    int x,y;
    qreal x_center, y_center;
protected:

    int type; // 1 - rect, 2 - ellipsoid, 3 - romb , 4 - open trapezoid, 5 - close trapezoid;
    QString textContent;
};

#endif // FORM_H
