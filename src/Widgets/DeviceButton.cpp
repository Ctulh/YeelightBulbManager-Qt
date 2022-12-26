#include "DeviceButton.hpp"
#include <QGraphicsDropShadowEffect>

DeviceButton::DeviceButton(QWidget *parent, int width, int height): QPushButton(parent) {
    this->setMinimumSize(width, height);
    this->setMaximumSize(width, height);
    this->setStyleSheet(
    "QPushButton{"
    "background: rgba(250,252,252,255); "
    "outline: none;"
    "border-radius: 15px;"
    "border-style: outset;}");

    connect(this, SIGNAL(clicked(bool)),this, SLOT(onClick(bool)));
}


void DeviceButton::onClick(bool) {

}
