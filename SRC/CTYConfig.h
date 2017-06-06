#ifndef CTYCONFIG_H
#define CTYCONFIG_H

#include <QObject>
#include <QString>
#include <QApplication>
#include <QDebug>
#include <QFont>

enum RequestType
{
    RequestValidUser,
    RequestMatchTest,
    RequestGetProblems,
    RequestCommit
};

class Config
{
public:
    static QString s_appName;
    static QString s_dbName;
    static QString s_logName;

    static Config* getInstance();
    static QFont getFont();
    static const int getMaxContestingSec();
public:
    QString getRootPath();
    QString getLogFile();
    QString getDBFile();
protected:
    Config();
private:
    static Config *s_Ins;
};
#endif // CTYCONFIG_H
