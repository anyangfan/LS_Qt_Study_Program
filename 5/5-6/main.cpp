#include <QCoreApplication>
#include <iostream>
#include <QMap>
#include <QMultiMap>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /* -------------------------------------------------------------------------- */
    /*                                    QMap类                                   */
    /* -------------------------------------------------------------------------- */
    std::cout << "/* -------------------------------------------------------------------------- */" << std::endl;
    std::cout << "/*                                    QMap类                                   */" << std::endl;
    std::cout << "/* -------------------------------------------------------------------------- */" << std::endl;
    // 1：创建QMap实例，第一个参数为QString类型的键，第二个参数为int类型的值
    qDebug() << "1.QMap";
    QMap<QString, int> qmap;
    qmap["Chinese"] = 119;
    qmap["English"] = 120;
    qmap.insert("Math", 115);
    qmap.insert("Physics", 99);
    qmap.insert("Chemistry", 100);
    qDebug() << qmap << endl;

    // Delete data informaton key
    qDebug() << "2. Delete data informaton key";
    qmap.remove("Chemistry");
    qDebug() << qmap << endl;

    // Traversal英/trəˈvərs(ə)l/ QMap
    // 1:iterator
    qDebug() << "3.1 Traversal QMap : iterator";
    QMapIterator<QString, int> itr(qmap);
    while (itr.hasNext())
    {
        itr.next();
        qDebug() << "key:" << itr.key() << "value:" << itr.value();
    }

    // 2:STL template
    qDebug() << "3.2 Traversal QMap : STL template";
    QMap<QString, int>::const_iterator stritr = qmap.constBegin();
    while (stritr != qmap.constEnd())
    {
        qDebug() << "key:" << stritr.key() << "value:" << stritr.value();
        stritr++;
    }

    // find
    qDebug() << "4. QMap : fine";
    qDebug() << "find key:" << qmap.find("Math").key() << "value:" << qmap.find("Math").value() << endl;

    // modify
    // 1.calling the insert() function to overwrite the value of the key
    qDebug() << "5.1. Modify the value of the key";
    qmap.insert("Math", 120);
    qDebug() << qmap.value("Math") << endl;

    // 2.using the [] operator to modify the value of the key
    qDebug() << "5.2 Modify the value of the key";
    qmap["Math"] = 130;
    qDebug() << qmap.value("Math") << endl;

    // search
    qDebug() << "6. QMap : Search";
    if (qmap.contains("Math"))
    {
        qDebug() << "Math is in the QMap" << endl;
    }
    else
    {
        qDebug() << "Math is not in the QMap" << endl;
    }

    // output : key-value
    qDebug() << "7. QMap : output key-value";
    QList<QString> keys = qmap.keys();
    for (int i = 0; i < keys.size(); i++)
    {
        qDebug() << keys.at(i) << ":" << qmap.value(keys.at(i));
    }
    QList<int> values = qmap.values();
    for (int i = 0; i < values.size(); i++)
    {
        qDebug() << values.at(i);
    }
    std::cout << std::endl;

    // QMultiMap
    qDebug() << "8. QMultiMap";
    QMultiMap<QString, QString> multimap;
    multimap.insert("student", "name");
    multimap.insert("student", "age");
    multimap.insert("student", "sex");
    qDebug() << multimap << endl;

    /* -------------------------------------------------------------------------- */
    /*                                    QHash                                   */
    /* -------------------------------------------------------------------------- */
    std::cout << "/* -------------------------------------------------------------------------- */" << std::endl;
    std::cout << "/*                                    QHash                                   */" << std::endl;
    std::cout << "/* -------------------------------------------------------------------------- */" << std::endl;

    // QHash 类
    qDebug() << "1. QHash";
    QHash<QString, int> qhash;
    qhash["key 1"] = 3;
    qhash["key 1"] = 8;
    qhash["key 4"] = 4;
    qhash["key 2"] = 2;

    qhash.insert("key 3", 30);
    QList<QString> list = qhash.keys();
    for (int i = 0; i < list.length(); i++)
        qDebug() << list[i] << "," << qhash.value(list[i]);

    std::cout<<std::endl;
    // QHash 内部的迭代器 QHashIterator 类
    qDebug() << "2. QHashIterator";
    QHash<QString, int> hash;
    hash["key 1"] = 33;
    hash["key 2"] = 44;
    hash["key 3"] = 55;
    hash["key 4"] = 66;
    hash.insert("key 3", 100);
    QHash<QString, int>::const_iterator iterator;
    for (iterator = hash.begin(); iterator != hash.end(); iterator++)
    {
        qDebug() << iterator.key() << "-->" << iterator.value();
    }
    std::cout<<std::endl;

    std::cout << "/* -------------------------------------------------------------------------- */" << std::endl;
    std::cout << "/*                                    Qvector                                 */" << std::endl;
    std::cout << "/* -------------------------------------------------------------------------- */" << std::endl;

    // QVector 类
    // QVector<T>是 Qt 的一个容器类
    qDebug() << "1. QVector 类 (两种赋值方式)";
    QVector<int> qvr;
    // 第一种方式赋值
    qvr << 10;
    qvr << 20;
    qvr << 30;
    qvr << 40;
    // 第二方式赋值
    qvr.append(50);
    qvr.append(60);
    qvr.append(70);
    qvr.append(80);
    qvr.append(90);
    qvr.append(100);
    qDebug() << qvr << endl;

    // 求出 QVector 类容器的实例化：元素个数
    qDebug() << "求出 QVector 类容器的实例化：元素个数";
    qDebug() << "qvr count=" << qvr.count() << endl;

    // 遍历所有元素
    qDebug() << "遍历所有元素";
    for (int i = 0; i < qvr.count(); i++)
    {
        qDebug() << qvr[i];
    }
    std::cout << std::endl;

    // 删除 qvr 容器里面的元素
    qDebug() << "删除 qvr 容器里面的元素";
    qvr.remove(0); // 删除第 0 个元素
    for (int i = 0; i < qvr.count(); i++)
        qDebug() << qvr[i];
    qDebug() << endl;

    qDebug() << "从第 2 个元素开始，删除后面 3 个元素";
    qvr.remove(2, 3); // 从第 2 个元素开始，删除后面 3 个元素
    for (int i = 0; i < qvr.count(); i++)
        qDebug() << qvr[i];
    qDebug() << endl;

    // 判断容器是否包含某个元素
    qDebug() << "判断容器是否包含某个元素";
    qDebug() << "result=" << qvr.contains(90);
    qDebug() << "result=" << qvr.contains(901) << endl;
    return 0;
    // return a.exec();
}
