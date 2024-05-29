#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("员工信息");

    // 左边控件
    UserNumber=new QLabel("员工编号：");
    UserNumberLineEdit=new QLineEdit;

    UserName=new QLabel("员工姓名：");
    UserNameLineEdit=new QLineEdit;

    UserSex=new QLabel("员工性别：");
    UserSexCombobox=new QComboBox;
    UserSexCombobox->addItem("男");
    UserSexCombobox->addItem("女");

    UserDepart=new QLabel("所在部门：");
    UserDepartTextEdit=new QTextEdit;

    UserAge=new QLabel("员工年龄：");
    UserAgeLineEdit=new QLineEdit;



    // 网格布局
    lLayout=new QGridLayout();

    lLayout->addWidget(UserNumber,0,0); // // 员工编号
    lLayout->addWidget(UserNumberLineEdit,0,1);

    lLayout->addWidget(UserName,1,0);
    lLayout->addWidget(UserNameLineEdit,1,1);

    lLayout->addWidget(UserSex,2,0);
    lLayout->addWidget(UserSexCombobox,2,1);

    lLayout->addWidget(UserDepart,3,0);
    lLayout->addWidget(UserDepartTextEdit,3,1);

    lLayout->addWidget(UserAge,4,0);
    lLayout->addWidget(UserAgeLineEdit,4,1);

    lLayout->setColumnStretch(0,1);
    lLayout->setColumnStretch(1,3);


    // 右边上部分
    toprightlayout=new QHBoxLayout();
    toprightlayout->setSpacing(25);

    MyselfInfo=new QLabel("个人简历:");
    MyselfInfoTextEdit=new QTextEdit;


    rightlayout=new QVBoxLayout();
    rightlayout->addLayout(toprightlayout);
    rightlayout->addWidget(MyselfInfo);
    rightlayout->addWidget(MyselfInfoTextEdit);


    // 右边下部分
    okbutton=new QPushButton("确认");
    cancelbutton=new QPushButton("退出");

    buttomLayout=new QHBoxLayout();
    buttomLayout->addStretch();
    buttomLayout->addWidget(okbutton);
    buttomLayout->addWidget(cancelbutton);

    //
    QGridLayout *mlayout=new QGridLayout(this);
    mlayout->setMargin(20);
    mlayout->setSpacing(10);
    mlayout->addLayout(lLayout,0,0); // 左边
    mlayout->addLayout(rightlayout,0,1); // 右上
    mlayout->addLayout(buttomLayout,1,0,1,2);

    mlayout->setSizeConstraint(QLayout::SetFixedSize);



}

Dialog::~Dialog()
{
}

