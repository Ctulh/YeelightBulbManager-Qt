
#pragma once

#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>
#include <QString>

#include "ManualAddWidget.hpp"

class AddDeviceWidget: public QFrame {
    Q_OBJECT
public:
    AddDeviceWidget(QWidget* = nullptr);
    ~AddDeviceWidget();
public slots:
    void onManualAddClicked(bool);
    void onAuthAccountClicked(bool);
    void onDoneButtonClicked(bool);
private:
    QPushButton* m_manualAddBtn;
    QPushButton* m_authAccountBtn;
    QStackedWidget* m_stackedWidget;
    ManualAddWidget* m_manualAddWidget;
};
