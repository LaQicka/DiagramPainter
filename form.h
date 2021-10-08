#ifndef FORM_H
#define FORM_H

#include <QGraphicsItem>
#include <QPainter>
#include <QString>

class Form : public QGraphicsItem
{
public:
    Form();
    Form(QString _text);
    QRectF boundingRect() const;
    bool Pressed;

    int getType(){ return type; }
    void setText(QString text);

    int x,y;
protected:
    int type; // 1 - rect, 2 - ellipsoid, 3 - romb , 4 - open trapezoid, 5 - close trapezoid
    QString textContent;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // FORM_H
