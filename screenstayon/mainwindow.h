#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <Windows.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onExit();

private:
    void initTrayIcon();
    void setPreventSleep(bool enable);

    QSystemTrayIcon *trayIcon;
    EXECUTION_STATE originalState;
};

#endif // MAINWINDOW_H
