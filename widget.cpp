#include "widget.h"
#include "ui_widget.h"

#include <QStandardItemModel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->horizontalHeader()->setVisible(false);


    QTableWidgetItem *wItem = new QTableWidgetItem(answer.getList('A')->at(0)->wItemQues);
    ui->tableWidget->setItem(0, 0, wItem); //添加到界面

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_lineEdit_textEdited(const QString &str)
{
    QString strU = str.toUpper();
    if(str.isEmpty()){

    }
    else {
        QChar ch = strU.at(0);
        QList<Item*>* list = answer.getList(ch);
        int rowCnt = list->size();
        ui->tableWidget->setRowCount(rowCnt);
        ui->tableWidget->clearContents();
        int row = 0;



        for(Item* item: *list){
            if(item->inits.startsWith(strU)){
                addNewRow(row, item);
                row++;
            }
        }
        ui->tableWidget->setRowCount(row);
    }
}

void Widget::addNewRow(int row, Item * item){
    QTableWidgetItem* question = new QTableWidgetItem(item->wItemQues);
    QTableWidgetItem* op1 = new QTableWidgetItem(item->wItemOp1);
    QTableWidgetItem* op2 = new QTableWidgetItem(item->wItemOp2);
    QTableWidgetItem* op3 = new QTableWidgetItem(item->wItemOp3);
    QTableWidgetItem* op4 = new QTableWidgetItem(item->wItemOp4);
    QTableWidgetItem* ans = new QTableWidgetItem(item->wItemAns);

    ui->tableWidget->setItem(row, colQues, question);
    ui->tableWidget->setItem(row, colOp1, op1);
    ui->tableWidget->setItem(row, colOp2, op2);
    ui->tableWidget->setItem(row, colOp3, op3);
    ui->tableWidget->setItem(row, colOp4, op4);
    ui->tableWidget->setItem(row, colAns, ans);
}
