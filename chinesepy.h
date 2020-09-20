#ifndef CHINESEPY_H
#define CHINESEPY_H

#include <qstring.h>


class ChinesePY
{
public:
    ChinesePY();
    QString static ToChineseSpell(QString strText);


private:


    QString static const strChineseFirstPY;

};

#endif // CHINESEPY_H
