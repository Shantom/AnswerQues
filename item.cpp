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
    wItemQues.setFlags(Qt::ItemFlag::ItemIsEnabled|Qt::ItemFlag::ItemIsSelectable);
    wItemOp1.setText(op1);
    wItemOp1.setFlags(Qt::ItemFlag::ItemIsEnabled|Qt::ItemFlag::ItemIsSelectable);
    wItemOp2.setText(op2);
    wItemOp2.setFlags(Qt::ItemFlag::ItemIsEnabled|Qt::ItemFlag::ItemIsSelectable);
    wItemOp3.setText(op3);
    wItemOp3.setFlags(Qt::ItemFlag::ItemIsEnabled|Qt::ItemFlag::ItemIsSelectable);
    wItemOp4.setText(op4);
    wItemOp4.setFlags(Qt::ItemFlag::ItemIsEnabled|Qt::ItemFlag::ItemIsSelectable);
    wItemAns.setText(ans);
    wItemAns.setFlags(Qt::ItemFlag::ItemIsEnabled|Qt::ItemFlag::ItemIsSelectable);

}
