#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new MainScene(this);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    //ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    //ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_delete_item_clicked()
{
    for(int t = ui->graphicsView->scene()->selectedItems().size();t>0;t--)
    {
        auto i = ui->graphicsView->scene()->selectedItems().at(0);

        Form* f = dynamic_cast<Form*>(i);

        scene->deleteForm(f);

        ui->graphicsView->scene()->removeItem(i);
        delete i;
    }
}

void MainWindow::on_addRect_clicked()
{
    //scene->addRect();

    Node* node1;
    Node* node2;
    node1 = new Node();
    node2 = new Node();

    node1->addNode(node2);

    scene->addItem(node1);
    scene->addItem(node2);

}

void MainWindow::on_addEllipse_clicked()
{
    scene->addEllipse();
}

void MainWindow::on_addRomb_clicked()
{
    scene->addRomb();
}

void MainWindow::on_addTrapezoid_clicked()
{
    scene->addTrapezoid();
}


void MainWindow::on_connect_clicked()
{
    for(int t = ui->graphicsView->scene()->selectedItems().size();t>0;t--)
    {
        auto i = ui->graphicsView->scene()->selectedItems().at(0);

        Node* f = dynamic_cast<Node*>(i);
        qDebug()<<f->getPos().first<<" "<<f->getPos().second<<" --- "<<ui->graphicsView->scene()->selectedItems().at(0)->pos().x()<<" "<<ui->graphicsView->scene()->selectedItems().at(0)->pos().y();
    }
}

