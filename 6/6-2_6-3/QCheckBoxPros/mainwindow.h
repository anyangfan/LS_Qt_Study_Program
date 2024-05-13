#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QCheckBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    // 声明1个QCheckBox对象
    QCheckBox *cb;

private slots:
    // 声明QCheckBox槽函数，在操作过程当中并且带参数传递，通过这个参数接收信号
    void checkboxstate(int);

};
#endif // MAINWINDOW_H
