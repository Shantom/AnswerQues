#include "answer.h"

#include <QFile>
#include <QDebug>

Answer::Answer()
{
    QFile file("newAns.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"No such file";
        return;
    }
    while (!file.atEnd()) {
        QStringList line = QString(file.readLine()).split(" ", QString::SkipEmptyParts);
        Item item(line);
        data.append(line);
    }
    for(int i=0;i<26;i++){
        QChar ch('A'+i);
        map[ch] = QList<Item*>();
    }

    for(Item& ans : data){
        QChar init = ans.inits[0];
        map[init].append(&ans);
    }
}

Answer::~Answer(){

}

QList<Item *> *Answer::getList(QChar ch)
{
    return &map[ch];
}
