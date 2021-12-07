#include "texteditor.h"

void textEditor::addString(QString line)
{
    text.push_back(line);
}

int textEditor::getTextSize()
{
    return text.size();
}

void textEditor::drawBlock(int start, int end, Form *source, Form *dest, int x, int y, int index)
{
    int main_x = source->x;
    for(int i = start;i < end;i++){

        //Parsing of string
        QString type, condition, action, buff, comment;
        bool type_found = false, condition_found = false, key_found = false;
        if(index) key_found = true;
        {
            QChar t1,t2;
            int l = index;
            int open = 0,close = 0;
            while(l<text[i].size() && (text[i][l] == '\t' || text[i][l] == ' ')) l++;
            for(int j = 0;j+l<text[i].size();j++){

                if(!key_found){
                    buff = t1, buff+=t2, buff+=text[i][j+l];
                    if(buff == key) key_found = true;
                    t1 = t2;
                    t2 = text[i][j+l];
                }
                else if(key_found)comment+=text[i][j+l];

                if(!type_found && !key_found){
                    action+=text[i][j+l];
                }

                if(j<6 && !type_found){
                    type+=text[i][j+l];
                    if(type == "if" || type == "for" || type == "while" || type == "switch"){
                        action.clear();
                        type_found = true;
                    }
                }

                if(type_found && !condition_found){
                    if(text[i][j+l] == ')') close++;
                    if(open && open!=close)condition+=text[i][j+l];
                    if(open && open==close)condition_found = true;
                    if(text[i][j+l] == '(') open++;
                }
            }
        }
        if(key_found)qDebug()<<comment;
        //adding blocks to scene
        // action block
        if(!type_found && key_found){
            Rect* rect;
            rect = new Rect(comment);
            scene->addingItem(rect);
            scene->setPosToForm(x,y,rect);
            y += 150;
            scene->connectForms(source,rect);
            source = rect;
        }

        // if block
        else if(type == "if" && key_found){
            Romb* romb;
            Node* node;
            romb = new Romb(condition);
            node = new Node;
            scene->addingItem(romb);
            scene->addingItem(node);
            scene->setPosToForm(x,y,romb);
            y+=150;
            scene->connectForms(source,romb);

            int open = 1, close = 0, k = i+1;
            for(;k<end;k++){
                for(int t=0;t<text[k].size();t++){
                    if(text[k][t] == '}') close++;
                    else if(text[k][t] == '{') open++;
                }
                if(open == close)break;
            }
            drawBlock(i+1,k,romb,node,x,y,0);
            i = ++k;

            QString temp;
            int t=0, index_toNext;
            bool exist_else=false, exist_if=false;
            while(t<text[k].size()){
                if(text[k][t] == '\t' || text[k][t] == ' ')t++;
                else{
                    temp+=text[k][t];
                    t++;
                    if(temp == "else"){
                        exist_else = true;
                        temp.clear();
                        index_toNext = t;
                    }
                    if(temp == "if"){
                        exist_if = true;
                        temp.clear();
                        break;
                    }
                }
            }
            if(exist_else){
                open = 1, close = 0, t = 0;
                for(;k<end;k++){
                    for(;t<text[k].size();t++){
                        if(text[k][t] == '}') close++;
                        else if(text[k][t] == '{') open++;
                    }
                    if(open == close)break;
                }
                if(exist_if)drawBlock(i,k-1,romb,node,x+300,y,index_toNext);
                else drawBlock(i+1,k-1,romb,node,x+300,y,0);
                i = k+1;
            }
            else{
                scene->connectForms(romb,node);
                scene->setPosToForm(x,y,node);
            }

            source = node;
            y = node->y;
        }

        // for block
        else if(type == "for" && key_found){
            qDebug()<<1;
            OpenTrapezoid* opt;
            CloseTrapezoid* cpt;
            opt = new OpenTrapezoid(condition);
            cpt = new CloseTrapezoid;
            scene->addingItem(opt);
            scene->addingItem(cpt);
            scene->setPosToForm(x,y,opt);
            y+=150;
            scene->connectForms(source,opt);

            int open = 1, close = 0, k = i+1;
            for(;k<end;k++){
                for(int t=0;t<text[k].size();t++){
                    if(text[k][t] == '}') close++;
                    else if(text[k][t] == '{') open++;
                }
                if(open == close)break;
            }
            drawBlock(i+1,k,opt,cpt,x,y,0);
            source = cpt;
            y = cpt->y + 150;
            i = k;
        }

        // while block
        else if(type == "while" && key_found){
            Romb* romb;
            Node* node;
            romb = new Romb(condition);
            node = new Node;
            scene->addingItem(romb);
            scene->addingItem(node);
            scene->setPosToForm(x,y,romb);
            y+=150;
            scene->connectForms(source,romb);

            int open = 1, close = 0, k = i+1;
            for(;k<end;k++){
                for(int t=0;t<text[k].size();t++){
                    if(text[k][t] == '}') close++;
                    else if(text[k][t] == '{') open++;
                }
                if(open == close) break;
            }
            drawBlock(i+1,k,romb,node,x,y,0);
            i = k + 1;
            y = node->y;
            scene->connectForms(node,romb);
            source = romb;
        }
    }
    scene->setPosToForm(main_x,source->y+100,dest);
    scene->connectForms(source,dest);
}

void textEditor::setKey(QString _key)
{
    key = _key;
}
