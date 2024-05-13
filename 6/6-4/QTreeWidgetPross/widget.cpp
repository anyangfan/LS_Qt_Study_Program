#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 1:添加第一级节点
    QTreeWidgetItem *topItem1=new QTreeWidgetItem(ui->treeWidget);
    topItem1->setText(0,"清华大学");
    topItem1->setCheckState(0,Qt::Checked);
    ui->treeWidget->addTopLevelItem(topItem1);

    // 隐藏表头
    ui->treeWidget->setHeaderHidden(true);
    // 展开节点
    ui->treeWidget->expandAll();

    // 2：二级节点添加到一级节点的topItem1
    QTreeWidgetItem *item11=new QTreeWidgetItem(topItem1);
    item11->setText(0,"清华大学建筑学院");
    item11->setCheckState(0,Qt::Checked);

    QTreeWidgetItem *item12=new QTreeWidgetItem(topItem1);
    item12->setText(0,"清华大学建筑学院");
    item12->setCheckState(0,Qt::Checked);

    QTreeWidgetItem *item13=new QTreeWidgetItem(topItem1);
    item13->setText(0,"清华大学土木学院");
    item13->setCheckState(0,Qt::Checked);

    QTreeWidgetItem *item14=new QTreeWidgetItem(topItem1);
    item14->setText(0,"清华大学信息科学技术学院");
    item14->setCheckState(0,Qt::Checked);

    QTreeWidgetItem *item15=new QTreeWidgetItem(topItem1);
    item15->setText(0,"清华大学马克思主义学院");
    item15->setCheckState(0,Qt::Checked);


    // 3:添加第一级节点
    QTreeWidgetItem *topItem2=new QTreeWidgetItem(ui->treeWidget);
    topItem2->setText(0,"北京大学");
    topItem2->setCheckState(0,Qt::Checked);
    ui->treeWidget->addTopLevelItem(topItem2);

    QTreeWidgetItem *item21=new QTreeWidgetItem(topItem2);
    item21->setText(0,"北京大学数学科学学院");
    item21->setCheckState(0,Qt::Checked);

    QTreeWidgetItem *item22=new QTreeWidgetItem(topItem2);
    item22->setText(0,"北京大学软件与微电子学院");
    item22->setCheckState(0,Qt::Checked);

    QTreeWidgetItem *item23=new QTreeWidgetItem(topItem2);
    item23->setText(0,"北京大学新闻与传播学院");
    item23->setCheckState(0,Qt::Checked);

    QTreeWidgetItem *item24=new QTreeWidgetItem(topItem2);
    item24->setText(0,"北京大学光华管理学院");
    item24->setCheckState(0,Qt::Checked);

    QTreeWidgetItem *item25=new QTreeWidgetItem(topItem2);
    item25->setText(0,"北京大学医学部");
    item25->setCheckState(0,Qt::Checked);


}

Widget::~Widget()
{
    delete ui;
}

