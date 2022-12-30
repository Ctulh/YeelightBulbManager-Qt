
#pragma once

#include <functional>

#include <QToolButton>


class AddDeviceButton: public QToolButton {
    Q_OBJECT
public:
    AddDeviceButton(QWidget* = nullptr);

public slots:
    void onClick(bool);
    //void onTriggered(QAction*);
};
