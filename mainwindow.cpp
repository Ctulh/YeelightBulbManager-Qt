#include "mainwindow.h"
#include <QPushButton>
#include <QStackedLayout>
#include <QToolButton>
#include "./ui_mainwindow.h"
#include <QFrame>
#include "Widgets/SettingsButton.hpp"

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
    const QSize bulbBtnSize(200,100);


    //QStackedLayout* newLayout = new QStackedLayout(this);
    //newLayout->setStackingMode(QStackedLayout::StackAll);






    //bulbButton->setFixedSize(bulbBtnSize);

    //newLayout->addWidget(bulbButton);
    //newLayout->addWidget(bulbSettingsBtn);


    //ui->gridLayout->addLayout(newLayout, 0, 1);



    auto frame = new QFrame(this);
    static int frameNumber = 0;
    frame->setObjectName((std::string("Frame_")+std::to_string(frameNumber++)).data());
    frame->setMinimumSize(QSize(100,100));
    frame->setMaximumSize(QSize(100,100));
    frame->setFrameShape(QFrame::StyledPanel);
    frame->setFrameShadow(QFrame::Raised);

    auto bulbButton = new QPushButton("Bulb", frame);
    auto bulbSettingsBtn = new SettingsButton(frame);


    static int column = 1;
    static int row = 0;

    ui->gridLayout->addWidget(frame, row, column++, Qt::AlignLeft);
    if(column%5 == 0) {
        column = 0;
        row++;
    }






    //auto addDeviceButton = ui->gridLayout[0][0];
    //ui->gridLayout->replaceWidget()
    //ui->gridLayout->addItem(newButton);


}

