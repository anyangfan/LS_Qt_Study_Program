#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>


#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QGridLayout>
#include <QPushButton>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();


private:



    // 1:左边 网格布局、表格布局
    QGridLayout *lLayout;


    QLabel *UserNumber;
    QLineEdit *UserNumberLineEdit;

    QLabel *UserName;
    QLineEdit *UserNameLineEdit;

    QLabel *UserSex;
    QComboBox *UserSexCombobox;

    QLabel *UserDepart;
    QTextEdit *UserDepartTextEdit;

    QLabel *UserAge;
    QLineEdit *UserAgeLineEdit;


    // 2:右边 水平布局
    QHBoxLayout *toprightlayout;
    QVBoxLayout *rightlayout;

    QLabel *MyselfInfo;
    QTextEdit *MyselfInfoTextEdit;

    // 3:右边底部
    QPushButton *okbutton,*cancelbutton;
    QHBoxLayout *buttomLayout;







};
#endif // DIALOG_H
