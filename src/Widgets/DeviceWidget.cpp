#include "DeviceWidget.hpp"
#include "SettingsButton.hpp"
#include "DeviceButton.hpp"
#include "ToggleButton.hpp"
#include <QPushButton>
#include <QStackedLayout>
#include <QDrag>
#include <QCursor>
#include <QMimeData>

DeviceWidget::DeviceWidget(QWidget *parent, QString deviceName): QWidget(parent), m_deviceName(deviceName) {
    this->setStyleSheet("border:none");
    this->setMinimumSize(QSize(200, 100));


    auto deviceButton = new DeviceButton(this);
    auto toggleButton = new ToggleButton(this);

    toggleButton->move(QPoint(200 - toggleButton->width() -5, 100 - toggleButton->height() - 5));
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
