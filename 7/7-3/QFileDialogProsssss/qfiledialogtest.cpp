#include "qfiledialogtest.h"

QFileDialogTest::QFileDialogTest(QWidget *parent)
    : QDialog(parent)
{
    // 1:创建控件
    FileNameLabel = new QLabel("文件名称：");
    FileNameLineEdit = new QLineEdit;
    FileButton = new QPushButton("选择...");

    FileSizeLabel = new QLabel("文件大小：");
    FileSizeLabelLineEdit = new QLineEdit;

    GetFileInfoButton = new QPushButton("获取文件大小信息");

    // 2:排列布局
    QGridLayout *glayout = new QGridLayout;
    glayout->addWidget(FileNameLabel, 0, 0);
    glayout->addWidget(FileNameLineEdit, 0, 1);
    glayout->addWidget(FileButton, 0, 2);

    glayout->addWidget(FileSizeLabel, 1, 0);
    glayout->addWidget(FileSizeLabelLineEdit, 1, 1, 1, 2);

    /* QHBoxLayout *hlayout=new QHBoxLayout;
    hlayout->addWidget(GetFileInfoButton);


    QVBoxLayout *vlayout=new QVBoxLayout(this);
    vlayout->addLayout(glayout);
    vlayout->addLayout(hlayout); */
    glayout->addWidget(GetFileInfoButton, 2, 0, 1, 3);

    setLayout(glayout);

    // 信号槽函数连接
    connect(FileButton, SIGNAL(clicked()), this, SLOT(GetFileInfoFunc()));
    connect(GetFileInfoButton, SIGNAL(clicked()), this, SLOT(GetFileSizeFunc()));
}

QFileDialogTest::~QFileDialogTest()
{
}

void QFileDialogTest::GetFileInfoFunc() // 用于打开文件
{
    QString strFileName = QFileDialog::getOpenFileName(this, "打开", "/", "Files(*)");
    /* 函数用于打开一个文件选择对话框，允许用户从指定的目录中选择一个文件。函数返回所选文件的路径作为字符串。
    具体说明：
        this 表示当前的窗口或对象作为父对象。
        "打开" 是对话框的标题，可以自定义。
        "/" 是对话框默认打开的目录，可以根据需要指定。
        "Files(*)" 是过滤器，表示可以选择所有类型的文件。可以根据需要指定特定的文件类型过滤器。 */
    FileNameLineEdit->setText(strFileName);
}

void QFileDialogTest::GetFileSizeFunc() // 用于获取文件大小
{
    // 获取单行编辑框控件里面文件路径等
    QString strFileNames = FileNameLineEdit->text();

    QFileInfo fileinfo(strFileNames);

    qint64 FileSize = fileinfo.size();

    FileSizeLabelLineEdit->setText(QString::number(FileSize));
}
