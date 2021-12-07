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

/// @brief This class is the heir of QGraphicsScene, allows to make custom realization of mouse signals

class MainScene : public QGraphicsScene
{
public:
    explicit MainScene(QObject* parent = nullptr);

/// @brief function to adding item on scene using its pointer
/// @param form -- pointer to this item
    void addingItem(Form* form);

/// @brief function to adding rect on scene
/// @param text -- text content of rect item
    void addRect(QString text = "");

/// @brief function to adding ellipse on scene
/// @param text -- text content of ellipse item
    void addEllipse(QString text = "");

/// @brief function to adding romb on scene
/// @param text -- text content of romb item
    void addRomb(QString text = "");

/// @brief function to adding OpenTrapezoid and CloseTrapezoid on scene
/// @param text -- text content of OpenTrapezoid item
    void addTrapezoid(QString text = "");

/// @brief function to deleting item from scene using its pointer
/// @param item -- item that should be deleted
    void deleteForm(Form* item);

/// @brief function, that allows scene to connect 2 items with edge
/// @param source -- item where edge start
/// @param dest -- item where edge end
    void connectForms(Form* source, Form* dest);

/// @brief function, that allows scene to set position using the pointer of element
/// @param x -- x position of element
/// @param y -- y position of element
/// @param form -- pointer of element
    void setPosToForm(int x,int y,Form* form);

/// @brief function that catch mousePressEvent and realize custom work of it
/// @param event -- scene mouse event
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

/// @brief function that catch mouseReleaseEvent and realize custom work of it
/// @param event -- scene mouse event
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

/// @brief function that catch mouseMoveEvent and realize custom work of it
/// @param event -- scene mouse event
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    Form* first_selected = nullptr;
    Form* second_selected = nullptr;
    QList <Form*> forms;
private:
    Form* pressedItem = nullptr;

};

#endif // MAINSCENE_H
