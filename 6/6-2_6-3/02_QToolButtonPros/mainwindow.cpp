#include "mainwindow.h"

#include <QApplication>
#include <QStyle>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //3: 设置窗口运行位置
    this->setGeometry(300,150,500,300);

    //4: 将QToolBar对象进行实例化
    tbar=new QToolBar(this);
    tbar->setGeometry(20,20,250,100);

    //5: 将QStyle类对象进行实例化，主要目的设置风格，图标是系统自带
    QStyle *sty=QApplication::style();
    QIcon ico=sty->standardIcon(QStyle::SP_TitleBarContextHelpButton);

    //6: 将QToolButton对象进行实例化
    tbutton=new QToolButton();
    tbutton->setIcon(ico);

    tbutton->setText("系统帮助提示"); // 设置将要显示文本

    // 调用setToolButtonStyle函数设置tbutton样式，设置文本在图标下方
    tbutton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    // 将tbutton添加到tbar里面
    tbar->addWidget(tbutton);




}

MainWindow::~MainWindow()
{
}

