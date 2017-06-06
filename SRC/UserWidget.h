#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include "CTYThread.h"
#include "ui_user_from.h"
#include <QDockWidget>

class UserWidget : public QWidget
{
    Q_OBJECT
Q_SIGNALS:
    void signalStart();
    void signalLogout();
private slots:
    void slotClickedStart();
    void slotMatchSuccess(const QString &);
    void slotMatchFail(const QString &);
    void slotLogout();
    void slotTimeout();
public:
    explicit UserWidget(QWidget *parent = NULL);
    UserWidget(const QString &username, QWidget *parent = NULL);
    ~UserWidget();

    void setLabelStatus(const QString &message, bool isHidden = false);
    void setUserName(const QString &username);
    QString getUserName() const;
    void setScore(int score);
    bool appendMessage(const QString &message);

    bool completeMatch();

    void reset();
private:
    void _init();
private:
    Ui_UserForm *m_UI;
    QString strUserName;

    static CTYThread *m_Thread;

    bool isContesting;

    QTimer *m_Timer;

    QDockWidget *m_UserWidget;
    QDockWidget *m_EventWidget;
    QLabel *labelUser;
    QPushButton *btnLogout;
    QLabel *labelScore;
    QPushButton *btnCommit;
    QTextEdit *textEditEvents;
};

#endif // USERWIDGET_H
