#include "DeviceButton.hpp"
#include <QGraphicsDropShadowEffect>
#include "FileReader/FileReader.hpp"

DeviceButton::DeviceButton(QWidget *parent, int width, int height): QPushButton(parent) {
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setStyleSheet(FileReader::getFileData(":/styles/DeviceButton.css").c_str());

    QPixmap pixmap(":/icons/bulb.png");
    QIcon buttonIcon(pixmap);
    const QSize iconSize(50,50);
    this->setIcon(buttonIcon);
    this->setIconSize(iconSize);

    connect(this, SIGNAL(clicked(bool)),this, SLOT(onClick(bool)));
}


void DeviceButton::onClick(bool) {

}
