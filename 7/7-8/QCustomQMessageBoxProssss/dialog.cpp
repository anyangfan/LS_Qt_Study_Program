#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{

    resize(260,120);

    glayout=new QGridLayout(this);

    labelmsg=new QLabel("自定义消息框");
    msgbutton=new QPushButton("测试操作");

    labeldispmsg=new QLabel("未测试状态");

    glayout->addWidget(labelmsg,0,0);
    glayout->addWidget(msgbutton,0,1);
    glayout->addWidget(labeldispmsg,1,0,1,1);

    connect(msgbutton,SIGNAL(clicked()),this,SLOT(customMsg()));

}

Dialog::~Dialog()
{
}


void Dialog::customMsg()
{
    QMessageBox cMsgBox;
    cMsgBox.setWindowTitle("零声教育消息框");

    // 添加按钮
    QPushButton *yes=cMsgBox.addButton("YES",QMessageBox::ActionRole);
    /* 
    这段代码是使用Qt库中的QMessageBox类创建了一个消息框对象cMsgBox，
    并设置了其窗口标题为"零声教育消息框"。
    接着，代码通过addButton()函数向消息框中添加了一个按钮，按钮上显示的文本是"YES"，
    并将按钮的角色设置为QMessageBox::ActionRole，表示这是一个操作按钮。
     */
    QPushButton *no=cMsgBox.addButton("NO",QMessageBox::ActionRole);

    // 添加图标
    

    // 设置当前目录
    QDir::setCurrent(QCoreApplication::applicationDirPath());


    cMsgBox.setIconPixmap(QPixmap("..\\..\\..\\00_material_lib\\lspng.png"));
    cMsgBox.exec();

    // 判断用户点击按钮 yes no
    if(cMsgBox.clickedButton()==yes)
    {
        labeldispmsg->setText("用户点击YES按钮");
    }
    else if(cMsgBox.clickedButton()==no)
    {
        labeldispmsg->setText("用户点击NO按钮");
    }


}
