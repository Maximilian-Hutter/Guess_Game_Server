#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myserver.h"
#include "client.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ServerMode_toggled(bool checked);

    void on_ClientMode_toggled(bool checked);

    void on_IPinput_returnPressed();

    void on_Portin_returnPressed();

    void on_NumberIn_valueChanged(int arg1);

    void on_GuessButton_clicked();

    void on_NumberIn_editingFinished();

    void on_IPinput_editingFinished();

    void on_Portin_editingFinished();

    void on_ClientMode_clicked();

    void on_ServerMode_clicked();

private:
    Ui::MainWindow *ui;
    QString m_ip;
    quint16 m_port;
    int m_number;
    Client *client;
    MyServer *server;

};
#endif // MAINWINDOW_H
