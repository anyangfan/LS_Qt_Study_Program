#include "qfiledialogtest.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFileDialogTest w;
    w.show();
    return a.exec();
}
