#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置表格行数和列数
    ui->tableWidget->setRowCount(3);
    ui->tableWidget->setColumnCount(2);

    // 设置水平表头
    QStringList slist;
    slist<<"学号"<<"高考分数";
    ui->tableWidget->setHorizontalHeaderLabels(slist);

    QList<QString> strno;
    strno<<"202201"<<"202202"<<"202203";
    QList<QString> strscore;
    strscore<<"708"<<"712"<<"690";

    // 通过循环为表格赋值
    for(int i=0;i<3;i++)
    {
        int iCol=0;
        QTableWidgetItem *pitem=new QTableWidgetItem(strno.at(i));
        ui->tableWidget->setItem(i,iCol++,pitem);
        ui->tableWidget->setItem(i,iCol,new QTableWidgetItem(strscore.at(i)));
    }


}

Widget::~Widget()
{
    delete ui;
}

