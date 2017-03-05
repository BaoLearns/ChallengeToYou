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
}

void CTYServer::Run( quint16 port )
{
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
   Log::writeLog( "Client Disconnected !") ;
    QList<CTYSocket*>::iterator iter;
    for( iter = m_sockets.begin(); iter != m_sockets.end(); iter++ )
    {
        if( -1 == (*iter)->socketDescriptor() )
        {
            m_sockets.erase( iter );
            return;
        }
    }
}
