#include "mainwindow.h"
#include "./ui_mainwindow.h"

QByteArray IntToArray(qint32 source)
{
    QByteArray temp;
    QDataStream data(&temp, QIODevice::ReadWrite);
    data << source;
    return temp;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ServerMode_toggled(bool checked)
{

}


void MainWindow::on_ClientMode_toggled(bool checked)
{

}


void MainWindow::on_IPinput_returnPressed()
{

}


void MainWindow::on_Portin_returnPressed()
{

}



void MainWindow::on_GuessButton_clicked()
{
    QByteArray number = IntToArray(m_number);
    client->writeData(number);
    QString response = client->readData();
    ui->Feedback->append(response);

    qDebug() << response;
}


void MainWindow::on_NumberIn_editingFinished()
{
    QString numberstring = ui->NumberIn->text();
    m_number = numberstring.toInt();
}



void MainWindow::on_NumberIn_valueChanged(int arg1)
{

}


void MainWindow::on_IPinput_editingFinished()
{
    m_ip = ui->IPinput->text();
}


void MainWindow::on_Portin_editingFinished()
{
    QString portstring = ui->Portin->text();
    m_port = portstring.toInt();
}


void MainWindow::on_ClientMode_clicked()
{
    client = new Client(this);
    client->connectToHost(m_ip,m_port);
}


void MainWindow::on_ServerMode_clicked()
{
    server = new MyServer(this, m_port);
}

