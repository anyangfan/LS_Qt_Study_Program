#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 设置窗口运行位置
    this->setGeometry(300,150,500,300);

    //设置背景为白色
    this->setStyleSheet("QMainWindow {background-color:rgba(255,255,255,100%);}");

    // 将QRadioButton类的两个对象进行实例化
    radb1 = new QRadioButton(this);
    radb2 = new QRadioButton(this);

    // 设置两个对象位置
    radb1->setGeometry(20,20,150,40);
    radb2->setGeometry(20,80,150,40);

    // 设置两个单选按钮文本
    radb1->setText("选择按钮1");
    radb2->setText("选择按钮2");

    // 设置命令按钮默认值Checked false true
    radb1->setChecked(true);
    radb2->setChecked(false);


}

MainWindow::~MainWindow()
{
}

