#include "LoginWidget.h"
#include <QTextStream>
#include <QFile>
#include <QFont>
#include "Log.h"
#include "CTYDb.h"

#include <QKeyEvent>
#include <qDebug>
#include <QTextCodec>
#include <QGroupBox>
#include <QMessageBox>
#include "RegisterWidget.h"

LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    setFixedSize(300, 740);

    labelUserName = new QLabel(QString::fromLocal8Bit("用户名："));
    labelPassword = new QLabel(QString::fromLocal8Bit("密码：  "));

    lineEditUserName = new QLineEdit();
    lineEditPassword = new QLineEdit();
    lineEditPassword->setEchoMode(QLineEdit::Password);

    buttonLogin = new QPushButton(QString::fromLocal8Bit("登录"));
    buttonCancle = new QPushButton(QString::fromLocal8Bit("注册"));
    connect(buttonLogin, SIGNAL(clicked()), this, SLOT(slotLogin()));
    connect(buttonCancle, SIGNAL(clicked()), this, SLOT(slotCancle()));
    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(labelUserName);
    topLayout->addWidget(lineEditUserName);

    QHBoxLayout *midLayout = new QHBoxLayout();
    midLayout->addWidget(labelPassword);
    midLayout->addWidget(lineEditPassword);

    QHBoxLayout *bottomLayout = new QHBoxLayout();
    bottomLayout->addWidget(buttonLogin);
    bottomLayout->addWidget(buttonCancle);

    QVBoxLayout  *mainLayout = new QVBoxLayout();
    mainLayout->setMargin(20);
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(midLayout);
    mainLayout->addLayout(bottomLayout);

    QFont serifFont("黑体", 11, QFont::Bold);
    labelUserName->setFont(serifFont);
    labelPassword->setFont(serifFont);
    lineEditUserName->setFont(serifFont);
    buttonLogin->setFont(serifFont);
    buttonCancle->setFont(serifFont);

    QGroupBox *group = new QGroupBox();
    //group->setFixedHeight(600);
    group->setLayout(mainLayout);

    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->addWidget(group);
    setLayout(vLayout);
}

LoginWidget::~LoginWidget()
{

}
void LoginWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Enter)
    {
        qDebug() << "press Enter";
        slotLogin();
    }
    else if(event->key() == Qt::Key_Escape)
    {
        emit close();
    }
}


void LoginWidget::slotLogin()
{
    QString strUserName = lineEditUserName->text().trimmed();
    QString strPassword = lineEditPassword->text().trimmed();

    if(strUserName.isEmpty() || strPassword.isEmpty())
    {
        QMessageBox box(this);
        box.setWindowTitle(QStringLiteral("警告："));
        box.setText(QStringLiteral("用户名或密码输入不完整.\n请重新输入."));
        box.setIcon(QMessageBox::Warning);
        box.setStandardButtons (QMessageBox::Ok);
        box.setButtonText (QMessageBox::Ok,QString("确定"));
        box.exec ();
        return ;
    }
    if(CTYDb::getInstance()->isVaild(strUserName, strPassword))
    {
        CTYDb::getInstance()->updateStatus(strUserName, "online");
        emit signalAuthenticationSucceed();
    }
    else
    {
        emit signalAuthenticationFailed();
        lineEditPassword->setText("");
    }
}

void LoginWidget::slotCancle()
{
    RegisterWidget *RegisterWid = new RegisterWidget(this);
    RegisterWid->exec();
    delete RegisterWid;
}

QString LoginWidget::getUserName() const
{
    return lineEditUserName->text();
}

void LoginWidget::reset()
{
    lineEditUserName->clear();
    lineEditPassword->clear();
}
