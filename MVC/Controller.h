#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>  // 引用 QObject 头文件

class LoginController : public QObject
{
    Q_OBJECT

public:
    LoginController(QObject* parent = nullptr);

public slots:
    void slotLogin(const QString& username, const QString& password);

signals:
    void signalLoginResult(bool result);

private:
    bool checkUser(const QString& username, const QString& password); // 模拟验证用户信息是否正确的函数
};

#endif // CONTROLLER_H
