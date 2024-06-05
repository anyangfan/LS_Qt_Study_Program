#include "keyboardevent.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    keyboardevent w;
    w.show();
    return a.exec();
}
