#include "mainwindow.h"

#include <QApplication>
#include "Widgets/FlowLayout.hpp"
#include "Presenter/Presenter.hpp"
#include <memory>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto window  = std::make_shared<MainWindow>(nullptr);

    Presenter::getInstance().attach(window);

    window->show();
    return a.exec();
}
