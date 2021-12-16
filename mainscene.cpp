#include "mainscene.h"

MainScene::MainScene(QObject *parent) : QGraphicsScene()
{
    Q_UNUSED(parent);
}

void MainScene::addingItem(Form *form)
{
    forms.append(form);
    this->addItem(form);
}

void MainScene::addRect(QString text)
{
    Rect* rect;
    rect = new Rect(text);
    forms.append(rect);
    this->addItem(rect);
}

void MainScene::addEllipse(QString text)
{
    Ellipsoid* ellipse;
    ellipse = new Ellipsoid(text);
    forms.append(ellipse);
    this->addItem(ellipse);
}

void MainScene::addRomb(QString text)
{
    Romb* romb;
    romb = new Romb(text);
    forms.append(romb);
    this->addItem(romb);
}

void MainScene::addTrapezoid(QString text)
{
    OpenTrapezoid* opt;
    CloseTrapezoid* clt;
    opt = new OpenTrapezoid(text);
    clt = new CloseTrapezoid();
    forms.append(opt);
    forms.append(clt);
    this->addItem(opt);
    this->addItem(clt);
}

void MainScene::deleteForm(Form* item)
{
    if(item == first_selected){
        first_selected = second_selected;
        second_selected = nullptr;
    }
    else if(item == second_selected){
        second_selected = nullptr;
    }
    forms.removeAll(item);
    this->removeItem(item);
}

void MainScene::connectForms(Form *source, Form *dest)
{
    Edge* edge1;
    Edge* edge2;
    Node* node;
    node = new Node;
    edge1 = new Edge;
    edge2 = new Edge;

    node->x = source->x + (dest->x - source->x)/2 + source->x_center;
    node->y = source->y + (dest->y - source->y)/2;
    node->setPos(node->x,node->y);

    edge1->setStart(source);
    edge1->setEnd(node);
    edge2->setStart(node);
    edge2->setEnd(dest);

    this->addItem(node);
    this->forms.append(node);
    this->addItem(edge1);
    this->addItem(edge2);
}

void MainScene::setPosToForm(int x, int y, Form *form)
{
    form->x = x;
    form->y = y;
    form->setPos(x,y);
}

void MainScene::deleteEdgeBetweenSelected()
{
    QList<Form*> nodes1;
    QList<Form*> nodes2;
    Edge* edge1 = nullptr;
    Edge* edge2 = nullptr;
    bool flag=false,flag1=false,flag2=false;
    Form* i =  this->first_selected;

    if(i->getType()==3){
        if(i->output_connections[0].isBusy)edge1 = i->output_connections[0].edge;
        if(i->output_connections[1].isBusy)edge2 = i->output_connections[1].edge;
        flag=true;
    }
    else{
        if(i->output_connections[0].isBusy)edge1 = i->output_connections[0].edge;
    }
    qDebug()<<1;
    if(!flag){
        if(edge1 && edge1->endNode()==this->second_selected){
            this->first_selected->deleteOutputEdge(edge1);
        }
    }
    else{
        if(edge1 && edge1->endNode()==this->second_selected)this->first_selected->deleteOutputEdge(edge1);
        if(edge2 && edge2->endNode()==this->second_selected)this->first_selected->deleteOutputEdge(edge2);
    }
    qDebug()<<2;
    while(edge1 && edge1->endNode()!=nullptr && edge1->endNode()->getType()==6){
        i = edge1->endNode();
        edge1 = i->output_connections[0].edge;
        nodes1.append(i);
        if(edge1->endNode()==this->second_selected)flag1=true;
    }

    while(edge2 && !flag1 && flag && edge2->endNode()!=nullptr && edge2->endNode()->getType()==6){
        i = edge2->endNode();
        edge2 = i->output_connections[0].edge;
        nodes2.append(i);
        if(edge2->endNode()==this->second_selected)flag2=true;
    }
    if(flag1){
        foreach(Form* item,nodes1){
            this->deleteForm(item);
            delete item;
        }
    }
    else if(flag2){
        foreach(Form* item,nodes2){
            this->deleteForm(item);
            delete item;
        }
    }
    this->update();
}

void MainScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem* item = this->itemAt(event->scenePos(), QTransform());
    Form* f = dynamic_cast<Form*>(item);
    if(f){
        switch (event->button()) {
            case Qt::RightButton:
            {
                if(f == first_selected){
                    first_selected->Selected=false;
                    first_selected=second_selected;
                    second_selected=nullptr;
                }
                else if(f == second_selected){
                    second_selected->Selected = false;
                    second_selected = nullptr;
                }
                else if(first_selected && second_selected){
                    first_selected->Selected=false;
                    first_selected = second_selected;
                    f->Selected=true;
                    second_selected=f;
                }
                else if(first_selected && !second_selected){
                    f->Selected=true;
                    second_selected=f;
                }
                else{
                    f->Selected=true;
                    first_selected=f;
                }
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
