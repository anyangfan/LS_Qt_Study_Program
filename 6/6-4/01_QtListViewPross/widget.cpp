#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    resize(450,250);

    listview1=new QListView(this);  // 创建QListView对象
    listview1->setGeometry(20,20,240,160); // 设置控件显示位置和控件大小

    QStringList qlist; // 创建数据显示至清单视图(之前）
    qlist.append("运动类：篮球、足球");
    qlist.append("娱乐类：看电影、写小说、听音乐");
    qlist.append("游戏类：五子棋、扑克牌、中国象棋");
    qlist.append("旅游类：国外旅游、国内旅游");

    // 他用数据列表创建数据显示模型进行实现
    QStringListModel *listmode=new QStringListModel(qlist);
    listview1->setModel(listmode);

    connect(listview1,SIGNAL(clicked(const QModelIndex)),this,SLOT(SlotClickedFunc(const QModelIndex)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::SlotClickedFunc(const QModelIndex &index)
{
    QMessageBox::information(NULL,"兴趣爱好","你选择的类型为：\n"+index.data().toString());
}

