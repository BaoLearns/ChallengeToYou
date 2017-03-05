#include "Client.h"
#include <QHostAddress>
#include <QDebug>
#include <QApplication>
#include "Problem.h"
#include "Log.h"
#include "CTYDb.h"


MainWindow *m_Window;

CTYClient::CTYClient( QObject *parent /* = NULL */ )
    : QTcpSocket( parent )
    //, m_Window(new MainWindow())
{
    const char host[10] = {"127.0.0.1"};
    const int port = 33333;
    ConnectToServer(host, port);
    waitForConnected( -1 );

    connect( this, SIGNAL(readyRead()), this, SLOT(OnReadyRead()) );
    connect( this, SIGNAL(connected()), this, SLOT(OnConnected()) );
}

CTYClient::~CTYClient()
{
    m_CTYDb.updateStatus(m_strUserName, "offline");
    m_CTYDb.disconnect();
}

void CTYClient::Run()
{
    m_Window = new MainWindow;
    connect(m_Window, SIGNAL(signalRequestProblems()), this, SLOT(slotDisposeProblems()));
    //connect(m_Window, SIGNAL(close()), this, SLOT(slotCloseWindow()));
    connect(m_Window, SIGNAL(signalRequestMatchContest(const QString&)),
            this, SLOT(slotDisposeMatchContest(const QString &)));
    m_Window->showMaximized();

}

void CTYClient::ConnectToServer( const char *ip, quint16 port )
{
    QString strip( ip );
    QHostAddress addr;
    addr.setAddress( strip );
    connectToHost( addr, port );
}

void CTYClient::Close()
{
    disconnectFromHost();
    close();
}

bool CTYClient::WriteData( const char *data, qint64 len )
{
    if( NULL == data || len <= 0 )
    {
        return false;
    }
    qint64 ret = writeData( data, len );
    if( 0 >= ret )
    {
        return false;
    }
    waitForBytesWritten( -1 );
    qDebug()  << "send    data: %s\n" <<  data ;

    waitForReadyRead( -1 );
    return true;
}

// 解析问题，从QString中解析到ListProblem
ListProblem CTYClient::ParseProblems(const QString &data)
{
    Log::writeLog("Start ParseProblem");
    QStringList list = data.split("#");
    if(list.size() % 7 != 0)
    {
        Log::writeLog("Parse Problem Failed. Stop!");
        qApp->exit();
    }

    ListProblem problems;
    for(int i = 0; i < list.size(); i += 7)
    {
        Problem problem(list.at(i).toInt(),
                        list.at(i + 1),
                        list.at(i + 2),
                        list.at(i + 3),
                        list.at(i + 4),
                        list.at(i + 5),
                        list.at(i + 6).toInt());
        problems.append(problem);
    }
    return problems;
}

// 解析数据
void CTYClient::ParseData( const char *data, qint64 len )
{
    qDebug() << "receive data: %s\n" << data ;
    const QString strGoal = "Already Match";
    QString strData(data);

    if(strData.size() > strGoal.size() && strData.left(strGoal.size()) == strGoal)
    {
        m_Problmes = ParseProblems(strData.right(strData.size() - strGoal.size()));
    }
}

void CTYClient::OnReadyRead()
{
    char data[BUFFERSIZE_MAX] = { 0 };
    qint64 len = readData( data, BUFFERSIZE_MAX );
    if( len <= 0 )
        return;
    else
        ParseData( data, len );
}

void CTYClient::OnConnected()
{
    qDebug() <<  "connected: %d !\n"<< socketDescriptor() ;
}


bool CTYClient::MatchContest()
{
    char data[BUFFERSIZE_MAX] = {0};
    strcpy(data, "Request Match Contest");
    int len = strlen(data);
    qint64 ret = writeData(data, len);
    if(ret < 0)
    {
        return false;
    }
    waitForBytesWritten(-1);
    qDebug()  << "send    data: %s\n" <<  data ;
    waitForReadyRead(-1);
    return true;
}

ListProblem CTYClient::getProblmes()
{
    if(m_Problmes.size() < 10)
    {
        Log::writeLog("No 10 problmes. Stop!");
        Log::writeLog(QString::number(m_Problmes.size()));
        //qApp->exit();
        m_Problmes = CTYDb::getInstance()->getNumProblem();
    }
    return m_Problmes;
}

void CTYClient::setUserName(const QString &username)
{
    m_strUserName = username;
}

QString CTYClient::getUserName() const
{
    return m_strUserName;
}

void CTYClient::slotDisposeProblems()
{
    m_Window->setProblems(m_CTYDb.getNumProblem());
}

void CTYClient::slotCloseWindow()
{
    m_CTYDb.updateStatus(m_strUserName, "offline");
    m_CTYDb.disconnect();
}

void CTYClient::slotDisposeMatchContest(const QString &username)
{
    if(m_CTYDb.MatchOpponent(username))
    {
        Log::writeLog("Already Match.");
        m_Window->setMatchStatus(true);
    }
    else
    {
        Log::writeLog("Match Failed");
        m_Window->setMatchStatus(false);
    }
}
