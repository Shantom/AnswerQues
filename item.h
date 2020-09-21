#ifndef ITEM_H
#define ITEM_H
#include<QString>
#include<QStringList>
#include<QTableWidgetItem>
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
    QTableWidgetItem wItemQues;
    QTableWidgetItem wItemOp1;
    QTableWidgetItem wItemOp2;
    QTableWidgetItem wItemOp3;
    QTableWidgetItem wItemOp4;
    QTableWidgetItem wItemAns;
private:


};

#endif // ITEM_H
