/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *labeljpg;
    QTextBrowser *textBrowser;
    QProgressBar *progressBar;
    QCalendarWidget *calendarWidget;
    QPushButton *pushButtonProgressBar;
    QLCDNumber *lcdNumber;
    QPushButton *pushbtnstart;
    QPushButton *pushbtnpause;
    QPushButton *pushbtnreset;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(795, 488);
        labeljpg = new QLabel(Widget);
        labeljpg->setObjectName(QString::fromUtf8("labeljpg"));
        labeljpg->setGeometry(QRect(20, 10, 401, 131));
        textBrowser = new QTextBrowser(Widget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(20, 160, 431, 261));
        progressBar = new QProgressBar(Widget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(20, 440, 611, 31));
        progressBar->setValue(24);
        calendarWidget = new QCalendarWidget(Widget);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(470, 160, 311, 251));
        pushButtonProgressBar = new QPushButton(Widget);
        pushButtonProgressBar->setObjectName(QString::fromUtf8("pushButtonProgressBar"));
        pushButtonProgressBar->setGeometry(QRect(650, 440, 131, 31));
        lcdNumber = new QLCDNumber(Widget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(480, 30, 111, 111));
        pushbtnstart = new QPushButton(Widget);
        pushbtnstart->setObjectName(QString::fromUtf8("pushbtnstart"));
        pushbtnstart->setGeometry(QRect(620, 30, 131, 31));
        pushbtnpause = new QPushButton(Widget);
        pushbtnpause->setObjectName(QString::fromUtf8("pushbtnpause"));
        pushbtnpause->setGeometry(QRect(620, 70, 131, 31));
        pushbtnreset = new QPushButton(Widget);
        pushbtnreset->setObjectName(QString::fromUtf8("pushbtnreset"));
        pushbtnreset->setGeometry(QRect(620, 110, 131, 31));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        labeljpg->setText(QCoreApplication::translate("Widget", "\346\226\207\344\273\266\346\240\207\347\255\276\346\265\213\350\257\225", nullptr));
        pushButtonProgressBar->setText(QCoreApplication::translate("Widget", "\346\265\213\350\257\225\350\277\233\345\272\246\346\235\241", nullptr));
        pushbtnstart->setText(QCoreApplication::translate("Widget", "start", nullptr));
        pushbtnpause->setText(QCoreApplication::translate("Widget", "pause", nullptr));
        pushbtnreset->setText(QCoreApplication::translate("Widget", "reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
