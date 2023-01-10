#pragma once

#include <QPushButton>
#include <functional>

using toggleCallback = std::function<void(void)>;

class ToggleButton: public QPushButton {
    Q_OBJECT
public:
    explicit ToggleButton(QWidget *parent = nullptr);
    bool isToggled() const;

public slots:
    void onClick(bool);
private:
    bool m_isToggled = false;
};
