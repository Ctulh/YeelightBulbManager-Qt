#pragma once

#include <QWidget>
#include <QMouseEvent>

#include "ToggleButton.hpp"

class DeviceWidget: public QWidget {
    Q_OBJECT
public:
    explicit DeviceWidget(QWidget *parent = nullptr, QString deviceName = "EmptyName");

public:
    void mouseMoveEvent(QMouseEvent*) override;

public slots:
    void onClicked(bool);

private:
    QString m_deviceName;
    ToggleButton* m_toggleButton;
};
