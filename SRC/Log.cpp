#include "Log.h"
#include "CTYConfig.h"
#include <QFileInfo>
#include <QTextStream>
#include <QDateTime>

Log::Log()
{

}

bool Log::beginLog()
{
    writeLog("###################BEGIN####################################");
    writeLog(QString("###################%0####################")
             .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh::mm::ss.zzz")));
    QFile m_LogFile(Config::getInstance()->getLogFile());
    if(!m_LogFile.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "No Such Log File " + Config::s_logName;
        return false;
    }
    return true;
}

bool Log::endLog()
{
    writeLog("###################END####################");
    return true;
}

void Log::writeLog(const QString &message)
{
    QFile file(Config::getInstance()->getLogFile());
    file.open(QIODevice::Append | QIODevice::Text);
    QTextStream stream(&file);
    stream << "[" << QDateTime::currentDateTime().toString("yyyy-MM-dd hh::mm::ss.zzz") << "]\t" ;
    stream << message << "\n";
    qDebug() << "[" << QDateTime::currentDateTime().toString("yyyy-MM-dd hh::mm::ss.zzz") << "]\t" << message;
}

//void Log::writeLog(const std::string &message)
//{

//    QFile file(Config::getInstance()->getLogFile());
//    if(!file.open(QIODevice::Append | QIODevice::Text))
//    {
//        qDebug() << "No Such File " + Config::s_logName;
//        qDebug() << "Stop!";
//    }
//    QTextStream stream(&file);
//    stream << "[" <<QDateTime::currentDateTime().toString() << "]" << "\n";
//    stream << QString::fromStdString(message) << "\n";
//}
