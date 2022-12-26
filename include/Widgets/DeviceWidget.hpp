#ifndef DEVICEWIDGET_H
#define DEVICEWIDGET_H

#include <QFrame>

class DeviceWidget: public QFrame {
    Q_OBJECT
public:
    explicit DeviceWidget(QWidget *parent = nullptr);
};

#endif // DEVICEWIDGET_H
