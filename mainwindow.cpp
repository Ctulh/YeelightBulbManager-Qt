#include "mainwindow.h"
#include <QPushButton>
#include <QStackedLayout>
#include <QToolButton>
#include "./ui_mainwindow.h"
#include "Widgets/DeviceWidget.hpp"
#include "Widgets/FlowLayout.hpp"
#include <QMimeData>
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
    QAction* deleteLast = new QAction("DeleteLast");

    m_addDeviceButton->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceButton.css").c_str());

    m_addDeviceButton->setMinimumSize(200,100);
    m_addDeviceButton->addAction(addDeviceAction);
    m_addDeviceButton->addAction(scanDeviceAction);
    m_addDeviceButton->addAction(deleteLast);

    connect(m_addDeviceButton, SIGNAL(clicked(bool)),this, SLOT(onClick(bool)));
    connect(m_addDeviceButton, SIGNAL(triggered(QAction*)),this, SLOT(onTriggered(QAction*)));


    m_layout = new FlowLayout;
    m_layout->addWidget(m_addDeviceButton);


    setAcceptDrops(true);

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
        static int number = 0;
        auto it = m_widgets.insert(QString::number(number),new DeviceWidget(nullptr, number));
        m_layout->addWidget(it.value());
        number++;
    }
    else if (arg1->text() == "DeleteLast") {
        auto widget = m_widgets[m_widgets.lastKey()];

        m_widgets.remove(m_widgets.lastKey());
        m_layout->removeWidget(widget);

        delete widget;
    }
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event) {
    event->accept();
    event->acceptProposedAction();
}

void MainWindow::dropEvent(QDropEvent *event) {
    auto widgetToMove = m_widgets[event->mimeData()->text()];
    m_layout->removeWidget(widgetToMove);
    //auto widgets = m_layout->getWidgetsList();


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

