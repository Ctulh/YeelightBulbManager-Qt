#ifndef DEVICEWIDGET_H
#define DEVICEWIDGET_H

#include <QFrame>

class DeviceWidget: public QWidget {
    Q_OBJECT
public:
    explicit DeviceWidget(QWidget *parent = nullptr);
};

#endif // DEVICEWIDGET_H
