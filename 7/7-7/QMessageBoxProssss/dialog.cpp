#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    resize(320,150);

    glayout=new QGridLayout(this);

    displabel=new QLabel("请你选择一个消息框");

    questionbutton=new QPushButton("questionMsg"); // 问题消息框命令按钮
    informationbutton=new QPushButton("informationMsg"); // 信息消息框命令按钮
    warningbutton=new QPushButton("warningMsg"); // 警告消息框命令按钮
    criticalbutton=new QPushButton("criticalMsg"); // 错误消息框命令按钮
    aboutbutton=new QPushButton("aboutMsg"); // 关于消息框命令按钮
    aboutqtbutton=new QPushButton("aboutQtMsg"); //


    glayout->addWidget(displabel,0,0,1,2);
    glayout->addWidget(questionbutton,1,0);
    glayout->addWidget(informationbutton,1,1);
    glayout->addWidget(warningbutton,2,0);
    glayout->addWidget(criticalbutton,2,1);
    glayout->addWidget(aboutbutton,3,0);
    glayout->addWidget(aboutqtbutton,3,1);


    connect(questionbutton,SIGNAL(clicked()),this,SLOT(displayquestionMsg()));
    connect(informationbutton,SIGNAL(clicked()),this,SLOT(displayinformationMsg()));
    connect(warningbutton,SIGNAL(clicked()),this,SLOT(displaywarningMsg()));
    connect(criticalbutton,SIGNAL(clicked()),this,SLOT(displaycriticalMsg()));
    connect(aboutbutton,SIGNAL(clicked()),this,SLOT(displayaboutMsg()));
    connect(aboutqtbutton,SIGNAL(clicked()),this,SLOT(displayaboutqtMsg()));

}

Dialog::~Dialog()
{
}

void Dialog::displayquestionMsg()
{
    displabel->setText("question QMessageBox");

    switch(QMessageBox::question(this,"Question消息框",
                                 "你是否想退出程序应用，请选择?",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok))
    /* 
    这是一个使用Qt框架中QMessageBox类的示例代码，通常用于在图形用户界面中显示消息框。让我来解释一下这些参数：
    QMessageBox::question: 这是一个静态方法，用于显示一个询问类型的消息框。它通常用于询问用户是否想要执行某个操作。
    this: 这表示当前窗口或对话框的指针。在Qt中，通常使用this来引用当前对象。
    "Question消息框": 这是消息框的标题，会显示在消息框的标题栏上。
    "你是否想退出程序应用，请选择?": 这是要显示的消息文本，通常包含一条问题或提示信息。
    QMessageBox::Ok|QMessageBox::Cancel: 这是按钮的组合。在这里，QMessageBox::Ok表示消息框中会显示一个“确定”按钮，QMessageBox::Cancel表示消息框中会显示一个“取消”按钮。| 是按位或运算符，将两个按钮组合在一起。
    QMessageBox::Ok: 这是默认按钮，表示用户按下回车键时，该按钮的行为将被触发。
    */
    {
    case QMessageBox::Ok:
        displabel->setText("你选择questionMsg命令按钮当中的button/Ok!");
        break;
    case QMessageBox::Cancel:
        displabel->setText("你选择questionMsg命令按钮当中的button/Cancel!");
        break;
    default:
        break;
    }
    return ;
}


void Dialog::displayinformationMsg()
{
    displabel->setText("information QMessageBox");
    QMessageBox::information(this,"Information消息框","Information消息框测试成功，大家可以自己描述");
    return ;
}
void Dialog::displaywarningMsg()
{
    displabel->setText("warning QMessageBox");

    switch(QMessageBox::warning(this,"Warning消息框",
                                "是否删除数据库sudent.mdb，请注意数据的操作安全?",
                                QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel,QMessageBox::Save))
    {
    case QMessageBox::Save:
        displabel->setText("你选择warningMsg命令按钮当中的button/Save!");
        break;
    case QMessageBox::Discard:
        displabel->setText("你选择warningMsg命令按钮当中的button/Discard!");
        break;
    case QMessageBox::Cancel:
        displabel->setText("你选择warningMsg命令按钮当中的button/Cancel!");
        break;
    default:
        break;
    }
    return ;


}
void Dialog::displaycriticalMsg()
{
    displabel->setText("critical QMessageBox");
    QMessageBox::critical(this,"critical消息框","数据库文件备份错误，请重新检查？");
    return ;
}
void Dialog::displayaboutMsg()
{
    displabel->setText("about QMessageBox");
    QMessageBox::about(this,"about消息框","测试Qt about消息框");
    return ;
}
void Dialog::displayaboutqtMsg()
{
    displabel->setText("aboutQt QMessageBox");
    QMessageBox::aboutQt(this,"aboutQt消息框测试--Vico老师");
    return ;

}
