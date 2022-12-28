#include "mainwindow.h"
#include <QPushButton>
#include <QStackedLayout>
#include <QToolButton>
#include "./ui_mainwindow.h"
#include "Widgets/DeviceWidget.hpp"
#include "Widgets/FlowLayout.hpp"
#include <FileReader/FileReader.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      m_addDeviceButton(new QToolButton(this))
{
    ui->setupUi(this);
    this->setStyleSheet(FileReader::getFileData(":/styles/MainWindow.css").c_str());

    QAction* addDeviceAction = new QAction("Add"); // TODO separete to class AddDeviceButton
    QAction* scanDeviceAction = new QAction("Scan");

    m_addDeviceButton->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceButton.css").c_str());

    m_addDeviceButton->setMinimumSize(200,100);
    m_addDeviceButton->addAction(addDeviceAction);
    m_addDeviceButton->addAction(scanDeviceAction);


    connect(m_addDeviceButton, SIGNAL(clicked(bool)),this, SLOT(onClick(bool)));
    connect(m_addDeviceButton, SIGNAL(triggered(QAction*)),this, SLOT(onTriggered(QAction*)));

    m_layout = new FlowLayout;
    m_layout->addWidget(m_addDeviceButton);

    ui->centralwidget->setLayout(m_layout);

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


void MainWindow::onTriggered(QAction *arg1)
{
    if(arg1->text() == "Add") {
        auto deviceWidget = new DeviceWidget();
        m_layout->addWidget(deviceWidget);
    }

}

