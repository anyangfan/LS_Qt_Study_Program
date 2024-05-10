#include "dialog.h"

const static double PI=3.1415;
#include <QGridLayout>  // QGridLayout（表格布局）

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    // 创建第1个标签（提示用户输入圆球的半径）
    lab1=new QLabel(this);
    lab1->setText(tr("请输入圆球的半径:"));

    // 创建第2个标签（专门用来显示计算圆球体积的结果）
    lab2=new QLabel(this);

    // 创建一个编辑框控件（专门用于接收用户的输入圆球半径的值）
    lEdit=new QLineEdit(this);

    // 创建命令按钮
    pbt=new QPushButton(this);
    pbt->setText(tr("计算圆球体积"));

    // 表格布局
    QGridLayout *mLay=new QGridLayout(this);
    mLay->addWidget(lab1,0,0);
    mLay->addWidget(lEdit,0,1);
    mLay->addWidget(lab2,1,0);
    mLay->addWidget(pbt,1,1);

    connect(lEdit,SIGNAL(textChanged(QString)),this,SLOT(CalcBallVolume()));
}

Dialog::~Dialog()
{
}

void Dialog::CalcBallVolume() // 槽函数计算圆球的体积
{
    bool isLoop;
    QString tempStr;
    QString valueStr=lEdit->text();

    int valueInt=valueStr.toInt(&isLoop);
    double dVSum=4.0/3.0*PI*valueInt*valueInt*valueInt;
    lab2->setText(tempStr.setNum(dVSum));
}
