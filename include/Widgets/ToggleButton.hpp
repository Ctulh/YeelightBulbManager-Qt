
#pragma once

#include <QPushButton>

class ToggleButton: public QPushButton {
    Q_OBJECT
public:
    explicit ToggleButton(QWidget *parent = nullptr);
};
