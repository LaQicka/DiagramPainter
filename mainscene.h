#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QGraphicsScene>
#include <QGuiApplication>
#include <QGraphicsItem>
#include <QList>

#include <form.h>
#include <rect.h>
#include <ellipsoid.h>
#include <romb.h>
#include <opentrapezoid.h>
#include <closetrapezoid.h>

class MainScene : public QGraphicsScene
{
public:
    explicit MainScene(QObject* parent = nullptr);

    void addRect();
    void addEllipse();
    void addRomb();
    void addTrapezoid();
    void deleteForm(Form* item);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    Form* first_selected = nullptr;
    Form* second_selected = nullptr;
private:
    QList <Form*> forms;
    Form* pressedItem = nullptr;

};

#endif // MAINSCENE_H
