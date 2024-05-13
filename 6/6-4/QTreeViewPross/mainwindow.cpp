#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitTreeViewFunc(); // 在构造函数调用树视图控件
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitTreeViewFunc() // 初始化树视图控件
{
    // 1：构造model
    sItemMode = new QStandardItemModel(ui->treeView);
    sItemMode->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("编号") << QStringLiteral("初中部|高中部"));     //设置列头

    // 创建一级节点，将它加入到sItemModel
    QList<QStandardItem*> item11;
    QStandardItem *item1=new QStandardItem(QString::number(1));
    QStandardItem *item2=new QStandardItem("初中部");
    item11.append(item1);
    item11.append(item2);
    sItemMode->appendRow(item11);


    // 二级节点，添加到第一个一级节点
    QList<QStandardItem*> item112;
    QStandardItem *item1121=new QStandardItem(QString::number(2));
    QStandardItem *item1122=new QStandardItem(QStringLiteral("一年级"));

    item112.append(item1121);
    item112.append(item1122);
    item1->appendRow(item112);

    // 三级节点，添加到第一个二级节点
    QList<QStandardItem*> item1231;
    QStandardItem *item12311=new QStandardItem(QString::number(3));
    QStandardItem *item12312=new QStandardItem(QStringLiteral("一班"));
    item1231.append(item12311);
    item1231.append(item12312);
    item1121->appendRow(item1231);

    QList<QStandardItem*> item1232;
    QStandardItem *item12321=new QStandardItem(QString::number(3));
    QStandardItem *item12322=new QStandardItem(QStringLiteral("二班"));
    item1232.append(item12321);
    item1232.append(item12322);
    item1121->appendRow(item1232);

    QList<QStandardItem*> item1233;
    QStandardItem *item12331=new QStandardItem(QString::number(3));
    QStandardItem *item12332=new QStandardItem(QStringLiteral("三班"));
    item1233.append(item12331);
    item1233.append(item12332);
    item1121->appendRow(item1233);





    // 创建一级节点，将它加入到sItemModel
    QList<QStandardItem*> item12;

    QStandardItem *item3=new QStandardItem(QString::number(2));
    QStandardItem *item4=new QStandardItem("高中部");

    item12.append(item3);
    item12.append(item4);
    sItemMode->appendRow(item12);



    // 2：给QTreeView应用model
    ui->treeView->setModel(sItemMode);


}
