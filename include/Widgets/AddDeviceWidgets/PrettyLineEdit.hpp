
#pragma once

#include <QFrame>
#include <QLineEdit>
#include <QFocusEvent>

class PrettyLineEdit: public QLineEdit {
    Q_OBJECT
public:
    PrettyLineEdit(QWidget* parent = nullptr);
    virtual ~PrettyLineEdit() = default;
protected:
    void focusInEvent(QFocusEvent* e);
    void focusOutEvent(QFocusEvent* e);
};
