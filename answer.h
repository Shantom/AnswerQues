#ifndef ANSWER_H
#define ANSWER_H
#include "item.h"

class Answer
{
public:
    Answer();
    bool isLoadSuccess = false;


private:
    QList<Item> data;

};

#endif // ANSWER_H
