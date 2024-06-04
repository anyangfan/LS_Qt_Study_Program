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

    lLayout->setColumnStretch(0,1);//该函数用于设置QGridLayout布局中第0列的拉伸因子为1。这意味着在布局中，第0列将按照指定的拉伸因子进行扩展，使得其宽度可以随窗口的大小而自动调整。
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
    mlayout->addLayout(buttomLayout,1,0,1,2);//该函数是Qt中的一个布局管理函数，用于将buttomLayout布局添加到mlayout中，位置从第1行第0列开始，占用1行2列的空间。

    mlayout->setSizeConstraint(QLayout::SetFixedSize);
    /*
    它设置了名为mlayout的QLayout对象的大小约束为固定大小。
    这意味着mlayout将不会根据其内容调整大小，而是保持固定的尺寸。
    */



}

Dialog::~Dialog()
{
}

