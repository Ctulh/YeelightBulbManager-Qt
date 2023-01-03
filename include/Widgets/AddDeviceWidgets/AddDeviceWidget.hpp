
#pragma once

#include <QWidget>
#include <QStackedWidget>

class AddDeviceWidget: public QFrame {
    Q_OBJECT
public:
    AddDeviceWidget(QWidget* = nullptr);
    ~AddDeviceWidget();
public slots:
    void onManualAddClicked(bool);
    void onAuthAccountClicked(bool);
private:
    QStackedWidget* m_stackedWidget;
};
