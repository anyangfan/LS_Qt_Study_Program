#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QDockWidget>
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDockWidget *dw=new QDockWidget("停靠窗口部件测试：Dock Widget-->Vico",this);

    // 设置颜色
    QPalette pal;
    pal.setColor(QPalette::Background,Qt::cyan);
    dw->setAutoFillBackground(true);
    dw->setPalette(pal);

    // 学历层次
    QLabel *lab=new QLabel("学历层次：");

    QComboBox *cbx=new QComboBox();
    cbx->addItem("小学");
    cbx->addItem("初中");
    cbx->addItem("高中");
    cbx->addItem("专科");
    cbx->addItem("本科");
    cbx->addItem("硕士研究生");
    cbx->addItem("博士研究生");

    QPushButton *pbt1=new QPushButton("清华大学");
    QPushButton *pbt2=new QPushButton("北京大学");

    // 通过栅格布局（网格布局）
    QGridLayout *glayout=new QGridLayout();
    //该函数是Qt库中的一个函数，用于将一个标签控件（lab）添加到一个网格布局（glayout）中。添加的方式是在布局中的第0行、第0列的位置，并且占用1行、1列的空间。
    glayout->addWidget(lab,0,0,1,1);
    glayout->addWidget(cbx,0,1,1,1);
    glayout->addWidget(pbt1,1,0,1,1);
    glayout->addWidget(pbt2,1,1,1,1);

    //该函数用于设置QGridLayout布局的水平间距为10。
    glayout->setHorizontalSpacing(10);
    //该函数用于设置QGridLayout布局的垂直间距为10。
    glayout->setVerticalSpacing(10);
    //该函数用于设置QLayout对象（glayout）的内边距，参数分别为上、下、左、右四个边距值，单位为像素。该函数可以使得布局管理器在控制小部件排列时，留出指定大小的边距。
    glayout->setContentsMargins(20,20,20,20);


    QWidget *wgt=new QWidget();
    wgt->setLayout(glayout);
    dw->setWidget(wgt);



    dw->setMaximumSize(300,300);
}

MainWindow::~MainWindow()
{
    delete ui;
}

