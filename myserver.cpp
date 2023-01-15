#include "myserver.h"

MyServer::MyServer(QObject *parent, quint16 port)
    : QObject{parent}
{
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()),this, SLOT(newConnection()));
    m_randnum = QRandomGenerator::global()->bounded(100);
    qDebug() << "random num ist";
    qDebug() << m_randnum;

    if(!server->listen(QHostAddress::Any, port))
    {
        qDebug() << "Server could not start";
    }
    else
    {
        qDebug() << "Server started!";
    }
}

qint32 ArrayToInt(QByteArray source)
{
    qint32 temp;
    QDataStream data(&source, QIODevice::ReadWrite);
    data >> temp;
    return temp;
}

void MyServer::newConnection()
{
    QTcpSocket *socket = server->nextPendingConnection();
    connect(socket, SIGNAL(readyRead()), SLOT(readyRead()));

}

void MyServer::readyRead()
{
    QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
    if (!socket->waitForConnected(1000))
    {
        qDebug("Not Connected!");
        m_randnum = QRandomGenerator::global()->bounded(100);
        qDebug() << "random num ist";
        qDebug() << m_randnum;
    }

    QByteArray ByteArray = socket->read(4);
    int number = ArrayToInt(ByteArray);

    QString response = "Not a Number";
    if(number == m_randnum)
    {
        response = "Gewonnen!";
    }
    if(number < m_randnum)
    {
        response = "Deine Nummer ist zu klein";
    }
    if(number > m_randnum)
    {
        response = "Deine Nummer ist zu groß";
    }

    socket->write(response.toUtf8());

}
