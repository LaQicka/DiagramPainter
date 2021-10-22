#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QGraphicsScene>
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

private:
    QList <Form*> forms;

};

#endif // MAINSCENE_H
