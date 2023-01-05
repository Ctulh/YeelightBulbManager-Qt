#pragma once

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QStackedWidget>

#include "ManualAddWidget.hpp"

class AddDeviceWidget: public QFrame {
    Q_OBJECT
public:
    AddDeviceWidget(QWidget* = nullptr);
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
