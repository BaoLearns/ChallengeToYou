#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "CTYThread.h"

class UserWidget : public QWidget
{
    Q_OBJECT
Q_SIGNALS:
    void signalStart();
private slots:
    void slotClickedStart();
    void slotMatchSuccess(const QString &);
    void slotMatchFail(const QString &);
public:
    explicit UserWidget(QWidget *parent);
    UserWidget(const QString &username, QWidget *parent = NULL);

    void setLabelStatus(const QString &message, bool isHidden = false);
    void setUserName(const QString &username);
    QString getUserName() const;
private:
    void _init();
private:
    QPushButton *btnStart;
    QString strUserName;
    QLabel *labelStatus;

    static CTYThread *m_Thread;
};

#endif // USERWIDGET_H
