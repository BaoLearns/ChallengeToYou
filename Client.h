#ifndef CLIENT_H
#define CLIENT_H

#include "mainwindow.h"
#include "Problem.h"
#include "CTYDb.h"
#include <QTcpSocket>
#include <QWidget>

class CTYClient : public QTcpSocket
{
    Q_OBJECT

public:
    CTYClient  ( QObject *parent = NULL );
    ~CTYClient ();

    void Run();
    void ConnectToServer(const char *ip, quint16 port );
    void Close();
    bool WriteData(const char *data, qint64 len);

    bool MatchContest();
    ListProblem getProblmes();
    void setUserName(const QString &username);
    QString getUserName() const;

protected:
    void ParseData( const char *data, qint64 len );
    ListProblem ParseProblems(const QString &data);
private slots:
    void OnConnected ();
    void OnReadyRead ();
    void slotDisposeProblems();
    void slotCloseWindow();
    void slotDisposeMatchContest(const QString &);
private:
    enum { BUFFERSIZE_MAX = 2^20 };

    ListProblem m_Problmes;
    CTYDb m_CTYDb;
    QString m_strUserName;
};

#endif // CLIENT_H
