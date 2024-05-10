#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;

    // 修改应用程序窗口标准的名称
    w.setWindowTitle("计算圆球体积");

    w.show();
    return a.exec();
}
