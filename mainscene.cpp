#include "mainscene.h"


MainScene::MainScene(QObject *parent) : QGraphicsScene()
{
    Q_UNUSED(parent);
}

void MainScene::addRect()
{
    Rect* rect;
    rect = new Rect("Rect");
    forms.append(rect);
    this->addItem(rect);
}

void MainScene::addEllipse()
{
    Ellipsoid* ellipse;
    ellipse = new Ellipsoid("Ellipse");
    forms.append(ellipse);
    this->addItem(ellipse);
}

void MainScene::addRomb()
{
    Romb* romb;
    romb = new Romb("Romb");
    forms.append(romb);
    this->addItem(romb);
}

void MainScene::addTrapezoid()
{
    OpenTrapezoid* opt;
    CloseTrapezoid* clt;
    opt = new OpenTrapezoid("Open Trapezoid");
    clt = new CloseTrapezoid("Close Trapezoid");
    forms.append(opt);
    forms.append(clt);
    this->addItem(opt);
    this->addItem(clt);
}

void MainScene::deleteForm(Form* item)
{
    forms.removeAll(item);
}

