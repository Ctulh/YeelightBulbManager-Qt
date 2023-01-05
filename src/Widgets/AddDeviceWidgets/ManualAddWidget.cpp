
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

    m_ipAddrLineEdit = new IpAddrLineEdit;
    m_deviceNameLineEdit = new PrettyLineEdit;

    auto ipAddrLabel = new QLabel("Address");
    ipAddrLabel->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/Labels.css").c_str());

    auto deviceNameLabel = new QLabel("Device Name");
    deviceNameLabel->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/Labels.css").c_str());

    auto verticalSpacer = new QSpacerItem(20,40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vBoxLayout->setSpacing(0);
    vBoxLayout->setMargin(0);

    auto frameBeforeLineEdits = new QFrame; // to be able to change the distance before the first LineEdit
    frameBeforeLineEdits->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/SpaceElementBeforeLineEdits.css").c_str());

    auto frameBetweenLineEdits = new QFrame; // to be able to change the distance between lineEdit's
    frameBetweenLineEdits->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/SpaceElementBetweenLineEdits.css").c_str());

    vBoxLayout->addWidget(frameBeforeLineEdits);
    vBoxLayout->addWidget(ipAddrLabel);
    vBoxLayout->addWidget(m_ipAddrLineEdit);
    vBoxLayout->addWidget(frameBetweenLineEdits);
    vBoxLayout->addWidget(deviceNameLabel);
    vBoxLayout->addWidget(m_deviceNameLineEdit);
    vBoxLayout->addItem(verticalSpacer);
}

QString ManualAddWidget::getIpAddr() const {
    return m_ipAddrLineEdit->text();
}

QString ManualAddWidget::getDeviceName() const {
    return m_deviceNameLineEdit->text();
}

void ManualAddWidget::setIpAddrIncorrect() {
    m_ipAddrLineEdit->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/PrettyLineEdit_Incorrect.css").c_str());
}

void ManualAddWidget::setDeviceNameIncorrect() {
    m_deviceNameLineEdit->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/PrettyLineEdit_Incorrect.css").c_str());
}

void ManualAddWidget::clearLineEdits() {
    m_ipAddrLineEdit->clear();
    m_deviceNameLineEdit->clear();
}

