#include "AddDeviceButton.hpp"
#include "FileReader/FileReader.hpp"

AddDeviceButton::AddDeviceButton(QWidget* parent): QToolButton(parent) {
    this->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceButton.css").c_str());

    this->setMinimumSize(200,100);


    connect(this, SIGNAL(clicked(bool)),this, SLOT(onClick(bool)));
   // connect(this, SIGNAL(triggered(QAction*)),this, SLOT(onTriggered(QAction*)));
}

void AddDeviceButton::onClick(bool)
{
    this->showMenu();
}
