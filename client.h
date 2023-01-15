#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QRandomGenerator>

class Client : public QObject
{
public:
    explicit Client(QObject *parent = 0);

public slots:
    bool connectToHost(QString host, quint16 port = 6666);
    bool writeData(QByteArray data);
    QString readData();

private:
    QTcpSocket *socket;
};

#endif // CLIENT_H
