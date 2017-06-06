#include "RegisterWidget.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include "CTYDb.h"
#include <QMessagebox>

RegisterWidget::RegisterWidget(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(QStringLiteral("注册新用户"));
    setFixedSize(400, 350);
    //setWindowIcon(QIcon(QString::fromLocal8Bit(":/resources/image/icon.ico")));

    QLabel *labelUser = new QLabel(QStringLiteral("用户名:"));
    editUser = new QLineEdit();
    QLabel *labelPassword = new QLabel(QStringLiteral("密码:"));
    editPassword = new QLineEdit();
    editPassword->setEchoMode(QLineEdit::Password);
    QLabel *LabelConfirm = new QLabel(QStringLiteral("确认密码:"));
    editConfirm = new QLineEdit();
    editConfirm->setEchoMode(QLineEdit::Password);
    btnCommit = new QPushButton(QStringLiteral("提交"));
    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->setAlignment(Qt::AlignTop);
    gridLayout->setMargin(20);
    gridLayout->setHorizontalSpacing(20);
    gridLayout->setSpacing(60);

    gridLayout->addWidget(labelUser, 0, 0, 1, 1);
    gridLayout->addWidget(editUser, 0, 1, 1, 1);
    gridLayout->addWidget(labelPassword, 1, 0, 1, 1);
    gridLayout->addWidget(editPassword, 1, 1, 1, 1);
    gridLayout->addWidget(LabelConfirm, 2, 0, 1, 1);
    gridLayout->addWidget(editConfirm, 2, 1, 1, 1);
    gridLayout->addWidget(btnCommit, 3, 1, 1, 1, Qt::AlignBottom | Qt::AlignRight);
    QGroupBox *box = new QGroupBox();
    box->setLayout(gridLayout);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(box);

    connect(btnCommit, SIGNAL(clicked()), this, SLOT(slotCommit()));

    QFont serifFont("黑体", 11, QFont::Bold);
    labelUser->setFont(serifFont);
    editUser->setFont(serifFont);
    labelPassword->setFont(serifFont);
    editPassword->setFont(serifFont);
    LabelConfirm->setFont(serifFont);
    editConfirm->setFont(serifFont);
    btnCommit->setFont(serifFont);
}

void RegisterWidget::slotCommit()
{
    if(editUser->text().isEmpty()
       || editPassword->text().isEmpty()
       || editConfirm->text().isEmpty())
    {
        QMessageBox box(this);
        box.setWindowTitle(QStringLiteral("错误："));
        box.setText(QStringLiteral("有未填写信息，请填写完整.\n请重新输入！"));
        box.setIcon(QMessageBox::Critical);
        box.setStandardButtons (QMessageBox::Ok);
        box.setButtonText (QMessageBox::Ok,QString("确定"));
        box.exec ();
        return;
    }

    if(editPassword->text() != editConfirm->text())
    {
        QMessageBox box(this);
        box.setWindowTitle(QStringLiteral("错误："));
        box.setText(QStringLiteral("两次密码不匹配.\n请重新输入！"));
        box.setIcon(QMessageBox::Critical);
        box.setStandardButtons (QMessageBox::Ok);
        box.setButtonText (QMessageBox::Ok,QString("确定"));
        box.exec ();
        return ;
    }
    if(CTYDb::getInstance()->addNewUser(editUser->text(), editPassword->text()))
    {
        QMessageBox box(this);
        box.setWindowTitle(QStringLiteral("提示："));
        box.setText(QStringLiteral("注册成功.\n"));
        box.setIcon(QMessageBox::Information);
        box.setStandardButtons (QMessageBox::Ok);
        box.setButtonText (QMessageBox::Ok,QString("确定"));
        box.exec ();
        close();
    }
    else
    {
        QMessageBox box(this);
        box.setWindowTitle(QStringLiteral("错误："));
        box.setText(QStringLiteral("注册失败！"));
        box.setIcon(QMessageBox::Critical);
        box.setStandardButtons (QMessageBox::Ok);
        box.setButtonText (QMessageBox::Ok,QString("确定"));
        box.exec ();
    }
}
