#include "widget.h"

#include <QFormLayout>
#include <QLineEdit>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    setFixedSize(450,250);

    /*
    该函数是一个C++函数，用于设置窗口的固定大小为宽度450像素和高度250像素。一旦窗口被设置为固定大小，
    用户将无法通过拖动窗口边缘来更改窗口大小。这个函数通常在创建窗口或对话框时调用，以确保窗口在屏幕上显示时具有预期的尺寸
    */

    // 创建表单布局指针
    QFormLayout *qLayout=new QFormLayout(this);

    QLineEdit *le1=new QLineEdit(); // 输入学号
    QLineEdit *le2=new QLineEdit(); // 输入姓名
    QLineEdit *le3=new QLineEdit(); // 输入学校

    qLayout->addRow("学号",le1);
    /*
    该函数是Qt中的一个布局管理函数，用于在布局（qLayout）中添加一行控件。
    该行包含一个标签（"学号"）和一个文本编辑框（le1），它们将按照布局的方式进行排列和展示。
    */
    qLayout->addRow("姓名",le2);
    qLayout->addRow("学校",le3);
    qLayout->setSpacing(8);

    // WrapAllRows将标签显示在单行编辑框上面
    //qLayout->setRowWrapPolicy(QFormLayout::WrapAllRows);

    // 当标签和单选编辑框,将标签显示在同一行。
    qLayout->setRowWrapPolicy(QFormLayout::WrapLongRows);


    qLayout->setLabelAlignment(Qt::AlignLeft); // 设置标签对齐方式

    setWindowTitle("表单布局测试案例");

}

Widget::~Widget()
{
}

