#include "mainwindow.h"
#include <QPushButton>
#include <QStackedLayout>
#include <QToolButton>
#include "./ui_mainwindow.h"
#include "Widgets/DeviceWidget.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{


     auto deviceWidget = new DeviceWidget(this);


    static int column = 1;
    static int row = 0;

    ui->gridLayout->addWidget(deviceWidget, row, column++);
    if(column%5 == 0) {
        column = 0;
        row++;
    }






    //auto addDeviceButton = ui->gridLayout[0][0];
    //ui->gridLayout->replaceWidget()
    //ui->gridLayout->addItem(newButton);


}

