#include "mainscene.h"


MainScene::MainScene(QObject *parent) : QGraphicsScene()
{
    Q_UNUSED(parent);
}

void MainScene::addRect()
{
    Rect* rect;
    rect = new Rect();
    forms.append(rect);
    this->addItem(rect);
}

void MainScene::addEllipse()
{
    Ellipsoid* ellipse;
    ellipse = new Ellipsoid();
    forms.append(ellipse);
    this->addItem(ellipse);
}

void MainScene::addRomb()
{
    Romb* romb;
    romb = new Romb();
    forms.append(romb);
    this->addItem(romb);
}

void MainScene::addTrapezoid()
{
    OpenTrapezoid* opt;
    CloseTrapezoid* clt;
    opt = new OpenTrapezoid();
    clt = new CloseTrapezoid();
    forms.append(opt);
    forms.append(clt);
    this->addItem(opt);
    this->addItem(clt);
}

void MainScene::deleteForm(Form* item)
{
    forms.removeAll(item);
}

void MainScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem* item = this->itemAt(event->scenePos(), QTransform());
    Form* f = dynamic_cast<Form*>(item);

    if(f){
        switch (event->button()) {
            case Qt::RightButton:
            {
                if(first_selected)first_selected->Selected = false;
                f->Selected = true;
                first_selected = second_selected;
                second_selected = f;
                break;
            }
            default:
                break;
        }
    }

    QGraphicsScene::mousePressEvent(event);
    pressedItem = f;
}

void MainScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem* item = this->itemAt(event->scenePos(), QTransform());
    Form* f = dynamic_cast<Form*>(item);

    if(f)this->sendEvent(f,event);
    QGraphicsScene::mouseReleaseEvent(event);
    pressedItem = nullptr;

}

void MainScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    Form* f = nullptr;
    if(this->selectedItems().size()){
        QGraphicsItem* item = this->selectedItems().at(0);
        f = dynamic_cast<Form*>(item);
    }
    QGraphicsScene::mouseMoveEvent(event);
    if(f){
        f->x=event->scenePos().x()-f->x_center;
        f->y=event->scenePos().y()-f->y_center;
        f->x -= f->x%5;
        f->y -= f->y%5;
        f->setPos(f->x,f->y);
    }
}

