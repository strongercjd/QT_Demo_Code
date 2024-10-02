#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QObject>  // 引用 QObject 头文件
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    LoginWidget(QWidget* parent = nullptr);

signals:
    void signalLogin(const QString& username, const QString& password);

private slots:
    void slotLogin();

private:
    QLineEdit*  m_usernameLineEdit;
    QLineEdit*  m_passwordLineEdit;
    QPushButton *m_loginButton;
};


#endif // LOGINWIDGET_H
