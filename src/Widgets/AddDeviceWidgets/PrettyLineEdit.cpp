
#include "AddDeviceWidgets/PrettyLineEdit.hpp"

#include "FileReader/FileReader.hpp"
#include <iostream>

PrettyLineEdit::PrettyLineEdit(QWidget *parent): QLineEdit(parent) {
    this->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/PrettyLineEdit.css").c_str());
}

void PrettyLineEdit::focusInEvent(QFocusEvent *e) {
    if(e->reason() == Qt::MouseFocusReason) {
        this->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/PrettyLineEdit_Focussed.css").c_str());
    }
    QLineEdit::focusInEvent(e);
}

void PrettyLineEdit::focusOutEvent(QFocusEvent *e) {
    if(e->reason() == Qt::MouseFocusReason) {
        this->setStyleSheet(FileReader::getFileData(":/styles/AddDeviceStyles/PrettyLineEdit.css").c_str());
    }
    QLineEdit::focusOutEvent(e);
}
