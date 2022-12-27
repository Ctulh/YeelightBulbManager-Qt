#include "ToggleButton.hpp"

ToggleButton::ToggleButton(QWidget *parent): QPushButton(parent) {
    QPixmap pixmap(":/icons/powerOff.png");
    const QSize bulbSize(25,25);
    QIcon buttonIcon(pixmap);


    this->setStyleSheet("border: none; outline: none;");
    this->setIcon(buttonIcon);
    this->setIconSize(QSize(25, 25));  
    this->setFixedSize(bulbSize);

    //QRect rect(this->x(), this->y(), this->x() + this->width(),this->y() + this->height());
    //QRegion region(rect, QRegion::Ellipse);
    //this->setMask(region);

    connect(this, SIGNAL(clicked(bool)),this, SLOT(onClick(bool)));
}


void ToggleButton::onClick(bool) {
    QPixmap pixmap;
    if(m_isToggled)
       pixmap = QPixmap(":/icons/powerOff.png");
    else
       pixmap = QPixmap(":/icons/powerOn.png");

    m_isToggled = !m_isToggled;
    QIcon buttonIcon(pixmap);

    this->setIcon(buttonIcon);
}
