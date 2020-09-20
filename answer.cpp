#include "answer.h"

#include <QFile>

Answer::Answer()
{
    QFile file("newAns.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
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
