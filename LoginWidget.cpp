#include "LoginWidget.h"
#include <QTextStream>
#include <QFile>
#include "Log.h"
#include "CTYDb.h"

#include <QKeyEvent>
#include <qDebug>
#include <QTextCodec>

LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
     //
    //setFixedSize(200, 100);
    setFixedSize(300, 800);
    labelUserName = new QLabel(QString::fromLocal8Bit("用户名："));
    labelPassword = new QLabel(QString::fromLocal8Bit("密码：  "));

    lineEditUserName = new QLineEdit();
    lineEditPassword = new QLineEdit();
    lineEditPassword->setEchoMode(QLineEdit::Password);

    buttonLogin = new QPushButton(QString::fromLocal8Bit("登录"));
    buttonCancle = new QPushButton(QString::fromLocal8Bit("取消"));
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
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(midLayout);
    mainLayout->addLayout(bottomLayout);

    setLayout(mainLayout);


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
    emit close();
}

QString LoginWidget::getUserName() const
{
    return lineEditUserName->text();
}
