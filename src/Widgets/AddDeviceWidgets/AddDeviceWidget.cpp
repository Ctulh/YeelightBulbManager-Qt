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

AddDeviceWidget::AddDeviceWidget(QWidget* parent): QFrame(parent), m_stackedWidget(new QStackedWidget) {
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


    auto manualAddBtn = new QPushButton("Manual");
    auto authAccountBtn = new QPushButton("Auth account");

    connect(manualAddBtn, &QPushButton::clicked, this, &AddDeviceWidget::onManualAddClicked);
    connect(authAccountBtn, &QPushButton::clicked, this, &AddDeviceWidget::onAuthAccountClicked);

    manualAddBtn->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/ManualButton.css").c_str());
    authAccountBtn->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/ManualButton.css").c_str());

    hBoxLayout->addWidget(manualAddBtn);
    hBoxLayout->addWidget(authAccountBtn);

    auto manualAddWidget = new ManualAddWidget;
    auto authAccountWidget = new AuthAccountWidget;

    m_stackedWidget->addWidget(manualAddWidget);
    m_stackedWidget->addWidget(authAccountWidget);

    vBoxLayout->addLayout(hBoxLayout);
    vBoxLayout->addWidget(m_stackedWidget);


    auto doneButtonWidget = new QWidget;
    auto doneButtonLayout = new QHBoxLayout(doneButtonWidget);
    auto doneButton = new DoneButton;

    doneButtonLayout->addWidget(doneButton);


    vBoxLayout->addWidget(doneButtonWidget, Qt::AlignCenter);
}

void AddDeviceWidget::onManualAddClicked(bool) {
    m_stackedWidget->setCurrentIndex(0);
}

void AddDeviceWidget::onAuthAccountClicked(bool) {
    m_stackedWidget->setCurrentIndex(1);
}


AddDeviceWidget::~AddDeviceWidget() {
    if(m_stackedWidget)
        delete m_stackedWidget;
}
