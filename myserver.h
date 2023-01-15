#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QRandomGenerator>

class MyServer : public QObject
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = nullptr,quint16 port = 6666);

signals:

public slots:
    void newConnection();
    void readyRead();

private:
    QTcpServer *server;
    int m_randnum;

};

#endif // MYSERVER_H
