#include "Socket.h"
#include "Server.h"
#include <QTcpSocket>
#include <QDebug>
#include "CTYDb.h"
#include "Problem.h"
#include "Log.h"
#include <QTextStream>

CTYSocket::CTYSocket( QObject *parent /* = NULL */ )
    : QTcpSocket( parent )
{
    connect( this, SIGNAL(readyRead()), this, SLOT(onReadyRead()) );
}

CTYSocket::~CTYSocket()
{
    close();
}

void CTYSocket::onReadyRead()
{
    char data[BUFFERSIZE_MAX] = { 0 };
    int len = readData(data, BUFFERSIZE_MAX);
    if( len <= 0 )
    {
        Log::writeLog( "CTYSocket::OnReadyRead() Read Data Failed !" );
        return;
    }

    qDebug() <<  "receive data: %s\n" << data ;

//    QString strData(data);
//    if(strData == "Request Match Contest")
//    {
//            ListProblem problmes = DB::getInstance()->getNumProblem();
//            char dataWrite[BUFFERSIZE_MAX];
//            QString strDataWrite;
//            QTextStream stream(&strDataWrite);
//            for(int i = 0; i < problmes.size(); ++i)
//            {
//                stream << problmes.at(i).index << "#"
//                       << problmes.at(i).strDescription << "#"
//                       << problmes.at(i).strOptionA << "#"
//                       << problmes.at(i).strOptionB << "#"
//                       << problmes.at(i).strOptionC << "#"
//                       << problmes.at(i).strOptionD << "#"
//                       << problmes.at(i).indexAnswer<< (i == problmes.size() - 1? "":"#");
//            }
//            strcpy(dataWrite, static_cast<const char*>(strDataWrite.toLocal8Bit()));
//            if(writeData(data, strlen(dataWrite)) < 0)
//            {
//               Log::writeLog("CTYSocket::OnReadyRead() Write Data Failed !" );
//            }
//            else
//            {
//                Log::writeLog(QString("send    data: %0").arg(data ));
//            }
//    }
}
