#include "SettingsButton.hpp"
#include <QAction>
#include <iostream>
#include <QDebug>

SettingsButton::SettingsButton(QWidget *parent): QToolButton(parent) {
    const QSize bulbSettingsSize(50,50);
    QPixmap pixmap(":/icons/more.png");
    QIcon ButtonIcon(pixmap);


    this->setStyleSheet("QToolButton::menu-indicator { image: none; }"
                        "QToolButton{border: none; outline: none;}");

    QAction* settingsAction = new QAction("Settings");
    QAction* removeAction = new QAction("Remove");

    this->addAction(settingsAction);
    this->addAction(removeAction);


    this->setIcon(ButtonIcon);
    this->setFixedSize(bulbSettingsSize);
    connect(this, SIGNAL(clicked(bool)),this, SLOT(onClick(bool)));
}

SettingsButton::SettingsButton()
{
    const QSize bulbSettingsSize(50,50);
    QPixmap pixmap("/home/ctuh/SmartHouseManager/icons/more.png");
    QIcon ButtonIcon(pixmap);

    QAction* settingsAction = new QAction("Settings");
    QAction* removeAction = new QAction("Remove");

    this->addAction(settingsAction);
    this->addAction(removeAction);


    this->setIcon(ButtonIcon);
    this->setFixedSize(bulbSettingsSize);
    connect(this, SIGNAL(clicked(bool)),this, SLOT(onClick(bool)));
}


void SettingsButton::onClick(bool) {
   this->showMenu();
}
