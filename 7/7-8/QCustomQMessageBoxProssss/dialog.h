#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include <QMessageBox>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QDir>
#include <QCoreApplication>


class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    QLabel *labelmsg,*labeldispmsg;
    QPushButton *msgbutton;

    QGridLayout *glayout;

private slots:
    void customMsg();
};
#endif // DIALOG_H
