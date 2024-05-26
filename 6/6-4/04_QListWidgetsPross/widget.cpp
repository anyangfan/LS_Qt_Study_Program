#include "widget.h"
#include "ui_widget.h"

#include <QListWidget>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QListWidgetItem *qitem=new QListWidgetItem("沁园春.雪--作者:毛主席");
    ui->listWidget->addItem(qitem);
    qitem->setTextAlignment(Qt::AlignCenter|Qt::AlignVCenter);

    QStringList slist;
    slist<<"1:北国风光，千里冰封，万里雪飘。";
    slist<<"2:望长城内外，惟余莽莽；大河上下，顿时滔滔。";

    ui->listWidget->addItems(slist);
}

Widget::~Widget()
{
    delete ui;
}

