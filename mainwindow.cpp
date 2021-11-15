#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new MainScene(this);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    ui->graphicsView->setScene(scene);
    text.scene = scene;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_setText_clicked()
{
    auto i = ui->graphicsView->scene()->selectedItems().at(0);
    Form* f = dynamic_cast<Form*>(i);
    if(f->getType() == 6) return;
    else f->setText(ui->textToSet->text());
}

void MainWindow::on_delete_item_clicked()
{
    if(!scene->first_selected || !scene->second_selected)for(int t = ui->graphicsView->scene()->selectedItems().size();t>0;t--)
    {
        auto i = ui->graphicsView->scene()->selectedItems().at(0);

        Form* f = dynamic_cast<Form*>(i);
        bool flag = 0, exist_end = true;
        QList<Form*> start;
        Form* end;
        if(f->getType() == 6){
            flag = 1;
            if(f->output_connections[0].isBusy)end = f->output_edges[0]->endNode();
            else exist_end = 0;
            foreach(Edge* edge, f->input_edges){
                start.append(edge->startNode());
            }
        }

        scene->deleteForm(f);
        delete i;

        if(flag && exist_end){
            foreach(Form* st, start){
                Edge* edge;
                edge = new Edge();
                edge->setStart(st);
                edge->setEnd(end);
                scene->addItem(edge);
            }
        }
    }
    else{
        QList<Form*> nodes1;
        QList<Form*> nodes2;
        Edge* edge1 = nullptr;
        Edge* edge2 = nullptr;
        bool flag=false,flag1=false,flag2=false;
        Form* i =  scene->first_selected;
        if(i->output_connections.size() == 2){
            edge1 = i->output_connections[0].edge;
            edge2 = i->output_connections[1].edge;
            flag=true;
        }
        else{
            edge1 = i->output_connections[0].edge;
        }
        while(edge1->endNode()!=nullptr && edge1->endNode()->getType()==6){
            i = edge1->endNode();
            edge1 = i->output_connections[0].edge;
            nodes1.append(i);
            if(edge1->endNode()==scene->second_selected)flag1=true;
        }
        while(!flag1 && flag && edge2->endNode()!=nullptr && edge2->endNode()->getType()==6){
            i = edge2->endNode();
            edge2 = i->output_connections[0].edge;
            nodes2.append(i);
            if(edge2->endNode()==scene->second_selected)flag2=true;
        }
        if(flag1){
            foreach(Form* item,nodes1){
                scene->deleteForm(item);
                delete item;
            }
        }
        else if(flag2){
            foreach(Form* item,nodes2){
                scene->deleteForm(item);
                delete item;
            }
        }
    }
}

void MainWindow::on_addNode_clicked(){
    auto i = ui->graphicsView->scene()->selectedItems().at(0);

    Node* source = dynamic_cast<Node*>(i);

    Form* dest = source->output_connections[0].edge->endNode();

    source->output_connections[0].edge->deleteEnd();

    scene->connectForms(source, dest);
}

void MainWindow::on_addRect_clicked()
{
    scene->addRect();
//    if(!scene->first_selected || !scene->second_selected)scene->addRect();
//    else{

//    }
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
    if(n1 != nullptr && n2 != nullptr && n1->existOutputSlots())scene->connectForms(n1,n2);
}

void MainWindow::on_Read_clicked()
{
    QString name = ui->fileName->text();
    QFile file(name);
    QTextStream input(&file);

    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"could not find such file";
    }
    else{
        Ellipsoid* ell1;
        Ellipsoid* ell2;
        ell1 = new Ellipsoid("start");
        ell2 = new Ellipsoid("end");
        scene->addItem(ell1);
        scene->addItem(ell2);
        while(!input.atEnd()){
            QString line = input.readLine();
            text.addString(line);
        }
        text.drawBlock(key,0,text.getTextSize(), ell1,ell2,0,100);
    }
}
