#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


// 1:Combo Box控件
#include <QComboBox>


// 2:FontComboBox控件
#include <QFontComboBox>
#include <QLabel>

// 3:Line Edit控件
#include <QLineEdit>
#include <QPushButton>

// 4:Plain Text Edit控件
#include <QPlainTextEdit>
#include <QRadioButton>

// 5:Spin Box控件
#include <QSpinBox>

// 6:时间控件
#include <QTimeEdit>
#include <QDateEdit>
#include <QDateTimeEdit>


// 7: Scroll Bar控件
#include <QScrollBar>

// 8: Key Sequence Edit控件
#include <QKeySequenceEdit>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;



    // 1:声明一个QComboBox对象
private:
    QComboBox *combobox;
private slots:
    void comboboxIndex(int);

    // 2:声明QFontComboBox/QLabel对象
private:
    QFontComboBox *fontcombobox;
    QLabel *qlabels;
private slots:
    void fontcomboboxFunc(QFont);

    // 3:声明QLineEdit/QPushButton/QLabel对象
private:
    QLineEdit *lineedit;
    QPushButton *pushbutton;
    QLabel *qlabely;
private slots:
    void pushbuttonclicked();

    // 4:声明QPlainTextEdit/QRadioButton对象
private:
    QPlainTextEdit *plaintedit;
    QRadioButton *radiobutton;
private slots:
    void radioButtonClicked();

    // 5:声明QPlainTextEdit/QRadioButton对象
private:
    QSpinBox *spinbox;
private slots:
    void spinboxValueChanged(int);

    // 6:声明QDateTimeEdit/QTimeEdit/QDateEdit对象
private:
    QDateTimeEdit *dte;
    QTimeEdit *te;
    QDateEdit *de;

    // 7:声明QScrollBar对象
private:
    QScrollBar *hscrollbar,*vscrollbar;


    // 8:声明QKeySequenceEdit对象
private:
    QKeySequenceEdit *kse;
private slots:
    void keyseqeditChanged(const QKeySequence &);

};
#endif // MAINWINDOW_H
