#include "item.h"

Item::Item(QStringList data)
{
    question = data[0];
    op1 = data[1];
    op2 = data[2];
    op3 = data[3];
    op4 = data[4];
    ans = data[5];
}
