#ifndef SOCKET_H
#define SOCKET_H

#include <QThread>
#include <QTcpSocket>

class CTYServer;

class CTYSocket : public QTcpSocket
{
    Q_OBJECT

public:
    CTYSocket    ( QObject *parent = NULL );
    ~CTYSocket   ();

private slots:
    void    onReadyRead();

private:

    enum { BUFFERSIZE_MAX = 2^20 };
};

#endif // SOCKET_H
