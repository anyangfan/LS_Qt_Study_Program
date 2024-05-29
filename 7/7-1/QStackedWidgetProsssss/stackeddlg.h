#ifndef STACKEDDLG_H
#define STACKEDDLG_H

#include <QDialog>

#include <QListWidget>
#include <QStackedWidget>
#include <QLabel>


class stackedDlg : public QDialog
{
    Q_OBJECT

public:
    stackedDlg(QWidget *parent = nullptr);
    ~stackedDlg();


public:
    QStackedWidget *statcks;
    QListWidget *qlist; // 列表框控件创建

    QLabel *lab1,*lab2,*lab3,*lab4,*lab5;



};
#endif // STACKEDDLG_H
