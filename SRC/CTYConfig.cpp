#include "CTYConfig.h"
#include <QApplication>
#include <QDebug>
#include <QFileInfo>

QString Config::s_appName = "ProblemAnsweringSystem";
QString Config::s_dbName = "pas.sqlite";
QString Config::s_logName = "log.txt";
Config* Config::s_Ins = NULL;

Config::Config()
{
    // do init
}

QString  Config::getRootPath()
{
    QString strRootPath = qApp->applicationDirPath() + "/";//+ "/../../" + s_appName + "/";
    return strRootPath;
}

QString Config::getLogFile()
{
    return getRootPath() + s_logName;
}

QString Config::getDBFile()
{
    return getRootPath() + s_dbName;
}

Config* Config::getInstance()
{
    if(s_Ins == NULL)
    {
        s_Ins = new Config();
    }
    return s_Ins;
}

QFont Config::getFont()
{
    QFont serifFont("黑体", 11, QFont::Bold);
    return serifFont;
}

const int Config::getMaxContestingSec()
{
    return 600000 / 1000;
}
