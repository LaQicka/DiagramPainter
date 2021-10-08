#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addRect_clicked()
{
    int x=100,y=100;
    Rect* rect;
    rect = new Rect("Rect");
    rects.append(rect);
    rect->setPos(x,y);
    scene->addItem(rect);
}

void MainWindow::on_delete_item_clicked()
{
    for(int t = ui->graphicsView->scene()->selectedItems().size();t>0;t--)
    {
        auto i = ui->graphicsView->scene()->selectedItems().at(0);

        Form* f = dynamic_cast<Form*>(i);

        if(f->getType() == 1) ellips.removeAll(f);
        else if(f->getType() == 2) rects.removeAll(f);
        else if(f->getType() == 3) rombs.removeAll(f);
        else if(f->getType() == 4) openTrapez.removeAll(f);
        else if(f->getType() == 5) closeTrapez.removeAll(f);

        ui->graphicsView->scene()->removeItem(i);
        delete i;
    }
    qDebug() << rects.size() << " " << ellips.size() << " " << rombs.size() << " " <<openTrapez.size()<< " " << closeTrapez.size();
}


void MainWindow::on_addEllipse_clicked()
{
    int x=100,y=100;
    Ellipsoid* ellipse;
    ellipse = new Ellipsoid("ellips");
    ellips.append(ellipse);
    ellipse->setPos(x,y);
    scene->addItem(ellipse);
}


void MainWindow::on_addRomb_clicked()
{
    int x=100,y=100;
    Romb* romb;
    romb = new Romb("Romb");
    rombs.append(romb);
    romb->setPos(x,y);
    scene->addItem(romb);
}


void MainWindow::on_addTrapezoid_clicked()
{
    int x=100,y=100;
    OpenTrapezoid* opt;
    CloseTrapezoid* clt;
    opt = new OpenTrapezoid("Open Trapezoid");
    clt = new CloseTrapezoid("Close Trapezoid");
    openTrapez.append(opt);
    closeTrapez.append(clt);
    opt->setPos(x,y);
    clt->setPos(x,y);
    scene->addItem(opt);
    scene->addItem(clt);

}

