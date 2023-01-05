#pragma once

#include <QWidget>
#include <QMouseEvent>

class DeviceWidget: public QWidget {
    Q_OBJECT
public:
    explicit DeviceWidget(QWidget *parent = nullptr, QString deviceName = "EmptyName");

public:
    void mouseMoveEvent(QMouseEvent*) override;
private:
    QString m_deviceName;
};
