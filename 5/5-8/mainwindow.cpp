#include "mainwindow.h"

#include <QVariant>
#include <QDebug>
#include <QColor>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    // 初始化textBrowser
    textBrowser = new QTextBrowser(this);
    this->setCentralWidget(textBrowser);

    QVariant qv1(298);
    qDebug() << "qv1:" << qv1.toInt();
    // 添加textBrowser
    textBrowser->append("qv1:" + qv1.toString());

    QVariant qv2("LingShengEDU");
    qDebug() << "qv2:" << qv2.toString();
    textBrowser->append("qv2:" + qv2.toString());

    QMap<QString, QVariant> qmap;
    qDebug() << endl;
    qmap["int"] = 20000;                 // 整型
    qmap["double"] = 99.88;              // 浮点型
    qmap["string"] = "Good";             // 字符串
    qmap["color"] = QColor(255, 255, 0); // QColor类型

    // 输出：转换函数来处理
    qDebug() << qmap["int"] << qmap["int"].toInt();
    qDebug() << qmap["double"] << qmap["double"].toDouble();
    qDebug() << qmap["string"] << qmap["string"].toString();
    qDebug() << qmap["color"] << qmap["color"].value<QColor>();

    textBrowser->append("qmap:" + qmap.value("int").toString());
    textBrowser->append("qmap:" + qmap.value("double").toString());
    textBrowser->append("qmap:" + qmap.value("string").toString());
    textBrowser->append("qmap:" + qmap.value("color").value<QColor>().name());

    // 创建一个字符串列表：QStringList
    qDebug() << endl;
    QStringList qsl;
    qsl << "A" << "B" << "C" << "D" << "E" << "F";

    QVariant qvsl(qsl); // 将列表存储在一个QVariant变量

    if (qvsl.type() == QVariant::StringList)
    {
        QStringList qlist = qvsl.toStringList();
        for (int i = 0; i < qlist.size(); i++)
        {
            qDebug() << qlist.at(i); // 输出列表数据信息
        }
    }

    QString qs;
    for (int i = 0; i < qsl.size(); i++)
    {
        qs += qsl.at(i) + " ";
    }

    textBrowser->append("qvsl:" + qs);

    // 结构体类型和QVariant类配合使用
    qDebug() << endl;
    student stu;
    stu.iNo = 202201;
    stu.strName = "sunny";
    stu.score = 715;

    // 使用静态方法保存数据
    QVariant qstu = QVariant::fromValue(stu);

    if (qstu.canConvert<student>()) // 判断是否可以转换操作
    {
        student temp = qstu.value<student>();         // 获取数据
        student qtemp = qvariant_cast<student>(qstu); // 获取数据

        qDebug() << "student:iNo=" << temp.iNo << ",strName=" << temp.strName << ",score=" << temp.score;
        qDebug() << "student:iNo=" << qtemp.iNo << ",strName=" << qtemp.strName << ",score=" << qtemp.score;

        textBrowser->append("student:iNo=" + QString::number(stu.iNo) + ",strName=" + stu.strName + ",score=" + QString::number(stu.score));
        textBrowser->append("student:iNo=" + QString::number(qtemp.iNo) + ",strName=" + qtemp.strName + ",score=" + QString::number(qtemp.score));
    }
}

MainWindow::~MainWindow()
{
}
