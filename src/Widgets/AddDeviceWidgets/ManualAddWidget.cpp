
#include "AddDeviceWidgets/ManualAddWidget.hpp"
#include "AddDeviceWidgets/IpAddrLineEdit.hpp"
#include "FileReader.hpp"
#include "AddDeviceWidgets/PrettyLineEdit.hpp"

#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QSpacerItem>

ManualAddWidget::ManualAddWidget(QWidget* parent): QWidget(parent) {
    auto vBoxLayout = new QVBoxLayout(this);

    m_ipAddr = new IpAddrLineEdit;
    m_deviceName = new PrettyLineEdit;

    auto ipAddrLabel = new QLabel("Address");
    ipAddrLabel->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/Labels.css").c_str());

    auto deviceNameLabel = new QLabel("Device Name");
    deviceNameLabel->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/Labels.css").c_str());

    auto verticalSpacer = new QSpacerItem(20,40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vBoxLayout->setSpacing(0);
    vBoxLayout->setMargin(0);

    auto spacingWidgetBeforeLineEdits = new QFrame;
    spacingWidgetBeforeLineEdits->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/SpaceElementBeforeLineEdits.css").c_str());

    auto spacingWidgetBetweenLineEdits = new QFrame;
    spacingWidgetBetweenLineEdits->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/SpaceElementBetweenLineEdits.css").c_str());

    vBoxLayout->addWidget(spacingWidgetBeforeLineEdits);
    vBoxLayout->addWidget(ipAddrLabel);
    vBoxLayout->addWidget(m_ipAddr);
    vBoxLayout->addWidget(spacingWidgetBetweenLineEdits);
    vBoxLayout->addWidget(deviceNameLabel);
    vBoxLayout->addWidget(m_deviceName);
    vBoxLayout->addItem(verticalSpacer);
}

QString ManualAddWidget::getIpAddr() const {
    return m_ipAddr->text();
}

QString ManualAddWidget::getDeviceName() const {
    return m_deviceName->text();
}

void ManualAddWidget::setIpAddrIncorrect() {
    m_ipAddr->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/PrettyLineEdit_Incorrect.css").c_str());
}

void ManualAddWidget::setDeviceNameIncorrect() {
    m_deviceName->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/PrettyLineEdit_Incorrect.css").c_str());
}

