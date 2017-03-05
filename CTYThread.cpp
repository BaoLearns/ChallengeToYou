#include "CTYThread.h"
#include "CTYDb.h"

CTYThread::CTYThread(const QString &username)
{
    strUserName = username;
}

void CTYThread::run()
{
    CTYDb::getInstance()->MatchOpponent(strUserName);
}

void CTYThread::setUserName(const QString &username)
{
    strUserName = username;
}
