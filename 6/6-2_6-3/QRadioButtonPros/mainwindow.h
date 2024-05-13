#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QRadioButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    // 声明2个QRadioButton对象 radb1,radb2;
    QRadioButton *radb1,*radb2;

};
#endif // MAINWINDOW_H
