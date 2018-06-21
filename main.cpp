//-------------------------
//
// file created by Prouteau Antonin
// 14/06/2018
//
//-------------------------

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
//    QLoggingCategory::setFilterRules("*.debug=true\nqt.*.debug=false");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
