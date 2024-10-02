#include <QApplication>
#include "LoginWidget.h"
#include "User.h"
#include "Controller.h"
#include <QMessageBox>   // 包含 QMessageBox 头文件

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget* widget = new QWidget;
    QVBoxLayout* layout = new QVBoxLayout;

    LoginWidget* loginWidget = new LoginWidget;
    layout->addWidget(loginWidget);
    widget->setLayout(layout);

    LoginController controller;
    QObject::connect(loginWidget, &LoginWidget::signalLogin, &controller, &LoginController::slotLogin);
    QObject::connect(&controller, &LoginController::signalLoginResult, [widget](bool result) {
        if (result) {
            QMessageBox::information(widget, "Login Success", "Login success.");
        } else {
            QMessageBox::warning(widget, "Login Failed", "Username or password is wrong.");
        }
    });
    widget->show();
    return app.exec();
}
