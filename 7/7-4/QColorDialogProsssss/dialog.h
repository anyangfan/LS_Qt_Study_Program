#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>


#include <QPushButton>
#include <QFrame>
#include <QColorDialog>
#include <QGridLayout>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    QGridLayout *glayout;
    QPushButton *colorbutton;

    // QFrame类是基本控件的基类，QWidget是QFrame类型
    QFrame *colorFrame;

private slots:
    void dispcolorFunc();

};
#endif // DIALOG_H
