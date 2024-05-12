#include <QCoreApplication>
#include <QList>
#include <QDebug>
#include <QLinkedList>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "/* -------------------------------------------------------------------------- */";
    qDebug() << "/*                                    QList                                   */";
    qDebug() << "/* -------------------------------------------------------------------------- */";
    // QList 类
    qDebug() << "1.QList 类";
    QList<int> qlist; // 初始化一个空的 QList<int>列表
    for (int i = 0; i < 10; i++)
        qlist.insert(qlist.end(), i + 10);
    qDebug() << qlist;

    // 通过 QList<int>::iterator 读写迭代器
    qDebug() << endl;
    qDebug() << "2.通过 QList<int>::iterator 读写迭代器";
    QList<int>::iterator x;
    qDebug() << "Result1:";
    for (x = qlist.begin(); x != qlist.end(); x++)
    {
        qDebug() << (*x);
        *x = (*x) * 10 + 6;
    }

    // 初始化一个 QList<int>const_iterator 只读迭代器
    qDebug() << endl;
    qDebug() << "3.初始化一个 QList<int>const_iterator 只读迭代器";
    qDebug() << "Result1:";
    QList<int>::const_iterator qciter;
    // 输出列表所有的值
    for (qciter = qlist.constBegin(); qciter != qlist.constEnd(); qciter++)
        qDebug() << *qciter;

    // 向 qlist 添加元素
    qDebug() << endl;
    qDebug() << "4.向 qlist 添加元素";
    qlist.append(666);
    QList<int>::iterator itr1;
    qDebug() << "Result2:";
    for (itr1 = qlist.begin(); itr1 != qlist.end(); itr1++)
        qDebug() << *itr1;

    // 查询 qlist 当中元素
    qDebug() << endl;
    qDebug() << "5.查询 qlist 当中元素";
    qDebug() << "Result3:";
    qDebug() << qlist.at(3);
    qDebug() << qlist.contains(77);
    qDebug() << qlist.contains(166);

    // 修改 qlist 列表里面的元素值
    qDebug() << endl;
    qDebug() << "6.修改 qlist 列表里面的元素值";
    qDebug() << "Result4:";
    qlist.replace(5, 888);
    qDebug() << qlist;

    // 删除元素
    qDebug() << endl;
    qDebug() << "7.删除元素";
    qDebug() << "Result5:";
    qlist.removeAt(0);
    qlist.removeFirst();
    qlist.removeAt(6);
    qDebug() << qlist;
    qDebug() << endl;

    qDebug() << "/* -------------------------------------------------------------------------- */";
    qDebug() << "/*                                    QLinkedList                             */";
    qDebug() << "/* -------------------------------------------------------------------------- */";

    // QLinkedList 类
    qDebug() << "1.初始化 QLinkedList 类";
    QLinkedList<QString> qAllMonth;
    for (int i = 1; i <= 12; i++)
        qAllMonth << QString("%1%2").arg("Month:").arg(i);

    // 读写迭代器
    qDebug() << "2.读写迭代器";
    qDebug() << "Result1:";
    QLinkedList<QString>::iterator itrw = qAllMonth.begin();
    for (; itrw != qAllMonth.end(); itrw++)
        qDebug() << *itrw;
    // 只读迭代器
    qDebug() << endl;
    qDebug() << "3.只读迭代器";
    qDebug() << "Result2:";
    QLinkedList<QString>::const_iterator itr = qAllMonth.constBegin();
    for (; itr != qAllMonth.constEnd(); itr++)
        qDebug() << *itr;
    
    return 0;
    // return a.exec();
}
