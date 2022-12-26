#include "DeviceWidget.hpp"
#include "SettingsButton.hpp"
#include "DeviceButton.hpp"
#include "ToggleButton.hpp"
#include <QPushButton>

DeviceWidget::DeviceWidget(QWidget *parent): QFrame(parent) {

    constexpr int FRAME_WIDTH = 200;
    constexpr int FRAME_HEIGHT = 100;

     static int frameNumber = 0;

     this->setStyleSheet("border:none");

    this->setObjectName((std::string("Frame_")+std::to_string(frameNumber++)).data());
    this->setMinimumSize(QSize(FRAME_WIDTH, FRAME_HEIGHT));
    this->setMaximumSize(QSize(FRAME_WIDTH, FRAME_HEIGHT));
    this->setFrameShape(QFrame::StyledPanel);
    this->setFrameShadow(QFrame::Raised);

    auto deviceButton = new DeviceButton(this, FRAME_WIDTH, FRAME_HEIGHT);


    auto bulbButton = new ToggleButton(this);
    bulbButton->move(QPoint(FRAME_WIDTH - bulbButton->width() -5, FRAME_HEIGHT - bulbButton->height() - 5));

    //auto bulbSettingsBtn = new SettingsButton(this);
    //bulbSettingsBtn->move(QPoint(FRAME_WIDTH - bulbSettingsBtn->width(),0));

}
