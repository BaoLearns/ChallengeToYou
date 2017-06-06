#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextCodec>
#include <QtGui>
#include <QWidget>
#include <QKeyEvent>

#include "Log.h"
#include "CTYDb.h"
#include "LoginWidget.h"
#include "ProblemWidget.h"
#include "UserWidget.h"
#include "Client.h"
#include "Problem.h"
#include <QStackedWidget>

class MainWindow : public QWidget
{
    Q_OBJECT
Q_SIGNALS:
    void signalRequestProblems();
    void signalRequestMatchContest(const QString &);
private slots:
    void slotLoginSucceed();
    void slotLoginFailed();
    void slotStartContest();
    void slotCommitProblems(int score);
    void slotContestDone();
    void slotLogout();
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setProblems(const ListProblemItem &problems);
    void setMatchStatus(bool status);
protected:
    virtual void keyPressEvent(QKeyEvent *event);
    void closeEvent(QCloseEvent *event);

private:
    void _reset();
private:
    QHBoxLayout *mainLayout;
    QWidget *widgetBlank;
    LoginWidget *m_loginWidget;
    ProblemWidget *m_problemWidget;
    UserWidget *m_userWidget;
    QWidget *m_blankWidget;
    ListProblemItem m_Problems;
    bool isAlreadyMatch;

    QStackedWidget *m_leftStkWid;
    QStackedWidget *m_rightStkWid;
};

#endif // MAINWINDOW_H
