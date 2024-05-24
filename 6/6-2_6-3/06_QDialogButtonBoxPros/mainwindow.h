#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QDialogButtonBox>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    // 声明两个对象
    QDialogButtonBox *dbb;
    QPushButton *pb;

private slots:
    // 声明信号槽
    void dbbpbClicked(QAbstractButton *);
};
#endif // MAINWINDOW_H
