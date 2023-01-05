#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMimeData>
#include <QPushButton>
#include <QToolButton>
#include <QStackedLayout>

#include "Presenter/Presenter.hpp"
#include "Widgets/DeviceWidget.hpp"
#include "FileReader/FileReader.hpp"
#include "Widgets/AddDeviceButton.hpp"
#include "Widgets/AddDeviceWidgets/AddDeviceWidget.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet(FileReader::getFileData(":/styles/MainWindow.css").c_str());

    auto addDeviceButton = new AddDeviceButton(this);


    QAction* addDeviceAction = new QAction("Add");
    connect(addDeviceAction, &QAction::triggered, this, &MainWindow::addDevice);
    addDeviceButton->addAction(addDeviceAction);

    QAction* scanDeviceAction = new QAction("Scan");
    addDeviceButton->addAction(scanDeviceAction);

    QAction* deleteLastAction = new QAction("DeleteLast");
    connect(deleteLastAction, &QAction::triggered, this, &MainWindow::deleteLastDevice);
    addDeviceButton->addAction(deleteLastAction);


    m_layout = new FlowLayout;
    m_layout->addWidget(addDeviceButton);


    setAcceptDrops(true);

    ui->centralwidget->setLayout(m_layout);

    m_addDeviceWidget = new AddDeviceWidget(this);
    m_addDeviceWidget->hide();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::addDevice() {
    int x = (width() - m_addDeviceWidget->width()) / 2;
    int y = (height() - m_addDeviceWidget->height()) / 2;

    m_addDeviceWidget->move(QPoint(x, y));
    m_addDeviceWidget->show();
}


void MainWindow::deleteLastDevice() {
    auto widget = m_widgets[m_widgets.lastKey()];

    m_widgets.remove(m_widgets.lastKey());
    m_layout->removeWidget(widget);

    delete widget;
}


void MainWindow::update(const std::string &message) {
    if(message == "new device") {
        auto devices = Presenter::getInstance().getDevices();
        for(auto device: devices) {
            if(not m_widgets.contains(device->getDeviceName())) {
                auto deviceWidget = new DeviceWidget(nullptr, QString(device->getDeviceName().c_str()));
                auto it = m_widgets.insert(device->getDeviceName(), deviceWidget);
                m_layout->addWidget(it.value());
            }
        }
    }
}

void MainWindow::on_MainWindow_iconSizeChanged(const QSize &iconSize)
{

}


void MainWindow::dragEnterEvent(QDragEnterEvent *event) {
    event->accept();
    event->acceptProposedAction();
}

void MainWindow::dropEvent(QDropEvent *event) {
    auto widgetToMove = m_widgets[event->mimeData()->text().toStdString()];
    m_layout->removeWidget(widgetToMove);


    auto oneElementWidth = 200 + m_layout->horizontalSpacing();
    auto oneElementHeight = 100 + m_layout->verticalSpacing();
    int widthOfWidgetsInTheWindow = (width() / oneElementWidth * oneElementWidth) + 1;


    int columnsAmount = (200 + m_layout->horizontalSpacing()) * m_layout->count() / widthOfWidgetsInTheWindow;
    int rowsAmount = 0;
    if(columnsAmount == 0)
        rowsAmount = m_layout->count();
    else
        rowsAmount = m_layout->count() / columnsAmount;

    auto pos = event->pos();


    int destinationColumn = pos.x() / oneElementWidth;
    int destinationRow = pos.y() / oneElementHeight;


    int insertPos = destinationRow * rowsAmount + destinationColumn;
    if(insertPos > m_layout->count()) {
        m_layout->addWidget(widgetToMove);
    }
    else {
        m_layout->insertWidget(insertPos, widgetToMove);
    }

    event->acceptProposedAction();
}

