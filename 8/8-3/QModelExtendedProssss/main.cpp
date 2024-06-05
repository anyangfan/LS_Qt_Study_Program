#include "mainwindow.h"

#include <QApplication>


#include "modelextended.h"
#include <QTableView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // MainWindow w;
    // w.show();

    ModelExtended modelExts;

    QTableView view;
    view.setModel(&modelExts);
    view.setWindowTitle("ModelExtended模型扩展--测试操作");

    view.resize(500,300);

    view.show(); // 显示表视图



    return a.exec();
}
