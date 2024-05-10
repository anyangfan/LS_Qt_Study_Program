#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <qlabel.h> // 引入QLabel标签的头文件

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
   //1: QLabel *labFirst=new QLabel("LingShengEDU",this);  // 自己定义私有的QLabel标签指针对象
   //2:
   QLabel *labFirst;
};
#endif // MAINWINDOW_H
