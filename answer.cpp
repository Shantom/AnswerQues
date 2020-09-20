#include "answer.h"

#include <QFile>

Answer::Answer()
{
    QFile file("newAns.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    while (!file.atEnd()) {
        QStringList line = QString(file.readLine()).split(" ");
        Item item(line);
        data.append(line);
    }
}
