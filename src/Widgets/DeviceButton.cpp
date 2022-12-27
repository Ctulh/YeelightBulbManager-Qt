#include "DeviceButton.hpp"
#include <QGraphicsDropShadowEffect>

DeviceButton::DeviceButton(QWidget *parent, int width, int height): QPushButton(parent) {
        this->setMinimumSize(200, 100);
        this->setMaximumSize(200, 100);
       //this->setFixedSize(parent->size());
        this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

        this->setStyleSheet(
        "QPushButton{"
        "background: rgba(250,252,252,255); "
        "outline: none;"
        "border-radius: 15px;"
        "border-style: outset;}"
        "QPushButton:hover {"
                "background-color:#e3e3e3;"
            "}");

        connect(this, SIGNAL(clicked(bool)),this, SLOT(onClick(bool)));
}


void DeviceButton::onClick(bool) {

}
