#ifndef LOG_H
#define LOG_H
#include <QString>

#define LOG(MESSAGE)    \
    stream << __FILE__ << " " << __FUNCTION__ << " " << __LINE__ << " " << MESSAGE << "\n";

class Log
{
public:
    Log();
    static void writeLog(const QString &message);
};

#endif // LOG_H
