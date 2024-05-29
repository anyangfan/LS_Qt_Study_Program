#include "stackeddlg.h"



#include <QHBoxLayout>



stackedDlg::stackedDlg(QWidget *parent)
    : QDialog(parent)
{

    setWindowTitle("堆栈窗体测试");

    qlist=new QListWidget(this);
    qlist->insertItem(0,"Linux1");
    qlist->insertItem(1,"Linux2");
    qlist->insertItem(2,"Linux3");
    qlist->insertItem(3,"Linux4");
    qlist->insertItem(4,"Linux5");

    lab1=new QLabel("Linux1 Qt");
    lab2=new QLabel("Linux2 Qt");
    lab3=new QLabel("Linux3 Qt");
    lab4=new QLabel("Linux4 Qt");
    lab5=new QLabel("Linux5 Qt");

    statcks=new QStackedWidget(this);
    statcks->addWidget(lab1);
    statcks->addWidget(lab2);
    statcks->addWidget(lab3);
    statcks->addWidget(lab4);
    statcks->addWidget(lab5);


    QHBoxLayout *mlayout=new QHBoxLayout(this);

    mlayout->setMargin(10);
    mlayout->setSpacing(20);

    mlayout->addWidget(qlist);
    mlayout->addWidget(statcks,0,Qt::AlignCenter);
    mlayout->setStretchFactor(qlist,1);
    mlayout->setStretchFactor(statcks,5);



}

stackedDlg::~stackedDlg()
{
}

