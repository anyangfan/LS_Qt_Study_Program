#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    resize(300,150);
    setWindowTitle("Qt窗口常用的API位置函数测试");

    // 布局
    glayout=new QGridLayout(this);

    labelgeometry=new QLabel("函数geomery()：");
    labelgeometryvalue=new QLabel;

    labelwidth=new QLabel("函数width()：");
    labelwidthvalue=new QLabel;
    labelheight=new QLabel("函数height()：");
    labelheightvalue=new QLabel;

    labelrect=new QLabel("函数rect()：");
    labelrectvalue=new QLabel;

    labelsize=new QLabel("函数size()：");
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

// 窗口移动事件，通过此函数获取实时窗口的位置
void Dialog::moveEvent(QMoveEvent *)
{
    UpdateLabelFunc();
}
