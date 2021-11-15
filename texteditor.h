#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <mainscene.h>
#include <QVector>
#include <QString>

class textEditor
{
public:
    MainScene* scene;
    void addString(QString line);
    int getTextSize();

    void drawBlock(int start, int end, Form* source, Form* dest, int x, int y, int index);
    void setKey(QString _key);
private:
    QVector<QString> text;
    QString key;
};

#endif // TEXTEDITOR_H
