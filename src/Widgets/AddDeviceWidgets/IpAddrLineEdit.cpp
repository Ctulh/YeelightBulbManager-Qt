
#include "AddDeviceWidgets/IpAddrLineEdit.hpp"
#include "FileReader.hpp"

#include <QValidator>
#include <QRegExpValidator>

IpAddrLineEdit::IpAddrLineEdit(QWidget* parent): QLineEdit(parent) {
    //auto ipAddrLineEdit = new QLineEdit;
    QString ipRange = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";

    QRegExp ipRegex ("^" + ipRange
                     + "\\." + ipRange
                     + "\\." + ipRange
                     + "\\." + ipRange + "$");
    QRegExpValidator *ipValidator = new QRegExpValidator(ipRegex, this);
    this->setValidator(ipValidator);

    this->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/IpAddrLineEdit.css").c_str());

    this->setCursorPosition(0);
}
