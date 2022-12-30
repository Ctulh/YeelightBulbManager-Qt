#include "AuthWidget.hpp"
#include <QPushButton>
#include "FileReader.hpp"
#include <QGraphicsDropShadowEffect>

AuthWidget::AuthWidget(QWidget* parent): QFrame(parent) {
    this->setStyleSheet(FileReader::getFileData(":/styles/AuthWidget.css").c_str());

    this->setMinimumSize(400,400);

    auto button = new QPushButton("Scan", this);
    button->move(100,100);
    button->setStyleSheet("background: rgba(250,100,252,255); ");

    auto m_shadowEffect = new QGraphicsDropShadowEffect(this);
    m_shadowEffect->setColor(QColor(0, 0, 0, 255 * 0.3));
    m_shadowEffect->setXOffset(3);
    m_shadowEffect->setYOffset(3);
    m_shadowEffect->setBlurRadius(10);
    setGraphicsEffect(m_shadowEffect);




}
