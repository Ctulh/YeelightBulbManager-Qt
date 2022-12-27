#include "DeviceWidget.hpp"
#include "SettingsButton.hpp"
#include "DeviceButton.hpp"
#include "ToggleButton.hpp"
#include <QPushButton>
#include <QStackedLayout>

DeviceWidget::DeviceWidget(QWidget *parent): QWidget(parent) {
     static int frameNumber = 0;

     this->setStyleSheet("border:none");

    this->setObjectName((std::string("Frame_")+std::to_string(frameNumber++)).data());
    this->setMinimumSize(QSize(100, 50));
    this->setMaximumSize(QSize(200, 100));


    auto layout = new QStackedLayout;

    auto deviceButton = new DeviceButton();
    layout->addWidget(deviceButton);
    this->setLayout(layout);

    //auto bulbButton = new ToggleButton(this);
    //bulbButton->move(QPoint(200 - bulbButton->width() -5, 100 - bulbButton->height() - 5));
}
