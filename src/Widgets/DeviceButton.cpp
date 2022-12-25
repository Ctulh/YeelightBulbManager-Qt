#include "DeviceButton.hpp"

DeviceButton::DeviceButton(QWidget *parent, int width, int height): QPushButton(parent) {
    this->setMinimumSize(width, height);
    this->setMaximumSize(width, height);
    connect(this, SIGNAL(clicked(bool)),this, SLOT(onClick(bool)));
}


void DeviceButton::onClick(bool) {

}
