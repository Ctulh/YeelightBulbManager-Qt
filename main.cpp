#include "mainwindow.h"

#include <QApplication>
#include "Widgets/FlowLayout.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //auto flowLayout = new FlowLayout;
    //w.setLayout(flowLayout);

    w.show();
    return a.exec();
}
