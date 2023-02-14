#include "widget.h"

#include <QApplication>
#include <QDomComment>
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
//    QDomComment docment;
//    QFile file();

    w.show();
    return a.exec();
}
