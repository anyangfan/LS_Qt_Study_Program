#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("字体对话框测试");

    glayout=new QGridLayout(this);

    fontbutton=new QPushButton("调用字体对话框");

    fontlineedit=new QLineEdit;
    fontlineedit->setText("零声教育");

    glayout->addWidget(fontbutton,0,0);
    glayout->addWidget(fontlineedit,0,1);

    connect(fontbutton,SIGNAL(clicked()),this,SLOT(dispFontFunc()));

}

Dialog::~Dialog()
{
}


void Dialog::dispFontFunc()
{
    bool isbool;

    QFont font=QFontDialog::getFont(&isbool);

    if(isbool)
    {
        fontlineedit->setFont(font);
    }

}
