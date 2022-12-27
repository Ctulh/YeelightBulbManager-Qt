#include "mainwindow.h"
#include <QPushButton>
#include <QStackedLayout>
#include <QToolButton>
#include "./ui_mainwindow.h"
#include "Widgets/DeviceWidget.hpp"
#include "Widgets/FlowLayout.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      m_addDeviceButton(new QToolButton(this))
{
    ui->setupUi(this);
    QLinearGradient linearGrad(QPointF(0, 0), QPointF(0, 1000));
    linearGrad.setColorAt(0, "#bcd6d2");
    linearGrad.setColorAt(1, "#f0f0f0");
    QBrush brush(linearGrad);

    QPalette pal = this->palette();
    pal.setBrush(QPalette::Window, brush);
    this->setPalette(pal);

   // ui->gridLayout->setAlignment({Qt::AlignLeft, Qt::AlignTop});


    QAction* addDeviceAction = new QAction("Add");
    QAction* scanDeviceAction = new QAction("Scan");


    m_addDeviceButton->setStyleSheet(
    "QToolButton{"
                "icon: url(:/icons/add.png);"
    "background: rgba(250,252,252,255); "
    "outline: none;"
    "border-radius: 15px;"
    "border-style: outset;}"
    "QToolButton:hover {"
            "background-color:#e3e3e3;"
        "}");


    m_addDeviceButton->setMinimumSize(200,100);
    m_addDeviceButton->addAction(addDeviceAction);
    m_addDeviceButton->addAction(scanDeviceAction);


    connect(m_addDeviceButton, SIGNAL(clicked(bool)),this, SLOT(onClick(bool)));
    connect(m_addDeviceButton, SIGNAL(triggered(QAction*)),this, SLOT(onTriggered(QAction*)));

    m_layout = new FlowLayout;
    m_layout->addWidget(m_addDeviceButton);

    ui->centralwidget->setLayout(m_layout);

    //ui->gridLayout->

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_MainWindow_iconSizeChanged(const QSize &iconSize)
{

}


void MainWindow::onClick(bool)
{
    m_addDeviceButton->showMenu();
}

//

void MainWindow::onTriggered(QAction *arg1)
{
    if(arg1->text() == "Add") {
        auto deviceWidget = new DeviceWidget();


        static int column = 1;
        static int row = 0;

       // ui->gridLayout->addWidget(deviceWidget, row, column++);

        m_layout->addWidget(deviceWidget);

        if(column%4 == 0) {
           column = 0;
           row++;
        }
    }

}

