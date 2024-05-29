#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    QGridLayout *glayout;

    QLabel *displabel;
    QPushButton *questionbutton; // 问题消息框命令按钮
    QPushButton *informationbutton; // 信息消息框命令按钮
    QPushButton *warningbutton; // 警告消息框命令按钮
    QPushButton *criticalbutton; // 错误消息框命令按钮
    QPushButton *aboutbutton; // 关于消息框命令按钮
    QPushButton *aboutqtbutton; //

private slots:
    void displayquestionMsg();
    void displayinformationMsg();
    void displaywarningMsg();
    void displaycriticalMsg();
    void displayaboutMsg();
    void displayaboutqtMsg();

};
#endif // DIALOG_H



























