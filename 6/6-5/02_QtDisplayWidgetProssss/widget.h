#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


// 1:
#include <QMessageBox>

// 2:
#include <QFile>

// 4:
#include <QTimer>

#include <QDir>




QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButtonProgressBar_clicked();

    void on_pushbtnstart_clicked();

    void on_pushbtnpause_clicked();

    void on_pushbtnreset_clicked();

    // 4:
    // 自定义函数：定时器
    void on_timerout();
private:
    int iValues=0;
    QTimer *timers; // 定时器
    void InitFunc();

private:
    Ui::Widget *ui;

    // 1:
private:
    void textlabelFunc();

    // 2:
private:
    void textbrowserFuncReadTxt();

};
#endif // WIDGET_H
