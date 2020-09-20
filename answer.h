#ifndef ANSWER_H
#define ANSWER_H
#include "item.h"

#include <QMap>

class Answer
{
public:
    Answer();
    bool isLoadSuccess = false;


private:
    QList<Item> data;
    QMap<QChar, QList<Item*>> map;

};

#endif // ANSWER_H
