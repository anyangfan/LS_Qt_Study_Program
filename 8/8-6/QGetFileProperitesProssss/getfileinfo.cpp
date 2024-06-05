#include "getfileinfo.h"

GetFileInfo::GetFileInfo(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("获取文件属性项目实战模块");

    labelfilename=new QLabel("文件路径名称：");
    qlineeditfilename=new QLineEdit;
    qpushbuttongetfilename=new QPushButton("打开文件...");

    labelfilesize=new QLabel("文件容量大小：");
    qlineeditfilesize=new QLineEdit;

    labelfilecreatetime=new QLabel("文件创建时间：");
    qlineeditfilecreatetime=new QLineEdit;

    labelfilemodifytime=new QLabel("文件修改时间：");
    qlineeditfilemodifytime=new QLineEdit;

    labelfileaccesstime=new QLabel("文件访问时间：");
    qlineeditfileaccesstime=new QLineEdit;


    qlabelfileattribute=new QLabel("文件属性");
    qcheckboxisfile=new QCheckBox("文件");
    qcheckboxishide =new QCheckBox("隐藏属性");
    qcheckboxisreadable =new QCheckBox("只读属性");
    qcheckboxiswritable=new QCheckBox("只写属性");
    qcheckboxisexecute=new QCheckBox("执行权限");
    qpushbuttongetfileattributeinfo=new QPushButton("获取文件属性的全部数据信息...");



    // 布局
    QGridLayout *glayout=new QGridLayout;
    glayout->addWidget(labelfilename,0,0);
    glayout->addWidget(qlineeditfilename,0,1);
    glayout->addWidget(qpushbuttongetfilename,0,2);

    glayout->addWidget(labelfilesize,1,0);
    glayout->addWidget(qlineeditfilesize,1,1,1,2);

    glayout->addWidget(labelfilecreatetime,2,0);
    glayout->addWidget(qlineeditfilecreatetime,2,1,1,2);

    glayout->addWidget(labelfilemodifytime,3,0);
    glayout->addWidget(qlineeditfilemodifytime,3,1,1,2);

    glayout->addWidget(labelfileaccesstime,4,0);
    glayout->addWidget(qlineeditfileaccesstime,4,1,1,2);

    // 水平布局
    QHBoxLayout *hlayout=new QHBoxLayout;
    hlayout->addWidget(qlabelfileattribute);
    hlayout->addStretch();

    QHBoxLayout *hlayoutat=new QHBoxLayout;
    hlayoutat->addWidget(qcheckboxisfile);
    hlayoutat->addWidget(qcheckboxishide);
    hlayoutat->addWidget(qcheckboxisreadable);
    hlayoutat->addWidget(qcheckboxiswritable);
    hlayoutat->addWidget(qcheckboxisexecute);

    QHBoxLayout *hlayoutgetbtn=new QHBoxLayout;
    hlayoutgetbtn->addWidget(qpushbuttongetfileattributeinfo);



    //  垂直布局
    QVBoxLayout *vlayout=new QVBoxLayout(this);
    vlayout->addLayout(glayout);
    vlayout->addLayout(hlayout);
    vlayout->addLayout(hlayoutat);
    vlayout->addLayout(hlayoutgetbtn);


    // 信号与槽函数连接
    connect(qpushbuttongetfilename,SIGNAL(clicked()),this,SLOT(getfilepathandname()));

    connect(qpushbuttongetfileattributeinfo,SIGNAL(clicked()),this,SLOT(getfileattributeinfo()));
}

GetFileInfo::~GetFileInfo()
{
}

void GetFileInfo::getfilepathandname()
{
    QString filepathname;
    filepathname=QFileDialog::getOpenFileName(this,"打开文件对话框","/","files(*)");
    qlineeditfilename->setText(filepathname);

}

void GetFileInfo::getfileattributeinfo()
{
    QString strfile=qlineeditfilename->text();

    QFileInfo qfi(strfile);

    qint64 filesize=qfi.size(); // 获取文件容量大小
    QDateTime createtime=qfi.created(); // 文件创建时间
    QDateTime lastmodifytime=qfi.lastModified(); // 最后修改时间
    QDateTime lastaccesstime=qfi.lastRead(); // 最后访问时间


    bool bfile=qfi.isFile();
    bool bhide=qfi.isHidden();
    bool bread=qfi.isReadable();
    bool bwrite=qfi.isWritable();
    bool bexecute=qfi.isExecutable();


    qlineeditfilesize->setText(QString::number(filesize));
    qlineeditfilecreatetime->setText(createtime.toString());
    qlineeditfilemodifytime->setText(lastmodifytime.toString());
    qlineeditfileaccesstime->setText(lastaccesstime.toString());

    qcheckboxisfile->setCheckState(bfile?Qt::Checked:Qt::Unchecked);
    qcheckboxishide->setCheckState(bhide?Qt::Checked:Qt::Unchecked);
    qcheckboxisreadable->setCheckState(bread?Qt::Checked:Qt::Unchecked);
    qcheckboxiswritable->setCheckState(bwrite?Qt::Checked:Qt::Unchecked);
    qcheckboxisexecute->setCheckState(bexecute?Qt::Checked:Qt::Unchecked);



}

