#ifndef CTYTHREAD_H
#define CTYTHREAD_H

#include <QThread>
#include <QString>

class CTYThread : public QThread
{
    Q_OBJECT
public:
    CTYThread(const QString &username = "");

    void setUserName(const QString &username);
protected:
   void run();

private:
    QString strUserName;
};

#endif // CTYTHREAD_H
