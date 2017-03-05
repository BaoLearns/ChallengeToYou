#include "Log.h"
#include "CTYConfig.h"
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QDateTime>

Log::Log()
{

}

void Log::writeLog(const QString &message)
{
    QFile file(Config::getInstance()->getLogFile());
    if(!file.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "No Such Log File " + Config::s_logName;
    }

    QTextStream stream(&file);
    stream << "[" << QDateTime::currentDateTime().toString("yyyy-MM-dd hh::mm::ss::zzz") << "]\t" ;
    stream << message << "\n";
    qDebug() << "[" << QDateTime::currentDateTime().toString("yyyy-MM-dd hh::mm::ss::zzz") << "]\t" << message;
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
