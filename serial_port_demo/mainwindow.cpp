#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->widget_serial_port, &SerialCom::readdata, this, &MainWindow::serial_receive_data);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*串口接收数据*/
void MainWindow:: serial_receive_data(QByteArray data)
{
    ui->textBrowser->append(QString::fromUtf8(data));
}

void MainWindow::on_pushButton_clicked()
{
    ui->widget_serial_port->writedata(ui->lineEdit->text().toLatin1());
}
