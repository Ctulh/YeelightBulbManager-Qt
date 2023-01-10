#include "ToggleButton.hpp"
#include "FileReader.hpp"
#include "Presenter/Presenter.hpp"

ToggleButton::ToggleButton(QWidget *parent): QPushButton(parent) {
    this->setStyleSheet(FileReader::getFileData(":/styles/ToggleButton.css").c_str());

    QPixmap pixmap(":/icons/powerOff.png");
    const QSize bulbSize(35,35);
    QIcon buttonIcon(pixmap);

    this->setIcon(buttonIcon);
    this->setIconSize(QSize(35, 35));
    this->setFixedSize(bulbSize);

    connect(this, SIGNAL(clicked(bool)),this, SLOT(onClick(bool)));
}

bool ToggleButton::isToggled() const {
    return m_isToggled;
}

void ToggleButton::onClick(bool) {
    QPixmap pixmap;
    if(m_isToggled) {
       pixmap = QPixmap(":/icons/powerOff.png");
    }
    else {
       pixmap = QPixmap(":/icons/powerOn.png");
    }

    m_isToggled = !m_isToggled;
    QIcon buttonIcon(pixmap);

    this->setIcon(buttonIcon);
}
