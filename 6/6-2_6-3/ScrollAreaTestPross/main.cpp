#include "widget.h"

#include <QApplication>


#include <QLabel>
#include <QScrollArea>
#include <QGridLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    w.resize(300,200);

    /*
     * QScrollArea当中有很多功能继承来自于QAbstractScrollArea
     * 滚动条外观是否漂亮取决于当前滚动条策略，有时间大家可以研究一下，查询官网来实现。
     * */

    QLabel *qljpg=new QLabel;
    qljpg->setScaledContents(true);
    QImage imagejpg(":/new/prefix1/images/789.jpg");
    qljpg->setPixmap(QPixmap::fromImage(imagejpg));

    QScrollArea *sArea=new QScrollArea;

    // 居中
    sArea->setAlignment(Qt::AlignCenter);

    // 根据窗口比例显示
    // sArea->setWidgetResizable(true);

    sArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    sArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    sArea->setWidget(qljpg);

    QGridLayout *glayout=new QGridLayout;
    glayout->addWidget(sArea);

    w.setLayout(glayout);




    w.show();
    return a.exec();
}
