
#pragma once

#include <QPushButton>

class ToggleButton: public QPushButton {
    Q_OBJECT
public:
    explicit ToggleButton(QWidget *parent = nullptr);

public slots:
    void onClick(bool);
private:
    bool m_isToggled = false;
};
