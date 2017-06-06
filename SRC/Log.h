#ifndef LOG_H
#define LOG_H
#include <QString>
#include <QFile>
#define LOG(MESSAGE)    \
    stream << __FILE__ << " " << __FUNCTION__ << " " << __LINE__ << " " << MESSAGE << "\n";

class Log
{
public:
    Log();

    static bool beginLog();
    static bool endLog();
    static void writeLog(const QString &message);
    QFile m_LogFile;
};

#endif // LOG_H
