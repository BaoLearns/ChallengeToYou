#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSqlDatabase>
#include <QString>

class LoginWidget : public QWidget
{
    Q_OBJECT

Q_SIGNALS:
    void signalAuthenticationSucceed();
    void signalAuthenticationFailed();
public:
    explicit LoginWidget(QWidget *parent = 0);
    ~LoginWidget();

    QString getUserName() const;
protected:
    void keyPressEvent(QKeyEvent *event);
public slots:
    void slotLogin();
    void slotCancle();

private:
    QLabel *labelUserName;
    QLabel *labelPassword;
    QLineEdit *lineEditUserName;
    QLineEdit *lineEditPassword;
    QPushButton *buttonLogin;
    QPushButton *buttonCancle;
};

#endif // LOGIN_H
