#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QList>
#include <QStack>
#include <QDebug>
#include <QGraphicsItemGroup>
#include <QGraphicsLineItem>


#include <form.h>
#include <mainscene.h>
#include <node.h>
#include <edge.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void drawDiagram();

private slots:

    void on_addRect_clicked();

    void on_delete_item_clicked();

    void on_addEllipse_clicked();

    void on_addRomb_clicked();

    void on_addTrapezoid_clicked();

    void on_connect_clicked();

    void on_Read_clicked();

    void on_addNode_clicked();

    void on_setText_clicked();

private:
    Ui::MainWindow *ui;
    MainScene *scene;
    QString key = "//?";
    QList <Form*> all;

    struct diagramElement{
        QString type;
        QString condition;
        QString action;
        QString buffer;
        QString comment;
    };

public:
    QList<diagramElement> elements;
};
#endif // MAINWINDOW_H
