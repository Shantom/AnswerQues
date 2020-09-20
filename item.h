#ifndef ITEM_H
#define ITEM_H
#include<QString>
#include<QStringList>
#include"chinesepy.h"

class Item
{
public:
    Item(QStringList data);

    QString question;
    QString op1;
    QString op2;
    QString op3;
    QString op4;
    QString ans;
    QString inits;
private:


};

#endif // ITEM_H
