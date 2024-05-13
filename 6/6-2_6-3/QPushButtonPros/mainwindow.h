#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QPushButton>  // 引入QPushButton类对应的头文件


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    // 声明两个QPushButton对象
    QPushButton *pb1,*pb2;


private slots:
    // 声明对象pb1 pb2的槽函数
    void pushbutton1_clicked();
    void pushbutton2_clicked();

};
#endif // MAINWINDOW_H
