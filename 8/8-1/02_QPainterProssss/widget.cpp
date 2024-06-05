#include "widget.h"



Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    labelshapeArea=new PainterArea;

    glayout=new QGridLayout; // 控制面板的布局

    setWindowTitle("Qt绘图框架测试:QPainter类");

    labelshape=new QLabel("绘制形状:"); //右边有一个下拉列表框
    comboboxshape=new QComboBox;
    comboboxshape->addItem("Line",PainterArea::Line);
    comboboxshape->addItem("Rectangle",PainterArea::Rectangle);

    connect(comboboxshape,SIGNAL(activated(int)),this,SLOT(dispShapeFunc(int)));

    glayout->addWidget(labelshape,0,0);
    glayout->addWidget(comboboxshape,0,1);


    QHBoxLayout *mainlayout=new QHBoxLayout(this); // 整体布局
    mainlayout->addWidget(labelshapeArea); // 向布局添加控件
    mainlayout->addLayout(glayout); // 向整体布局添加布局




    // 如下语句大家自己添加
    dispShapeFunc(comboboxshape->currentIndex());//显示默认的图形
}

Widget::~Widget()
{

}


void Widget::dispShapeFunc(int v)
{
    PainterArea::shape sp=PainterArea::shape(comboboxshape->itemData(v,Qt::UserRole).toInt());
    labelshapeArea->setShape(sp);
}
