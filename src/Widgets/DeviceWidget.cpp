#include "DeviceWidget.hpp"
#include "SettingsButton.hpp"
#include "DeviceButton.hpp"
#include "ToggleButton.hpp"
#include <QPushButton>
#include <QStackedLayout>
#include <QDrag>
#include <QCursor>
#include <QMimeData>

DeviceWidget::DeviceWidget(QWidget *parent, int number): QWidget(parent), m_number(number) {
    static int frameNumber = 0;

    this->setStyleSheet("border:none");
    this->setMinimumSize(QSize(200, 100));

    //this->setObjectName((std::string("Frame_")+std::to_string(frameNumber++)).data());


    auto deviceButton = new DeviceButton(this);
    auto toggleButton = new ToggleButton(this);

    toggleButton->move(QPoint(200 - toggleButton->width() -5, 100 - toggleButton->height() - 5));
}


void DeviceWidget::mousePressEvent(QMouseEvent* event) {

}

void DeviceWidget::mouseMoveEvent(QMouseEvent* event) {
    if(event->buttons() == Qt::LeftButton) {
        this->setCursor(Qt::ClosedHandCursor);
        auto drag = new QDrag(this);
        auto mime = new QMimeData;

        mime->setText(QString::number(m_number));
        drag->setMimeData(mime);

        auto dropAction = drag->exec(Qt::MoveAction);
        this->setCursor(Qt::ArrowCursor);
    }

}

void DeviceWidget::mouseReleaseEvent(QMouseEvent* event) {

}
