#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// 1:
#include <QToolBar> // 引入QToolBar类
#include <QToolButton> // 引入QToolButton类


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    // 2：声明一个QToolButton对象和QToolBar对象
    QToolBar *tbar;
    QToolButton *tbutton;

};
#endif // MAINWINDOW_H
