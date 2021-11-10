#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QGraphicsScene>
#include <QGuiApplication>
#include <QGraphicsItem>
#include <QList>
#include <QString>

#include <form.h>
#include <node.h>
#include <rect.h>
#include <ellipsoid.h>
#include <romb.h>
#include <opentrapezoid.h>
#include <closetrapezoid.h>

class MainScene : public QGraphicsScene
{
public:
    explicit MainScene(QObject* parent = nullptr);

    void addRect(QString text = "");
    void addEllipse(QString text = "");
    void addRomb(QString text = "");
    void addTrapezoid(QString text = "");
    void deleteForm(Form* item);

    void connectForms(Form* source, Form* dest);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    Form* first_selected = nullptr;
    Form* second_selected = nullptr;
    QList <Form*> forms;
private:
    Form* pressedItem = nullptr;

};

#endif // MAINSCENE_H
