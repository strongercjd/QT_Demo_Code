#include "LoginWidget.h"

LoginWidget::LoginWidget(QWidget* parent)
    : QWidget(parent)
{
    m_usernameLineEdit = new QLineEdit;
    m_passwordLineEdit = new QLineEdit;
    m_passwordLineEdit->setEchoMode(QLineEdit::Password);

    m_loginButton = new QPushButton("Login");
    connect(m_loginButton, &QPushButton::clicked, this, &LoginWidget::slotLogin);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(m_usernameLineEdit);
    layout->addWidget(m_passwordLineEdit);
    layout->addWidget(m_loginButton);

    setLayout(layout);
}

void LoginWidget::slotLogin()
{
    QString username = m_usernameLineEdit->text();
    QString password = m_passwordLineEdit->text();

    emit signalLogin(username, password);
}

