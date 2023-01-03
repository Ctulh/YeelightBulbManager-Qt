#include "mainwindow.h"
#include <QPushButton>
#include <QStackedLayout>
#include <QToolButton>
#include "./ui_mainwindow.h"
#include "Widgets/DeviceWidget.hpp"
#include "Widgets/FlowLayout.hpp"
#include <QMimeData>
#include <FileReader/FileReader.hpp>
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

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::addDevice() {
    static int number = 0;
    auto authWidget = new AddDeviceWidget(this);

    //m_layout->addItem(authWidget);



    int x = (width() - authWidget->width()) / 2;
    int y = (height() - authWidget->height()) / 2;

    //std::cerr << "width: " << width() << " height: " << height() << '\n';
    //std::cerr << "width: " << authWidget->width() << " height: " << authWidget->height() << '\n';

    authWidget->move(QPoint(x, y));

    authWidget->show();

    //auto it = m_widgets.insert(QString::number(number),new DeviceWidget(nullptr, number));
    //m_layout->addWidget(it.value());
    //number++;
}


void MainWindow::deleteLastDevice() {
    auto widget = m_widgets[m_widgets.lastKey()];

    m_widgets.remove(m_widgets.lastKey());
    m_layout->removeWidget(widget);

    delete widget;
}

void MainWindow::on_MainWindow_iconSizeChanged(const QSize &iconSize)
{

}




void MainWindow::dragEnterEvent(QDragEnterEvent *event) {
    event->accept();
    event->acceptProposedAction();
}

void MainWindow::dropEvent(QDropEvent *event) {
    auto widgetToMove = m_widgets[event->mimeData()->text()];
    m_layout->removeWidget(widgetToMove);


    auto oneElementWidth = 200 + m_layout->horizontalSpacing();
    auto oneElementHeight = 100 + m_layout->verticalSpacing();
    int widthOfWidgetsInTheWindow = (width() / oneElementWidth * oneElementWidth) + 1;


    int columns = (200 + m_layout->horizontalSpacing()) * m_layout->count() / widthOfWidgetsInTheWindow;
    int rows;
    if(columns == 0)
        rows = m_layout->count();
    else
        rows = m_layout->count() / columns;



    auto pos = event->pos();


    int destinationColumn = pos.x() / oneElementWidth;
    int destinationRow = pos.y() / oneElementHeight;


    int insertPos = destinationRow * rows + destinationColumn;
    if(insertPos > m_layout->count()) {
        m_layout->addWidget(widgetToMove);
    }
    else {
        m_layout->insertWidget(insertPos, widgetToMove);
    }

    event->acceptProposedAction();
}

