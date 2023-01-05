#pragma once

#include <QToolButton>

class SettingsButton: public QToolButton
{
    Q_OBJECT
public:
    SettingsButton();
    explicit SettingsButton(QWidget *parent = nullptr);
public slots:
    void onClick(bool);
};

