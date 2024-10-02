#include "Controller.h"
#include "User.h"


LoginController::LoginController(QObject* parent)
    : QObject(parent)
{
}

void LoginController::slotLogin(const QString& username, const QString& password)
{
    bool result = checkUser(username, password);
    emit signalLoginResult(result);
}

bool LoginController::checkUser(const QString& username, const QString& password)
{
    User user;
    user.setUsername("admin");
    user.setPassword("123456");

    if (user.getUsername() == username && user.getPassword() == password) {
        return true;
    } else {
        return false;
    }
}
