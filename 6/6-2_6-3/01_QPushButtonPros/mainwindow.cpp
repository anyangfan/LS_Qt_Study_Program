#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 设置窗口运行位置
    this->setGeometry(300,150,500,300);

    // 实例化两个命令按钮对象
    pb1=new QPushButton("命令按钮1",this);
    pb2=new QPushButton("命令按钮2",this);

    // 设置两个QPushButton对象的坐标位置
    pb1->setGeometry(20,20,150,50);
    pb2->setGeometry(20,90,150,50);

    // 与信号槽函数连接
    connect(pb1,SIGNAL(clicked()),this,SLOT(pushbutton1_clicked()));
    connect(pb2,SIGNAL(clicked()),this,SLOT(pushbutton2_clicked()));
}

MainWindow::~MainWindow()
{

}


// 声明对象pb1 pb2的槽函数
void MainWindow::pushbutton1_clicked()
{
    this->setStyleSheet("QMainWindow {background-color:rgba(255,255,0,100%);}");

}

void MainWindow::pushbutton2_clicked()
{
    this->setStyleSheet("QMainWindow {background-color:rgba(255,0,0,100%);}");

}
