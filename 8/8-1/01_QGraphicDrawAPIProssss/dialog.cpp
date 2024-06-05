#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    resize(300,150);
    setWindowTitle("Qt窗口常用的API位置函数测试");

    // 布局
    glayout=new QGridLayout(this);

    labelgeometry=new QLabel("函数geomery():");
    labelgeometryvalue=new QLabel;

    labelwidth=new QLabel("函数width():");
    labelwidthvalue=new QLabel;
    labelheight=new QLabel("函数height():");
    labelheightvalue=new QLabel;

    labelrect=new QLabel("函数rect():");
    labelrectvalue=new QLabel;

    labelsize=new QLabel("函数size():");
    labelsizevalue=new QLabel;


    glayout->addWidget(labelgeometry,0,0);
    glayout->addWidget(labelgeometryvalue,0,1);

    glayout->addWidget(labelwidth,1,0);
    glayout->addWidget(labelwidthvalue,1,1);
    glayout->addWidget(labelheight,2,0);
    glayout->addWidget(labelheightvalue,2,1);

    glayout->addWidget(labelrect,3,0);
    glayout->addWidget(labelrectvalue,3,1);

    glayout->addWidget(labelsize,4,0);
    glayout->addWidget(labelsizevalue,4,1);




    UpdateLabelFunc(); // 调用更新Label标签的值

}

Dialog::~Dialog()
{
}



// 更新Label标签的值
void Dialog::UpdateLabelFunc()
{
    QString strgeometry; // 专门存放geometry()函数的显示结果
    QString str1,str2,str3,str4;

    strgeometry=str1.setNum(geometry().x())+","+str2.setNum(geometry().y())+","+
                            str3.setNum(geometry().width())+","+str4.setNum(geometry().height());

    /* 
    inline QString &QString::setNum(int n, int base)

    在C++中，`inline`是一个关键字，用于告诉编译器将函数体内联展开，而不是像普通函数那样生成一个函数调用。
    这意味着在编译时，编译器会尝试将函数调用处替换为函数体，以减少函数调用的开销，提高程序执行效率。

    `&`符号在这里不是指针的意思，而是表明该函数返回一个对`QString`对象的引用。
    返回引用的函数允许在函数调用后直接对返回的对象进行修改，而不需要再次复制该对象。
    这对于在一行代码中进行多个修改操作是非常方便的。

    所以，`inline QString &QString::setNum(int n, int base)`可以理解为这个函数是一个内联函数，
    它返回一个对`QString`对象的引用，并且可以将整数`n`转换为以`base`为基数的字符串，并将结果存储在该`QString`对象中。
     */
    labelgeometryvalue->setText(strgeometry); //将获取的值展示到这个控件



    QString strw,strh;
    labelwidthvalue->setText(strw.setNum(width()));
    labelheightvalue->setText(strh.setNum(height()));

    QString strrect;
    QString strrect1,strrect2,strrect3,strrect4;
    strrect=strrect1.setNum(rect().x())+","+strrect2.setNum(rect().y())+","+
            strrect3.setNum(width())+","+strrect4.setNum(height());
    labelrectvalue->setText(strrect);

    QString strsize;
    QString strsize1,strsize2;
    strsize=strsize1.setNum(size().width())+","+strsize2.setNum(size().height());
    labelsizevalue->setText(strsize);

}

// 窗口大小变化事件，通过此函数获取实时窗口的大小
void Dialog::resizeEvent(QResizeEvent *)
{
    UpdateLabelFunc();
}

/* 
    这个函数是Qt框架中的一个事件处理函数，属于对话框类（Dialog）的成员函数。
    它重写了QWidget类中的resizeEvent()函数，用于处理对话框的大小变化事件。
    当对话框的大小发生变化时，该函数会被自动调用，你可以在这里编写代码来处理对话框大小变化后的逻辑。

    在这个具体的函数定义中，参数 QResizeEvent * 通常表示一个指向大小变化事件对象的指针，
    尽管在函数体中没有使用这个参数。通常情况下，你可以通过这个参数来获取关于大小变化的更多信息，
    比如新的大小尺寸等。

    如果你想在对话框的大小发生变化时执行一些操作，比如重新布局控件或更新显示内容等，
    你可以将这些操作代码写在这个函数中。
 */

// 窗口移动事件，通过此函数获取实时窗口的位置
void Dialog::moveEvent(QMoveEvent *)
{
    UpdateLabelFunc();
}

/* 
    这个函数是在Qt中用于处理窗口移动事件的成员函数。在Qt中，所有的窗口小部件（widget）都能够接收和处理各种事件，
    比如鼠标事件、键盘事件、尺寸改变事件等等。moveEvent函数专门用于处理窗口移动事件。

    函数的签名是 void Dialog::moveEvent(QMoveEvent *)，表示这是 Dialog 类的成员函数，
    它接受一个指向 QMoveEvent 对象的指针作为参数，返回值是 void，即不返回任何值。

    当窗口被移动时，系统会生成一个 QMoveEvent 对象，并将其传递给窗口的 moveEvent 函数。
    在这个函数中，你可以编写处理移动事件的代码，比如更新窗口的位置信息或者执行其他相关操作。
 */
