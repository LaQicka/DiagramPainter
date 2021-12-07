#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <mainscene.h>
#include <QVector>
#include <QString>

/// @brief class that processes text file and build diagram for it

class textEditor
{
public:
    MainScene* scene;

/// @brief function to adding new string to text vector
/// @param line -- string line to adding
    void addString(QString line);

/// @brief return size of text vector
    int getTextSize();

/// @brief function that processes block of text and draw it on scene
/// @param start -- index of starting line
/// @param end -- index of ending line
/// @param source -- form that appears like diagram parent of this block
/// @param dest -- form that appears like end of this diagram
/// @param x -- x position of elements of this block
/// @param y -- y position of next element
/// @param index
    void drawBlock(int start, int end, Form* source, Form* dest, int x, int y, int index);

/// @brief function that allows to set keyFlag
/// @param key -- new keyFlag
/// @warning NOT WORKING IN THIS VERSION
    void setKey(QString _key);
private:
    QVector<QString> text;
    QString key;
};

#endif // TEXTEDITOR_H
