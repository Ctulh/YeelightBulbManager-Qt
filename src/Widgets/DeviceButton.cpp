#include "DeviceButton.hpp"
#include <QGraphicsDropShadowEffect>
#include "FileReader/FileReader.hpp"

DeviceButton::DeviceButton(QWidget *parent, int width, int height): QPushButton(parent) {
        this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        this->setStyleSheet(FileReader::getFileData(":/styles/DeviceButton.css").c_str());
        connect(this, SIGNAL(clicked(bool)),this, SLOT(onClick(bool)));
}


void DeviceButton::onClick(bool) {

}
