#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "CTYThread.h"
#include "ui_user_from.h"

class UserWidget : public QWidget
{
    Q_OBJECT
Q_SIGNALS:
    void signalStart();
private slots:
    void slotClickedStart();
    void slotMatchSuccess(const QString &);
    void slotMatchFail(const QString &);
    void slotLogout();
public:
    explicit UserWidget(QWidget *parent);
    UserWidget(const QString &username, QWidget *parent = NULL);
    ~UserWidget();

    void setLabelStatus(const QString &message, bool isHidden = false);
    void setUserName(const QString &username);
    QString getUserName() const;

    bool appendMessage(const QString &message);

    bool completeMatch();
private:
    void _init();
private:
    Ui_UserForm *m_UI;
    QString strUserName;

    static CTYThread *m_Thread;

    bool isContesting;
};

#endif // USERWIDGET_H
