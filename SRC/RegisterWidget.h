#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QTextBrowser>
#include <QLabel>
class RegisterWidget : public QDialog
{
    Q_OBJECT
public:
    explicit RegisterWidget(QWidget *parent = NULL);
private slots:
    void slotCommit();
private:
    QPushButton *btnCommit;
    QLineEdit *editUser;
    QLineEdit *editPassword;
    QLineEdit *editConfirm;
};

#endif // REGISTER_H
