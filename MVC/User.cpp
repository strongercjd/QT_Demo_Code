#include "User.h"

void User::setUsername(const QString& username)
{
    m_username = username;
}

QString User::getUsername() const
{
    return m_username;
}

void User::setPassword(const QString& password)
{
    m_password = password;
}

QString User::getPassword() const
{
    return m_password;
}
