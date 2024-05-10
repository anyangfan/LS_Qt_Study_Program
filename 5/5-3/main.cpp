#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.resize(500,300); // 设置运行窗口尺寸大小
    w.setWindowTitle("Qt第一个程序设计--OK");

    w.show();
    return a.exec();
}
