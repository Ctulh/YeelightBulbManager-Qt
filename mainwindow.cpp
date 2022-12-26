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
    //this->setStyleSheet("background-color: qlineargradient( x1:0 y1:0, x2:0 y2:5, stop:0 #bcd6d2, stop:1 #f0f0f0);");

    QLinearGradient linearGrad(QPointF(0, 0), QPointF(0, 1000));
    linearGrad.setColorAt(0, "#bcd6d2");
    linearGrad.setColorAt(1, "#f0f0f0");
    QBrush brush(linearGrad);

    QPalette pal = this->palette();
    pal.setBrush(QPalette::Window, brush);
    this->setPalette(pal);
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

