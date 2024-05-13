#include "mainwindow.h"

#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 设置窗口运行位置
    this->setGeometry(0,0,800,600);

    dbb=new QDialogButtonBox(this);
    dbb->setGeometry(300,200,200,30);

    dbb->addButton(QDialogButtonBox::Cancel);
    dbb->button(QDialogButtonBox::Cancel)->setText("取 消");


    pb=new QPushButton("自定义");

    // 将pb添加到dbb，并且设定ButtonRole为ActionRole
    dbb->addButton(pb,QDialogButtonBox::ActionRole);

    connect(dbb,SIGNAL(clicked(QAbstractButton*)),this,
            SLOT(dbbpbClicked(QAbstractButton*)));

}

MainWindow::~MainWindow()
{
}


void MainWindow::dbbpbClicked(QAbstractButton *bt)
{
    if(bt==dbb->button(QDialogButtonBox::Cancel))
    {
      qDebug()<<"你已经点击【取消】按钮"<<endl;
    }
    else if(bt==pb)
    {
        qDebug()<<"你已经点击【自定义】按钮"<<endl;
    }
}
