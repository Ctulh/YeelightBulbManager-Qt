#pragma once

#include <QWidget>
#include <QLineEdit>

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

    void clearLineEdits();

private:
    QLineEdit* m_ipAddrLineEdit;
    QLineEdit* m_deviceNameLineEdit;
};
