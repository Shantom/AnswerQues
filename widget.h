#ifndef WIDGET_H
#define WIDGET_H

#include "answer.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    enum FieldColNum{colQues=0,colOp1,colOp2,colOp3,colOp4,colAns};

private slots:
    void on_lineEdit_textEdited(const QString &arg1);

private:
    Ui::Widget *ui;
    Answer answer;

    void addNewRow(int row, Item *item);
};
#endif // WIDGET_H
