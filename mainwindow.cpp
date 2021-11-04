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
        bool flag = 0;
        QList<Form*> start;
        Form* end;
        if(f->getType() == 6){
            flag = 1;
            end = f->output_edges[0]->endNode();
            foreach(Edge* edge, f->input_edges){
                start.append(edge->startNode());
            }
        }

        scene->deleteForm(f);
        delete i;

        if(flag){
            foreach(Form* st, start){
                Edge* edge;
                edge = new Edge();
                edge->setStart(st);
                edge->setEnd(end);
                scene->addItem(edge);
            }
        }
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
    if(n1 != nullptr && n2 != nullptr && n1->existOutputSlots()){
        Edge* edge1;
        Edge* edge2;
        Node* node;
        node = new Node();
        edge1 = new Edge();
        edge2 = new Edge();
        edge1->setStart(n1);
        edge1->setEnd(node);
        edge2->setStart(node);
        edge2->setEnd(n2);
        scene->addItem(node);
        scene->forms.append(node);
        scene->addItem(edge1);
        scene->addItem(edge2);
    }
}

