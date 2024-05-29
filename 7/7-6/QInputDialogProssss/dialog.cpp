#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    resize(260,110);
    setWindowTitle("标准对话框测试");

    // 布局
    glayout=new QGridLayout(this);

    inputstudentnobutton=new QPushButton;
    inputstudentnobutton->setText("学生学号：");
    inputstudentnobuttonLineEdit=new QLineEdit("2022101001");

    inputstudentnamebutton=new QPushButton;
    inputstudentnamebutton->setText("学生姓名：");
    inputstudentnamebuttonLineEdit=new QLineEdit("王小");

    inputstudentsexbutton=new QPushButton;
    inputstudentsexbutton->setText("学生性别：");
    inputstudentsexbuttonLineEdit=new QLineEdit("男");

    inputstudentscorebutton=new QPushButton;
    inputstudentscorebutton->setText("学生分数：");
    inputstudentscorebuttonLineEdit=new QLineEdit("99");


    glayout->addWidget(inputstudentnobutton,0,0);
    glayout->addWidget(inputstudentnobuttonLineEdit,0,1);
    glayout->addWidget(inputstudentnamebutton,1,0);
    glayout->addWidget(inputstudentnamebuttonLineEdit,1,1);
    glayout->addWidget(inputstudentsexbutton,2,0);
    glayout->addWidget(inputstudentsexbuttonLineEdit,2,1);
    glayout->addWidget(inputstudentscorebutton,3,0);
    glayout->addWidget(inputstudentscorebuttonLineEdit,3,1);

    connect(inputstudentnobutton,SIGNAL(clicked()),this,SLOT(modifystudentno()));
    connect(inputstudentsexbutton,SIGNAL(clicked()),this,SLOT(modifystudentsex()));


}

Dialog::~Dialog()
{
}


void  Dialog::modifystudentno()
{
    bool isbool;
    QString strText=QInputDialog::getText(this,"标准输入对话框","请输入学号：",
            QLineEdit::Normal,inputstudentnobuttonLineEdit->text(),&isbool);

    if(isbool && !strText.isEmpty())
    {
        inputstudentnobuttonLineEdit->setText(strText);
    }
}

void  Dialog::modifystudentsex()
{
    QStringList strSexItems;
    strSexItems<<"男"<<"女";

    bool isbool;
    QString strsexItem=QInputDialog::getItem(this,"标准输入对话框",
                                             "请选择性别：",strSexItems,0,false,&isbool);
    if(isbool && !strsexItem.isEmpty())
    {
        inputstudentsexbuttonLineEdit->setText(strsexItem);
    }

}
