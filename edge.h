#ifndef EDGE_H
#define EDGE_H

#include <QGraphicsItem>
#include <QGraphicsLineItem>
#include <QString>
#include <form.h>
#include <cmath>

class Form;
/// @brief class that implements mechanic of connecting scene elements using edges
class Edge : public QGraphicsItem
{
public:

/// @brief function that setting start point of edge
/// @param node -- starting node
    void setStart(Form* node);

/// @brief function that setting end point of edge
/// @param node -- ending node
    void setEnd(Form* node);

/// @brief function that deleting starting point of edge
    void deleteStart();

/// @brief function that deleting ending point of edge
    void deleteEnd();

/// @brief function that prepare scene to rerender
    void adjust();

/// @brief function that return element render borders
    QRectF boundingRect() const;

/// @brief function that allows scene to paint this element
/// @param painter -- scene paint tool
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    Form *startNode() const;
    Form *endNode() const;
    Form* start = nullptr;
    Form* end = nullptr;

private:
    QString textContent;
    int i = 0;
    QPointF source, dest;
};

#endif // EDGE_H
