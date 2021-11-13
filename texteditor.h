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

    void drawBlock(QString key, int start, int end, Form* source, Form* dest, int x, int y);

private:
    QVector<QString> text;
};

#endif // TEXTEDITOR_H
