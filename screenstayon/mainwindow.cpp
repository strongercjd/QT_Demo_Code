#include "mainwindow.h"
#include <QApplication>
#include <QStyle>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 保存原始电源状态设置
    originalState = SetThreadExecutionState(ES_CONTINUOUS);

    // 初始化托盘图标
    initTrayIcon();

    // 启用防休眠
    setPreventSleep(true);

    // 隐藏主窗口
    setWindowFlag(Qt::Tool);
    resize(0, 0);
}

MainWindow::~MainWindow()
{
    // 恢复原始电源设置
    SetThreadExecutionState(originalState | ES_CONTINUOUS);
}

void MainWindow::initTrayIcon()
{
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QApplication::style()->standardIcon(QStyle::SP_ComputerIcon));
    trayIcon->setToolTip("系统防休眠工具\n正在阻止系统休眠和锁屏");

    QMenu *menu = new QMenu();
    QAction *exitAction = new QAction("退出", this);
    connect(exitAction, &QAction::triggered, this, &MainWindow::onExit);
    menu->addAction(exitAction);

    trayIcon->setContextMenu(menu);
    trayIcon->show();
}

void MainWindow::setPreventSleep(bool enable)
{
    if(enable) {
        // 组合标志说明：
        // ES_SYSTEM_REQUIRED - 阻止系统进入空闲休眠
        // ES_DISPLAY_REQUIRED - 阻止屏幕关闭
        // ES_CONTINUOUS - 持续生效直到显式关闭
        SetThreadExecutionState(ES_CONTINUOUS | ES_SYSTEM_REQUIRED | ES_DISPLAY_REQUIRED);
    } else {
        SetThreadExecutionState(ES_CONTINUOUS);
    }
}

void MainWindow::onExit()
{
    // 退出前恢复电源设置
    SetThreadExecutionState(originalState | ES_CONTINUOUS);
    qApp->quit();
}
