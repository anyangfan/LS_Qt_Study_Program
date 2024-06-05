#ifndef GETFILEINFO_H
#define GETFILEINFO_H

#include <QDialog>

#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>

#include <QFileDialog> // 引用文件对话框
#include <QDateTime>
#include <QHBoxLayout>
#include <QVBoxLayout>

class GetFileInfo : public QDialog
{
    Q_OBJECT

public:
    GetFileInfo(QWidget *parent = nullptr);
    ~GetFileInfo();

private:
    QLabel *labelfilename;
    QLineEdit *qlineeditfilename;
    QPushButton *qpushbuttongetfilename;

    // 文件容量大小
    QLabel *labelfilesize;
    QLineEdit *qlineeditfilesize;

    // 文件创建时间
    QLabel *labelfilecreatetime;
    QLineEdit *qlineeditfilecreatetime;


    // 文件修改时间
    QLabel *labelfilemodifytime;
    QLineEdit *qlineeditfilemodifytime;

    // 文件访问时间
    QLabel *labelfileaccesstime;
    QLineEdit *qlineeditfileaccesstime;

    // 文件属性及复选控件
    QLabel *qlabelfileattribute;

    QCheckBox *qcheckboxisfile;
    QCheckBox *qcheckboxishide;
    QCheckBox *qcheckboxisreadable;
    QCheckBox *qcheckboxiswritable;
    QCheckBox *qcheckboxisexecute;
    QPushButton *qpushbuttongetfileattributeinfo;

    // 声明槽函数
private slots:
    void getfilepathandname();
    void getfileattributeinfo();


};
#endif // GETFILEINFO_H
