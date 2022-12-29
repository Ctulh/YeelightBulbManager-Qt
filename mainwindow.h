#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include "Widgets/FlowLayout.hpp"
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

    void on_MainWindow_iconSizeChanged(const QSize &iconSize);
    void onClick(bool);
    void onTriggered(QAction*);

public:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
private:
    FlowLayout* m_layout;
    QMap <QString, QWidget*> m_widgets;
    QToolButton* m_addDeviceButton;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
