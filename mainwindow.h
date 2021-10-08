#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>

#include <form.h>
#include <rect.h>
#include <ellipsoid.h>
#include <romb.h>
#include <opentrapezoid.h>
#include <closetrapezoid.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_addRect_clicked();

    void on_delete_item_clicked();

    void on_addEllipse_clicked();

    void on_addRomb_clicked();

    void on_addTrapezoid_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    QList <Form*> rects;
    QList <Form*> ellips;
    QList <Form*> rombs;
    QList <Form*> openTrapez;
    QList <Form*> closeTrapez;

    QMap <QGraphicsItem*,int> rects_index;
};
#endif // MAINWINDOW_H
