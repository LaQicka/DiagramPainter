#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <QGraphicsItemGroup>
#include <QGraphicsLineItem>
#include <QApplication>
#include <QtSvg/QSvgGenerator>

#include <form.h>
#include <mainscene.h>
#include <texteditor.h>
#include <node.h>
#include <edge.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/// @brief class that realizing main window of application

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

/// @brief function that realize work of adding rect button
    void on_addRect_clicked();

/// @brief function that realize work of deleting item button
    void on_delete_item_clicked();

/// @brief function that realize work of adding ellipse button
    void on_addEllipse_clicked();

/// @brief function that realize work of adding romb button
    void on_addRomb_clicked();

/// @brief function that realize work of adding Trapezoid button
    void on_addTrapezoid_clicked();

/// @brief function that realize work of connect button
    void on_connect_clicked();

/// @brief function that realize work of adding read button
    void on_Read_clicked();

/// @brief function that realize work of adding node button
    void on_addNode_clicked();

/// @brief function that realize work of set text button
    void on_setText_clicked();

/// @brief function that realize work of save button
    void on_save_clicked();

private:
    Ui::MainWindow *ui;
    MainScene *scene;
    QString key = "//?";
    QList <Form*> all;
    textEditor text;
};
#endif // MAINWINDOW_H
