#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new MainScene(this);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
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
    scene->addRect();
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

    Node *n1 = nullptr;
    Node *n2 = nullptr;

    foreach(auto i,ui->graphicsView->scene()->selectedItems()){
        if(n1 == nullptr) n1 = dynamic_cast<Node*>(i);
        else if(n2 == nullptr) n2 = dynamic_cast<Node*>(i);
        else break;
    }

    if(n1 != nullptr && n2 != nullptr){
        Edge* edge;
        edge = new Edge();
        edge->setStart(n1);
        edge->setEnd(n2);

        scene->addItem(edge);
    }
}

