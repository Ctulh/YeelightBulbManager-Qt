#include "DeviceWidget.hpp"
#include "SettingsButton.hpp"
#include "DeviceButton.hpp"
#include "ToggleButton.hpp"
#include "Presenter/Presenter.hpp"

#include <QPushButton>
#include <QStackedLayout>
#include <QDrag>
#include <QCursor>
#include <QMimeData>
#include <string>

DeviceWidget::DeviceWidget(QWidget *parent, QString deviceName): QWidget(parent), m_deviceName(deviceName) {
    this->setStyleSheet("border:none");
    this->setMinimumSize(QSize(200, 100));


    auto deviceButton = new DeviceButton(this);
    m_toggleButton = new ToggleButton(this);

    connect(m_toggleButton, &QPushButton::clicked, this, &DeviceWidget::onClicked);

    m_toggleButton->move(QPoint(200 - m_toggleButton->width() -5, 5));
}

void DeviceWidget::onClicked(bool) {
    if(m_toggleButton->isToggled())
        Presenter::getInstance().turnOnDevice(std::string(m_deviceName.toStdString()));
    else
        Presenter::getInstance().turnOffDevice(std::string(m_deviceName.toStdString()));
}

void DeviceWidget::mouseMoveEvent(QMouseEvent* event) {
    if(event->buttons() == Qt::LeftButton) {
        this->setCursor(Qt::ClosedHandCursor);
        auto drag = new QDrag(this);
        auto mime = new QMimeData;

        mime->setText(m_deviceName);
        drag->setMimeData(mime);

        auto dropAction = drag->exec(Qt::MoveAction);
        this->setCursor(Qt::ArrowCursor);
    }

}
