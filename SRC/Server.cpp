#include "Server.h"
#include "Socket.h"
#include "Log.h"
#include "CTYDb.h"

#include <QHostAddress>
#include <QApplication>

CTYServer::CTYServer( QObject *parent /* = NULL */ )
    : QTcpServer( parent )
{
    m_sockets.empty();
}

CTYServer::~CTYServer()
{
    qDeleteAll( m_sockets );
    m_sockets.clear();
    Log::writeLog("Close Server.Bye!");
}

void CTYServer::Run( quint16 port )
{
    Log::writeLog(QString("Running in %0:%1").arg("127.0.0.1").arg(port));

    if( !this->listen(QHostAddress::LocalHost, port) )
    {
        Log::writeLog("CTYServer Listen Failed !Stop.") ;
        qApp->exit();
    }
}

void CTYServer::incomingConnection( int handle )
{
    Log::writeLog( QString("IncomingConnection(): %0!").arg(handle ));
    CTYSocket *socket = new CTYSocket( this );
    socket->setSocketDescriptor( handle );
    connect( socket, SIGNAL(disconnected()), this, SLOT(clientDisconnected()) );
    m_sockets.append( socket );
}

void CTYServer::clientDisconnected()
{
    QList<CTYSocket*>::iterator iter;
    for( iter = m_sockets.begin(); iter != m_sockets.end(); iter++ )
    {
        if( -1 == (*iter)->socketDescriptor() )
        {
            Log::writeLog( "Client Disconnected !") ;
            m_sockets.erase(iter);
            break;
        }
    }
    return;
}
