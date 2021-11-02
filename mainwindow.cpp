#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new MainScene(this);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
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

    Form *n1 = scene->first_selected;
    Form *n2 = scene->second_selected;

    if(n1 != nullptr && n2 != nullptr && n1->existOutputSlots() && n2->existInputSlots()){
        Edge* edge;
        edge = new Edge();
        edge->setStart(n1);
        edge->setEnd(n2);

        scene->addItem(edge);
    }
}

