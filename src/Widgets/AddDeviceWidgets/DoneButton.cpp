
#include "AddDeviceWidgets/DoneButton.hpp"
#include "FileReader/FileReader.hpp"


DoneButton::DoneButton(QWidget* parent): QPushButton("Done", parent) {
    this->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/DoneButton.css").c_str());
}
