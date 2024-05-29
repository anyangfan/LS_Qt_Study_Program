#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>

#include <QInputDialog>



class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    QGridLayout *glayout;

    QPushButton *inputstudentnobutton;
    QLineEdit *inputstudentnobuttonLineEdit;

    QPushButton *inputstudentnamebutton;
    QLineEdit *inputstudentnamebuttonLineEdit;

    QPushButton *inputstudentsexbutton;
    QLineEdit *inputstudentsexbuttonLineEdit;

    QPushButton *inputstudentscorebutton;
    QLineEdit *inputstudentscorebuttonLineEdit;

private slots:
    void  modifystudentno();
    void  modifystudentsex();


};
#endif // DIALOG_H
