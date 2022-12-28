#include "DeviceWidget.hpp"
#include "SettingsButton.hpp"
#include "DeviceButton.hpp"
#include "ToggleButton.hpp"
#include <QPushButton>
#include <QStackedLayout>

DeviceWidget::DeviceWidget(QWidget *parent): QWidget(parent) {
    static int frameNumber = 0;

    this->setStyleSheet("border:none");
    this->setMinimumSize(QSize(200, 100));

    this->setObjectName((std::string("Frame_")+std::to_string(frameNumber++)).data());


    auto deviceButton = new DeviceButton(this);
    auto toggleButton = new ToggleButton(this);

    toggleButton->move(QPoint(200 - toggleButton->width() -5, 100 - toggleButton->height() - 5));
}
