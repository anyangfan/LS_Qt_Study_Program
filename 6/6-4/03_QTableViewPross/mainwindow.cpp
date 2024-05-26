#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitTableViewFunc();  // 调用自定义函数
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::InitTableViewFunc()
{
    // 1:添加表头，准备数据模型
    QStandardItemModel *stuMode=new QStandardItemModel();
    stuMode->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("学号")));
    stuMode->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("姓名")));
    stuMode->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("性别")));
    stuMode->setHorizontalHeaderItem(3,new QStandardItem(QObject::tr("分数")));

    // 通过API函数将数据模型绑定到QTableView
    ui->tableView->setModel(stuMode);

    // 设备表格列的宽度
    ui->tableView->setColumnWidth(0,120);

    // 2:添加数据信息
    stuMode->setItem(0,0,new QStandardItem("2022001"));
    stuMode->setItem(0,1,new QStandardItem("张三"));
    stuMode->setItem(0,2,new QStandardItem("男"));
    stuMode->setItem(0,3,new QStandardItem("714"));

    stuMode->setItem(1,0,new QStandardItem("2022002"));
    stuMode->setItem(1,1,new QStandardItem("小花"));
    stuMode->setItem(1,2,new QStandardItem("女"));
    stuMode->setItem(1,3,new QStandardItem("720"));

    stuMode->setItem(2,0,new QStandardItem("2022003"));
    stuMode->setItem(2,1,new QStandardItem("小妮"));
    stuMode->setItem(2,2,new QStandardItem("女"));
    stuMode->setItem(2,3,new QStandardItem("657"));

    // 禁止编辑
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 排序操作
    stuMode->sort(3,Qt::DescendingOrder);


}
