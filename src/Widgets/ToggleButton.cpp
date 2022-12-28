#include "ToggleButton.hpp"
#include "FileReader.hpp"

ToggleButton::ToggleButton(QWidget *parent): QPushButton(parent) {
    this->setStyleSheet(FileReader::getFileData(":/styles/ToggleButton.css").c_str());

    QPixmap pixmap(":/icons/powerOff.png");
    const QSize bulbSize(25,25);
    QIcon buttonIcon(pixmap);

    this->setIcon(buttonIcon);
    this->setIconSize(QSize(25, 25));
    this->setFixedSize(bulbSize);

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
