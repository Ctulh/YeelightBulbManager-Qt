#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QMap>
#include <string>

#include "Subscriber.hpp"
#include "Widgets/FlowLayout.hpp"
#include "AddDeviceWidgets/AddDeviceWidget.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public Subscriber
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_MainWindow_iconSizeChanged(const QSize &iconSize);

public:
    void update(std::string const& message) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;

private:
    void addDevice();
    void deleteLastDevice();

private:
    AddDeviceWidget* m_addDeviceWidget;
    FlowLayout* m_layout;
    QMap<std::string, QWidget*> m_widgets;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
