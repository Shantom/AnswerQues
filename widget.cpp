#include "widget.h"
#include "ui_widget.h"

#include <QClipboard>
#include <QStandardItemModel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setSelectionBehavior ( QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode ( QAbstractItemView::SingleSelection);
    setFixedSize(650, height());
    setWindowTitle("答题");
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

    int a = ans->text().toInt();

    ui->tableWidget->setItem(row, colQues, question);
    ui->tableWidget->setItem(row, colOp1, op1);
    ui->tableWidget->setItem(row, colOp2, op2);
    ui->tableWidget->setItem(row, colOp3, op3);
    ui->tableWidget->setItem(row, colOp4, op4);
    ui->tableWidget->setItem(row, colAns, ans);

    QFont Empha;
    Empha.setBold(true);
    QBrush nullColor(Qt::gray);
    switch (a) {
    case 1:
        op1->setFont(Empha);
        op1->setBackground(nullColor);
        break;
    case 2:
        op2->setFont(Empha);
        op2->setBackground(nullColor);
        break;
    case 3:
        op3->setFont(Empha);
        op3->setBackground(nullColor);
        break;
    case 4:
        op4->setFont(Empha);
        op4->setBackground(nullColor);
        break;
    }
}

void Widget::on_tableWidget_cellDoubleClicked(int row, int column)
{
    QString ans = ui->tableWidget->item(row, colAns)->text();
    QClipboard *board = QApplication::clipboard();
    board->setText(ans);
}
