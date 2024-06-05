#include "qdirfileviews.h"

QDirFileViews::QDirFileViews(QWidget *parent)
    : QDialog(parent)
{
    resize(500,350);

    setWindowTitle("QDir类综合控件应用测试");

    filelineedit=new QLineEdit("/");
    filelistwidget=new QListWidget;

    glayout=new QVBoxLayout(this);
    glayout->addWidget(filelineedit);
    glayout->addWidget(filelistwidget);


    // 信号与槽函数连接
    connect(filelineedit,SIGNAL(returnPressed()),this,SLOT(dispdir(QDir)));

    connect(filelistwidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),
            this,SLOT(dispdirshow(QListWidgetItem*)));

    QString root="/";
    QDir rootDir(root);
    QStringList strlist;
    strlist<<"*";

    // entryInfoList函数获取过滤之后获得的文件名夹下面的文件信息列表
    QFileInfoList list=rootDir.entryInfoList(strlist);

    // 调用此函数来显示
    dispfileinfolist(list);

}

QDirFileViews::~QDirFileViews()
{
}


void QDirFileViews::dispfileinfolist(QFileInfoList list) // 显示目录和文件所对应图标
{
    filelistwidget->clear();

    for (unsigned int i=0;i<list.count();i++)
    {
        QFileInfo tempfileinfo=list.at(i);

        if(tempfileinfo.isDir()) // 判断是目录
        {
            QIcon ico("d:/dir.jpg");
            QString filename=tempfileinfo.fileName();
            QListWidgetItem *temp=new QListWidgetItem(ico,filename);
            filelistwidget->addItem(temp);
        }
        else if(tempfileinfo.isFile()) // 判断是文件
        {
            QIcon ico("d:/file.jpg");
            QString filename=tempfileinfo.fileName();
            QListWidgetItem *temp=new QListWidgetItem(ico,filename);
            filelistwidget->addItem(temp);
        }
    }

}

void QDirFileViews::dispdir(QDir dir)
{
    QStringList strlist;
    strlist<<"*";

    QFileInfoList fileinfolist=dir.entryInfoList(strlist,QDir::AllEntries,QDir::DirsFirst);


    dispfileinfolist(fileinfolist);
}

void QDirFileViews::dispdirshow(QListWidgetItem *item)
{
    QDir dir;
    QString str=item->text();

    dir.setPath(filelineedit->text());
    dir.cd(str);

    filelineedit->setText(dir.absolutePath());

    dispdir(dir);
}
