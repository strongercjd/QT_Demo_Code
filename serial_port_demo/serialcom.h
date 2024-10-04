#ifndef SERIALCOM_H
#define SERIALCOM_H

#include <QWidget>
#include <QObject>
/*
 *<QSerialPort>:提供串口相关的服务
 *<QSerialPortInfo>:提供串口设备查询的服务
 */
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <functional>

#include <QTimer>
#include <QTime>
#include <QQueue>

namespace Ui {
class SerialCom;
}

class SerialCom : public QWidget
{
    Q_OBJECT

public:
    explicit SerialCom(QWidget *parent = nullptr);
    ~SerialCom();

    bool isopen_status;
    void writedata(QByteArray data);

signals:
    void readdata(const QByteArray& data);

private slots:
    void receivedata();
    void SendData_Regularly();

    void on_btn_scancom_clicked();

    void on_btn_togglecom_clicked();

private:
    Ui::SerialCom *ui;

    QSerialPort  *serialport;
    QTimer       *send_data_timer;
    QQueue<QByteArray> *send_data_queue;

    void Open(void);
    void Close(void);

};

#endif // SERIALCOM_H
