#include "widget.h"


#include <QGroupBox>
#include <QRadioButton>
#include <QPushButton>
#include <QCheckBox>
#include <QVBoxLayout> // 可以在水平方向和垂直方向进行排列的控件，QHBoxLayout/QVBoxLayout所继承
#include <QGridLayout>

#include <QMenu>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 组合框1：gpb_1
    QGroupBox *gpb_1=new QGroupBox("单选按钮组1");
    QRadioButton *rbtn_1=new QRadioButton("RadioButton1");
    QRadioButton *rbtn_2=new QRadioButton("RadioButton2");
    QRadioButton *rbtn_3=new QRadioButton("RadioButton3");

    QVBoxLayout *vbly1=new QVBoxLayout;
    vbly1->addWidget(rbtn_1);
    vbly1->addWidget(rbtn_2);
    vbly1->addWidget(rbtn_3);
    gpb_1->setLayout(vbly1);



    // 组合框2：gpb_2
    QGroupBox *gpb_2=new QGroupBox("复选按钮组2");
    QCheckBox *cbx1=new QCheckBox("checkbox1");
    QCheckBox *cbx2=new QCheckBox("checkbox2");
    QCheckBox *cbx3=new QCheckBox("checkbox3");

    // 全选的复选框能实时呈现（全选、半选、未选）
    // cbx2->setTristate(true); // 设置是否支持半选状态，默认不支持半选态
    cbx2->setChecked(true);

    QVBoxLayout *vbly2=new QVBoxLayout;
    vbly2->addWidget(cbx1);
    vbly2->addWidget(cbx2);
    vbly2->addWidget(cbx3);
    gpb_2->setLayout(vbly2);


    // 组合框3：gpb_3
    QGroupBox *gpb_3=new QGroupBox("单选按钮和复选按钮组3");
    gpb_3->setCheckable(true);

    QRadioButton *rbtn_31=new QRadioButton("RadioButton31");
    QRadioButton *rbtn_32=new QRadioButton("RadioButton32");
    QRadioButton *rbtn_33=new QRadioButton("RadioButton33");
    QCheckBox *cbx4=new QCheckBox("checkbox4");
    cbx4->setChecked(true);

    QVBoxLayout *vbly3=new QVBoxLayout;
    vbly3->addWidget(rbtn_31);
    vbly3->addWidget(rbtn_32);
    vbly3->addWidget(rbtn_33);
    vbly3->addWidget(cbx4);
    gpb_3->setLayout(vbly3);


    // 组合框4：gpb_4
    QGroupBox *gpb_4=new QGroupBox("综合按钮组4");
    gpb_4->setCheckable(true);
    gpb_4->setChecked(true);

    QPushButton *pbtn_4=new QPushButton("PushButton4");
    QPushButton *pbtn_5=new QPushButton("PushButton5");
    pbtn_5->setCheckable(true);
    pbtn_5->setChecked(true);
    QPushButton *pbtn_6=new QPushButton("PushButton6");

    // 命令按钮添加子菜单
    QMenu *mu=new QMenu(this);
    mu->addAction("King");
    mu->addAction("Darren");
    mu->addAction("Mark");
    mu->addAction("Vico");
    pbtn_6->setMenu(mu);

    QVBoxLayout *vbly4=new QVBoxLayout;
    vbly4->addWidget(pbtn_4);
    vbly4->addWidget(pbtn_5);
    vbly4->addWidget(pbtn_6);
    gpb_4->setLayout(vbly4);




    QGridLayout *gdlyout=new QGridLayout;
    gdlyout->addWidget(gpb_1,0,0,1,1);
    gdlyout->addWidget(gpb_2,0,1,1,1);
    gdlyout->addWidget(gpb_3,1,0,1,1);
    gdlyout->addWidget(gpb_4,1,1,1,1);



    this->setLayout(gdlyout);

}

Widget::~Widget()
{
}

