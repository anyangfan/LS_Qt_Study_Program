#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include <QLabel>
#include <QGridLayout>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();


private:
    QGridLayout *glayout;  // 布局

    QLabel *labelgeometry; // 显示函数名称
    QLabel *labelgeometryvalue; // 显示geometry函数获取值

    QLabel *labelwidth;
    QLabel *labelwidthvalue;
    QLabel *labelheight;
    QLabel *labelheightvalue;

    QLabel *labelrect;
    QLabel *labelrectvalue;

    QLabel *labelsize;
    QLabel *labelsizevalue;

    // 窗口大小变化事件，通过此函数获取实时窗口的大小
    void resizeEvent(QResizeEvent *);

    // 窗口移动事件，通过此函数获取实时窗口的位置
    void moveEvent(QMoveEvent *);

public:
    // 更新Label标签的值
    void UpdateLabelFunc();


};
#endif // DIALOG_H
