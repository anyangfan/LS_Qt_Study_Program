#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextBrowser>
// 定义学生结构体类型
struct student
{
    int iNo;
    QString strName;
    int score;
};
Q_DECLARE_METATYPE(student)

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTextBrowser *textBrowser;

    
};
#endif // MAINWINDOW_H
