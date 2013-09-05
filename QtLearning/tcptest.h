#ifndef TCPTEST_H
#define TCPTEST_H
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QTextStream>
#include <QString>

class MyServer: public QObject{
    Q_OBJECT
private:
    QTcpServer* _server;

public:
    MyServer(){
        _server = new QTcpServer;
        connect(_server, SIGNAL(newConnection()), SLOT(connection()));
    }

protected slots:
    void connection(){
        qDebug()<<"connection ";
        QTcpSocket* sock = _server->nextPendingConnection();



        QTextStream ts(sock);

        QString s;
        ts>>s;
        qDebug()<<"s= "<<s;

        ts<<"qweqweqwe";
        ts.flush();

        qDebug()<<"sended ";
    }

public slots:
    void serverRun(){
        _server->listen(QHostAddress::Any, 2323);
    }


};

#endif // TCPTEST_H
