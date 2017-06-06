#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QQueue>

class CTYSocket;

class CTYServer : public QTcpServer
{
    Q_OBJECT

public:
    explicit CTYServer(QObject *parent = NULL );
    ~CTYServer ();

    void    Run ( quint16 port );

protected:
    void    incomingConnection  ( int handle );

private slots:
    void    clientDisconnected  ();

private:
    enum { BUFFERSIZE_MAX = 2^20 };

    quint16             m_port;
    QList<CTYSocket*>  m_sockets;

};

#endif // SERVER_H
