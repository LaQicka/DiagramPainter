#include "texteditor.h"

void textEditor::addString(QString line)
{
    text.push_back(line);
}

int textEditor::getTextSize()
{
    return text.size();
}

void textEditor::drawBlock(QString key, int start, int end, Form *source, Form *dest, int x, int y)
{
    int main_x = source->x;
    for(int i = start;i < end;i++){

        //Parsing of string
        QString type, condition, action, buff, comment;
        bool type_found = false, condition_found = false, key_found = false;
        {
            QChar t1,t2;
            int j = 0;
            int open = 0,close = 0;
            while(j<text[i].size() && (text[i][j] == '\t' || text[i][j] == ' ')) j++;
            for(;j<text[i].size();j++){

                if(!key_found){
                    buff = t1, buff+=t2, buff+=text[i][j];
                    if(buff == key) key_found = true;
                    t1 = t2;
                    t2 = text[i][j];
                }
                else if(key_found)comment+=text[i][j];

                if(!type_found && !key_found){
                    action+=text[i][j];
                }

                if(j<6 && !type_found){
                    type+=text[i][j];
                    if(type == "if" || type == "for" || type == "while" || type == "switch"){
                        type_found = true;
                        action.clear();
                    }
                }

                if(type_found && !condition_found){
                    if(text[i][j] == ')') close++;
                    if(open && open!=close)condition+=text[i][j];
                    if(open && open==close)condition_found = true;
                    if(text[i][j] == '(') open++;
                }
            }
        }

        //adding blocks to scene

        if(!type_found && key_found){
            qDebug()<<1;
            Rect* rect;
            rect = new Rect(comment);
            scene->addingItem(rect);
            scene->setPosToForm(x,y,rect);
            y += 100;
            scene->connectForms(source,rect);
            source = rect;
        }
        else if(type == "if" && key_found){
            Romb* romb;
            Node* node;
            romb = new Romb(condition);
            node = new Node;
            scene->addingItem(romb);
            scene->addingItem(node);
            scene->setPosToForm(x,y,romb);
            y+=100;
            scene->connectForms(source,romb);

            int open = 1, close = 0, j = i+1;
            for(;j<end;j++){
                for(int t=0;t<text[j].size();t++){
                    if(text[j][t] == '}') close++;
                    else if(text[j][t] == '{') open++;
                }
                if(open == close)break;
            }
            drawBlock(key,i+1,j,romb,node,x,y);
            i = ++j;

            QString temp;
            int t=0;
            while(t<text[j].size() && (text[j][t] == '\t' || text[j][t] == ' ')) t++;
            for(;t<text[j].size();t++){
                temp+=text[j][t];
                if(temp == "else" || temp.size() == 4)break;
            }
            if(temp == "else"){
                open = 1, close = 0, t = 0;
                for(;j<end;j++){
                    for(;t<text[j].size();t++){
                        if(text[j][t] == '}') close++;
                        else if(text[j][t] == '{') open++;
                    }
                    if(open == close)break;
                }
                drawBlock(key,i+1,j-1,romb,node,x+300,y);
                i = j+1;
            }
            else{
                scene->connectForms(romb,node);
                scene->setPosToForm(x,y,node);
            }

            source = node;
            y = node->y;
        }
    }
    scene->setPosToForm(main_x,source->y+100,dest);
    scene->connectForms(source,dest);
}
