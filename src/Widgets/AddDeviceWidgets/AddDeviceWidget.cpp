#include "AddDeviceWidgets/AddDeviceWidget.hpp"
#include <QPushButton>
#include "FileReader.hpp"
#include <QGraphicsDropShadowEffect>
#include <QStackedLayout>
#include <QLineEdit>


#include "AddDeviceWidgets/ManualAddWidget.hpp"
#include "AddDeviceWidgets/AuthAccountWidget.hpp"
#include "AddDeviceWidgets/IpAddrLineEdit.hpp"
#include "AddDeviceWidgets/DoneButton.hpp"

AddDeviceWidget::AddDeviceWidget(QWidget* parent): QFrame(parent),
                                                   m_stackedWidget(new QStackedWidget),
                                                   m_manualAddBtn(new QPushButton("Manual")),
                                                   m_authAccountBtn(new QPushButton("Auth account")) {
    this->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/AddDeviceWidget.css").c_str());

    this->setMinimumSize(400,400);

    auto m_shadowEffect = new QGraphicsDropShadowEffect(this);
    m_shadowEffect->setColor(QColor(0, 0, 0, 255 * 0.3));
    m_shadowEffect->setXOffset(3);
    m_shadowEffect->setYOffset(3);
    m_shadowEffect->setBlurRadius(10);
    setGraphicsEffect(m_shadowEffect);

    auto vBoxLayout = new QVBoxLayout(this);
    auto hBoxLayout = new QHBoxLayout;


    connect(m_manualAddBtn, &QPushButton::clicked, this, &AddDeviceWidget::onManualAddClicked);
    connect(m_authAccountBtn, &QPushButton::clicked, this, &AddDeviceWidget::onAuthAccountClicked);

    m_manualAddBtn->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/ChooseWayToAddDeviceButton_Selected.css").c_str());
    m_authAccountBtn->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/ChooseWayToAddDeviceButton.css").c_str());


    hBoxLayout->addWidget(m_manualAddBtn);
    hBoxLayout->addWidget(m_authAccountBtn);

    m_manualAddWidget = new ManualAddWidget;
    auto authAccountWidget = new AuthAccountWidget;

    m_stackedWidget->addWidget(m_manualAddWidget);
    m_stackedWidget->addWidget(authAccountWidget);

    vBoxLayout->addLayout(hBoxLayout);
    vBoxLayout->addWidget(m_stackedWidget);


    auto doneButtonWidget = new QWidget;
    auto doneButtonLayout = new QHBoxLayout(doneButtonWidget);
    auto doneButton = new DoneButton;
    connect(doneButton, &QPushButton::clicked, this, &AddDeviceWidget::onDoneButtonClicked);

    doneButtonLayout->addWidget(doneButton);


    vBoxLayout->addWidget(doneButtonWidget, Qt::AlignCenter);
}

void AddDeviceWidget::onManualAddClicked(bool) {
    m_authAccountBtn->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/ChooseWayToAddDeviceButton.css").c_str());
    m_manualAddBtn->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/ChooseWayToAddDeviceButton_Selected.css").c_str());
    m_stackedWidget->setCurrentIndex(0);
}

void AddDeviceWidget::onAuthAccountClicked(bool) {
    m_authAccountBtn->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/ChooseWayToAddDeviceButton_Selected.css").c_str());
    m_manualAddBtn->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/ChooseWayToAddDeviceButton.css").c_str());
    m_stackedWidget->setCurrentIndex(1);
}

void AddDeviceWidget::onDoneButtonClicked(bool) {
    auto ipAddr = m_manualAddWidget->getIpAddr();
    auto deviceName = m_manualAddWidget->getDeviceName();
    if(ipAddr.size() == 0) {
        m_manualAddWidget->setIpAddrIncorrect();
        return;
    }
    if(deviceName.size() == 0) {
        m_manualAddWidget->setDeviceNameIncorrect();
        return;
    }
    this->hide();
}

AddDeviceWidget::~AddDeviceWidget() {
    if(m_stackedWidget)
        delete m_stackedWidget;
}
