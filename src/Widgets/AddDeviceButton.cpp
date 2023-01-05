#include "AddDeviceButton.hpp"
#include "FileReader/FileReader.hpp"

AddDeviceButton::AddDeviceButton(QWidget* parent): QToolButton(parent) {
    this->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceButton.css").c_str());

    connect(this, SIGNAL(clicked(bool)),this, SLOT(onClick(bool)));
}

void AddDeviceButton::onClick(bool)
{
    this->showMenu();
}
