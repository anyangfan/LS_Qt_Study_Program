#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QCommandLinkButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    // 声明一个QCommandLinkButton对象
    QCommandLinkButton *clb;

private slots:
    // 声明槽函数 使用鼠标点击clb之后触发
    void clbClicked();
};
#endif // MAINWINDOW_H
