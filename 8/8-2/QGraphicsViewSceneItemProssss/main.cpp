#include "mainwidget.h"

#include <QApplication>
#include <QCoreApplication>


// 我们要自己创建一个类（图元类）：作为图元来显示对应图片
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.show();
    return a.exec();
}
