#ifndef QFILEDIALOGTEST_H
#define QFILEDIALOGTEST_H

#include <QDialog>

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout> // 水平布局
#include <QVBoxLayout> // 垂直布局

#include <QFileDialog>

class QFileDialogTest : public QDialog
{
    Q_OBJECT

public:
    QFileDialogTest(QWidget *parent = nullptr);
    ~QFileDialogTest();

private:
    QLabel *FileNameLabel;
    QLineEdit *FileNameLineEdit;

    QPushButton *FileButton;

    QLabel *FileSizeLabel;
    QLineEdit *FileSizeLabelLineEdit;

    QPushButton *GetFileInfoButton;

private slots:
    void GetFileInfoFunc(); // 用于打开文件
    void GetFileSizeFunc(); // 用于获取文件大小



};
#endif // QFILEDIALOGTEST_H
