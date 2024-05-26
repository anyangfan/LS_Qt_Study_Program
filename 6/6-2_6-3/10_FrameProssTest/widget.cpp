#include "widget.h"
#include "ui_widget.h"

#include <QFrame>

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("Frame框架控件测试");

    ui->frame_1->setStyleSheet("background-color:yellow");
    ui->frame_2->setStyleSheet("background-color:green");

    //这段代码是设置Qt框架中一个名为frame_1的QFrame对象的样式。
    ui->frame_1->setLineWidth(1);//设置边框的宽度为1。
    ui->frame_1->setMidLineWidth(1);//设置中间边框的宽度为1。
    ui->frame_1->setFrameShape(QFrame::Box);//设置边框的形状为矩形。
    ui->frame_1->setFrameShadow(QFrame::Raised);//设置边框的阴影样式为凸起。


    ui->frame_2->setLineWidth(0);
    ui->frame_2->setMidLineWidth(1);
    ui->frame_2->setFrameShape(QFrame::Box);
    ui->frame_2->setFrameShadow(QFrame::Sunken);

    //连接信号槽: ui->frame_1和on_pushButton_clicked()
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));    
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked(){
    //更改背景颜色
    ui->frame_1->setStyleSheet("background-color:rgb(255,0,0)");
}