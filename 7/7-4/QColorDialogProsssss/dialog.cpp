#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{

    setWindowTitle("颜色对话框测试");
    this->resize(300,200);

    glayout=new QGridLayout(this);  // new一个布局对象

    colorbutton=new QPushButton("调用颜色对话框");
    colorFrame=new QFrame;

    colorFrame->setFrameShape(QFrame::Box); // 设置形状
    colorFrame->setAutoFillBackground(true); // 填充背景处理

    glayout->addWidget(colorbutton,0,0);
    glayout->addWidget(colorFrame,1,0);

    // 信号槽函数连接
    connect(colorbutton,SIGNAL(clicked()),this,SLOT(dispcolorFunc()));


}

Dialog::~Dialog()
{
}

void Dialog::dispcolorFunc()
{
    QColor colorvalues=QColorDialog::getColor(Qt::red);//调用颜色对话框并设置默认颜色

    if(colorvalues.isValid())
    {
        colorFrame->setPalette(QPalette(colorvalues));
    }
}
