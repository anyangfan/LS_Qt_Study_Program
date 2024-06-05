#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QLabel>
#include <QMouseEvent> // 鼠标事件
#include <QStatusBar>  // 窗口状态栏实现
#include <QMessageBox>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);





private:
    QLabel *statuslabel;
    QLabel *mouselabelpos;

    void disppicture();


};
#endif // MAINWINDOW_H
