#include "widget.h"



Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("标签小部件控件测试");
    this->setGeometry(300,200,600,400);

    tabWidgetUI=new QTabWidget(this);
    tabWidgetUI->setGeometry(20,20,560,360);
    tabWidgetUI->show();

    bool m_showtabwidgetui1=true;
    bool m_showtabwidgetui2=true;
    // bool m_showtabwidgetui3=false;
    // bool m_showtabwidgetui4=false;

    if(m_showtabwidgetui1)
    {
        QWidget *qwidget1=new QWidget();
        tabWidgetUI->addTab(qwidget1,"进程");

        QGridLayout *glayout=new QGridLayout();

        QLabel *lab1=new QLabel("请选择文件及文件夹：");
        QLineEdit *ledit1=new QLineEdit();

        QPushButton *pbt1=new QPushButton("消息框...");
        connect(pbt1,SIGNAL(clicked(bool)),this,SLOT(MsgCommit()));

        glayout->addWidget(lab1,0,0);
        glayout->addWidget(ledit1,0,1);
        glayout->addWidget(pbt1,0,2);


        qwidget1->setLayout(glayout);
    }

    if(m_showtabwidgetui2)
    {
        QWidget *qwidget2=new QWidget();
        tabWidgetUI->addTab(qwidget2,"性能");
    }

    /*
    if(m_showtabwidgetui3)
    {
        QWidget *qwidget3=new QWidget();
        tabWidgetUI->addTab(qwidget3,"应用历史记录");
    }


    if(m_showtabwidgetui4)
    {
        QWidget *qwidget4=new QWidget();
        tabWidgetUI->addTab(qwidget4,"启动");
    }
    */


}

Widget::~Widget()
{
}


void Widget::MsgCommit()
{
    QMessageBox::information(NULL,"testing","QMessageBox：命令按钮测试成功!",QMessageBox::Ok);
}
