#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 设置窗口运行位置
    this->setGeometry(400,300,500,300);

    this->setStyleSheet("QMainWindow {background-color:rgba(255,100,0,100%);}");


    // 实例化操作
    cb=new QCheckBox(this);
    cb->setGeometry(30,50,250,50);

    cb->setCheckState(Qt::Checked); // 初始化三态复选框状态：Checked
    cb->setText("初始化状态为：Checked状态");

    cb->setTristate(); // 开启三态模式，必须开启。否则 只有两种状态（Checked Unchecked）

    connect(cb,SIGNAL(stateChanged(int)),this,SLOT(checkboxstate(int)));


}

MainWindow::~MainWindow()
{
}



void MainWindow::checkboxstate(int istate)
{
    // 判断checkbox的状态
    switch(istate)
    {
    case Qt::Checked: // 选中状态
        cb->setText("选中状态OK");
        break;

    case Qt::Unchecked: // 未选中状态
        cb->setText("未选中状态NO");
        break;

    case Qt::PartiallyChecked: // 半选中状态
        cb->setText("半选中状态OK");
        break;

    default:
        break;
    }


}
