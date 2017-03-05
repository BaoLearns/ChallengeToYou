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
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setProblems(const ListProblem &problems);
    void setMatchStatus(bool status);
protected:
    void keyPressEvent(QKeyEvent *event);
private:
    QHBoxLayout *mainLayout;
    QWidget *widgetBlank;
    LoginWidget *m_loginWidget;
    ProblemWidget *m_problemWidget;
    UserWidget *m_userWidget;
    ListProblem m_Problems;
    bool isAlreadyMatch;
};

#endif // MAINWINDOW_H
