#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
}

bool Client::connectToHost(QString host, quint16 port)
{
    socket->connectToHost(host, port);
    return socket->waitForConnected();
}

bool Client::writeData(QByteArray data)
{
    if(socket->state() == QAbstractSocket::ConnectedState)
    {
        socket->write(data);
        return socket->waitForBytesWritten();
    }
    else
        return false;
}

QString Client::readData()
{
    return QString(socket->read(256));
}
