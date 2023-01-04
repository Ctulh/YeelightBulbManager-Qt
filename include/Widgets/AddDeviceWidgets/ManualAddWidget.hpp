
#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QFrame>
#include <QString>


class ManualAddWidget: public QWidget {
    Q_OBJECT
public:
    ManualAddWidget(QWidget* = nullptr);
    virtual ~ManualAddWidget() = default;

public:
    QString getIpAddr() const;
    QString getDeviceName() const;

    void setIpAddrIncorrect();
    void setDeviceNameIncorrect();

private:
    QLineEdit* m_ipAddr;
    QLineEdit* m_deviceName;
};
