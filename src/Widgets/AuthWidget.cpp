#include "AuthWidget.hpp"
#include <QPushButton>
#include "FileReader.hpp"
#include <QGraphicsDropShadowEffect>
#include <QStackedLayout>
#include <QLineEdit>
#include <QValidator>
#include <QRegExpValidator>

AuthWidget::AuthWidget(QWidget* parent): QFrame(parent) {
    this->setStyleSheet(FileReader::getFileData(":/styles/AuthWidget.css").c_str());

    this->setMinimumSize(400,400);

    auto m_shadowEffect = new QGraphicsDropShadowEffect(this);
    m_shadowEffect->setColor(QColor(0, 0, 0, 255 * 0.3));
    m_shadowEffect->setXOffset(3);
    m_shadowEffect->setYOffset(3);
    m_shadowEffect->setBlurRadius(10);
    setGraphicsEffect(m_shadowEffect);


    auto vBoxLayout = new QVBoxLayout(this);
    auto hBoxLayout = new QHBoxLayout;


    auto manualAdd = new QPushButton("Manual add");
    auto addViaAccount = new QPushButton("Auth account");
    hBoxLayout->addWidget(manualAdd);
    hBoxLayout->addWidget(addViaAccount);

    manualAdd->setStyleSheet("background: rgba(250,100,252,255); ");
    addViaAccount->setStyleSheet("background: rgba(250,100,252,255); ");



    auto stackedLayout = new QStackedLayout;
    auto manualAddWidget = new QWidget;
    auto vBoxLayoutManualAdd = new QVBoxLayout(manualAddWidget);

    auto ipAddrLineEdit = new QLineEdit;
    QString ipRange = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";

    QRegExp ipRegex ("^" + ipRange
                     + "\\." + ipRange
                     + "\\." + ipRange
                     + "\\." + ipRange + "$");
    QRegExpValidator *ipValidator = new QRegExpValidator(ipRegex, this);
    ipAddrLineEdit->setValidator(ipValidator);

    ipAddrLineEdit->setStyleSheet("border: 2px solid; color: black;");
    ipAddrLineEdit->setMaximumHeight(50);
    ipAddrLineEdit->setCursorPosition(0);



    auto deviceNameLineEdit = new QLineEdit;

    deviceNameLineEdit->setStyleSheet("border: 2px solid; color: black;");
    deviceNameLineEdit->setCursorPosition(0);
    deviceNameLineEdit->setMaximumHeight(50);


    vBoxLayoutManualAdd->addWidget(ipAddrLineEdit);
    vBoxLayoutManualAdd->addWidget(deviceNameLineEdit);


    stackedLayout->addWidget(manualAddWidget);

    vBoxLayout->addLayout(hBoxLayout);
    vBoxLayout->addLayout(stackedLayout);

    auto doneButton = new QPushButton("Done");
    doneButton->setStyleSheet("background: rgba(250,100,252,255); ");

    vBoxLayout->addWidget(doneButton);
}
