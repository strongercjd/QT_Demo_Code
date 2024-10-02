#ifndef USER_H
#define USER_H

#include <QObject>  // 引用 QObject 头文件

class User
{
public:
    void setUsername(const QString& username);
    QString getUsername() const;

    void setPassword(const QString& password);
    QString getPassword() const;

private:
    QString m_username;
    QString m_password;
};


#endif // USER_H
