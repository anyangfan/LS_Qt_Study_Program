#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include <QPushButton>
#include <QLineEdit>
#include <QFontDialog>
#include <QGridLayout>


class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    QGridLayout *glayout;
    QPushButton *fontbutton;
    QLineEdit *fontlineedit;

private slots:
    void dispFontFunc();


};
#endif // DIALOG_H
