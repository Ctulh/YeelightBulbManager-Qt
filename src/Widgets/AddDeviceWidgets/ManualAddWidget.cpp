
#include "AddDeviceWidgets/ManualAddWidget.hpp"
#include "AddDeviceWidgets/IpAddrLineEdit.hpp"
#include "FileReader.hpp"

#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QSpacerItem>

ManualAddWidget::ManualAddWidget(QWidget* parent): QWidget(parent) {
    auto vBoxLayout = new QVBoxLayout(this);

    auto ipAddrLineEdit = new IpAddrLineEdit;

    auto deviceNameLineEdit = new QLineEdit;
    deviceNameLineEdit->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/DeviceNameLineEdit.css").c_str());

    auto ipAddrLabel = new QLabel("Address");
    ipAddrLabel->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/Labels.css").c_str());

    auto deviceNameLabel = new QLabel("Device Name");
    deviceNameLabel->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/Labels.css").c_str());

    auto verticalSpacer = new QSpacerItem(20,40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vBoxLayout->setSpacing(0);
    vBoxLayout->setMargin(0);

    vBoxLayout->addWidget(ipAddrLabel);
    vBoxLayout->addWidget(ipAddrLineEdit);
    vBoxLayout->addWidget(deviceNameLabel);
    vBoxLayout->addWidget(deviceNameLineEdit);
    vBoxLayout->addItem(verticalSpacer);

}
