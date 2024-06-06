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
/* 
    1 
    函数void Widget::dispShapeFunc(int v) 的解释：
    这个函数是在一个名为 Widget 的类中定义的。函数接受一个整数参数 v。
    1.1
    它的目的是根据传入的整数值来设置 PainterArea 类的形状（shape）。
    1.2
    函数内部通过 comboboxshape 的 itemData 方法获取对应下拉框中选项的用户自定义数据，
    转换为整数，并转换为 PainterArea 类中的 shape 枚举类型。然后，通过调用 PainterArea 类的 setShape 方法，
    将得到的形状值传递给 PainterArea 对象的实例 labelshapeArea，从而改变绘图区域的形状。

    2
    在上述代码中，Qt::UserRole 被用于获取下拉框（comboboxshape）中每个选项的自定义数据。
    具体来说，itemData(v, Qt::UserRole) 方法用于检索下拉框中第 v 个选项关联的用户自定义数据，
    然后通过 toInt() 方法将其转换为整数。

    Qt::UserRole 的作用是允许开发人员将自定义的数据与Qt框架提供的控件（如下拉框）中的每个选项相关联。
    这样，开发人员可以存储任何他们想要的数据，而不仅仅是显示文本。
    在这种情况下，Qt::UserRole 被用于存储与每个下拉框选项相关联的形状（PainterArea::shape），
    并且在 Widget::dispShapeFunc 函数中用于动态设置 PainterArea 对象的形状。
 */
