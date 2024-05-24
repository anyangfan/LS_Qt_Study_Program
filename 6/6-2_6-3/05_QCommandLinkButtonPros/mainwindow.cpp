#include "mainwindow.h"

#include <QDesktopServices> // 引入桌面服务
#include <QUrl> // 引入URL

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 设置窗口运行位置
    this->setGeometry(400,300,500,300);

    this->setStyleSheet("QMainWindow {background-color:rgba(255,100,0,100%);}");


    clb=new QCommandLinkButton("testclb","clicked testclb",this);
    clb->setGeometry(50,100,250,60);

    connect(clb,SIGNAL(clicked()),this,SLOT(clbClicked()));

}

MainWindow::~MainWindow()
{
}



void MainWindow::clbClicked()
{
    // 调用系统服务打开操作
    QDesktopServices::openUrl(QUrl("https://www.sina.com.cn/"));

}
