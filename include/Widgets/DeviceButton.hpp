
#pragma once

#include <QPushButton>

namespace {
    constexpr uint32_t DEFAULT_WIDTH = 200;
    constexpr uint32_t DEFAULT_HEIGHT = 100;
}

class DeviceButton: public QPushButton {
    Q_OBJECT
public:
     explicit DeviceButton(QWidget *parent = nullptr, int width = ::DEFAULT_WIDTH, int height = ::DEFAULT_HEIGHT);
public slots:
    void onClick(bool);
};
