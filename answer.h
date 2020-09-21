#ifndef ANSWER_H
#define ANSWER_H
#include "item.h"

#include <QMap>

class Answer
{
public:
    Answer();
    ~Answer();
    bool isLoadSuccess = false;
    QList<Item*>* getList(QChar ch);



private:
    QList<Item> data;
    QMap<QChar, QList<Item*>> map;

};

#endif // ANSWER_H
