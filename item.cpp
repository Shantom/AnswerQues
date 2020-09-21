#include "item.h"

Item::Item(QStringList data)
{
    question = data[0];
    op1 = data[1];
    op2 = data[2];
    op3 = data[3];
    op4 = data[4];
    ans = data[5].trimmed();
    inits = ChinesePY::ToChineseSpell(question);

    wItemQues.setText(question);
    wItemOp1.setText(op1);
    wItemOp2.setText(op2);
    wItemOp3.setText(op3);
    wItemOp4.setText(op4);
    wItemAns.setText(ans);

}
