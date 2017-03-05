#include "UserWidget.h"
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "CTYDb.h"
#include "Client.h"
#include "CTYThread.h"
#include <QThread>
#include <QMessageBox>


CTYThread *UserWidget::m_Thread = new CTYThread();

UserWidget::UserWidget(QWidget *parent)
    : QWidget(parent)
{
    _init();
}

UserWidget::UserWidget(const QString &username, QWidget *parent)
    : strUserName(username)
    , QWidget(parent)
{
    _init();
}

UserWidget::~UserWidget()
{
    delete m_UI;
}

void UserWidget::_init()
{
    m_UI = new Ui_UserForm();
    m_UI->setupUi(this);

    setFixedSize(300, 800);
    m_UI->label->setText(QStringLiteral("欢迎您，") + strUserName);
    m_UI->labelTotalScore->setText(QStringLiteral("你的总积分是：")
                                        + QString::number(CTYDb::getInstance()->getScoreByUser(strUserName)));

    isContesting = false;
    connect(m_UI->pushButtonStartOrCancle, SIGNAL(clicked()), this, SLOT(slotClickedStart()));
    connect(m_UI->pushButtonLogout, SIGNAL(clicked()), this, SLOT(slotLogout()));
//    connect(btnStart, SIGNAL(clicked()), this, SIGNAL(signalRequestStart()));

    connect(CTYDb::getInstance(), SIGNAL(signalMatchSuccess(const QString&)),
            this, SLOT(slotMatchSuccess(const QString&)));
//    connect(CTYDb::getInstance(), SIGNAL(signalMatchFail(const QString&)),
//            this, SLOT(slotMatchFail(const QString&)));
}

void UserWidget::slotClickedStart()
{
    appendMessage(QStringLiteral("正在匹配对手...."));

    m_UI->pushButtonStartOrCancle->setEnabled(false);
    //CTYThread *thread = new CTYThread(strUserName);


    //m_Thread->setUserName(strUserName);
    //m_Thread->start();

    //Sleep(10000);
    CTYDb::getInstance()->MatchOpponent(strUserName);
//    QMessageBox box(this);
//    box.setWindowTitle(QStringLiteral("提示："));
//    box.setText(QStringLiteral("正在匹配对手...."));
//    box.setIcon(QMessageBox::Information);
//    box.setStandarCTYDbuttons (QMessageBox::Cancel);
//    box.setButtonText (QMessageBox::Ok,QString("取消配对"));
//    box.exec ();


}

void UserWidget::slotMatchSuccess(const QString &)
{
    if(!CTYDb::getInstance()->isAlreadyMatch(strUserName))
    {
      appendMessage(QStringLiteral("没有合适的对手！"));
      return;
    }
    else
    {
        m_UI->pushButtonStartOrCancle->setEnabled(false);
        MatchPair pair = CTYDb::getInstance()->getMatchPair(strUserName);
        if(pair.first == strUserName)
        {
            appendMessage(QStringLiteral("匹配到对手:") + pair.second);

        }
        else
        {
            appendMessage(QStringLiteral("匹配到对手:") + pair.first);
        }
    }
    //btnStart->setHidden(true);
    emit signalStart();
}

void UserWidget::slotMatchFail(const QString &)
{

}

void UserWidget::setLabelStatus(const QString &message, bool isHidden)
{
}

void UserWidget::setUserName(const QString &username)
{
    strUserName = username;

}

QString UserWidget::getUserName() const
{
    return strUserName;
}

void UserWidget::slotLogout()
{
    CTYDb::getInstance()->updateStatus(strUserName, "offline");
    appendMessage(QStringLiteral("成功注销！"));
    Sleep(2000);
    qApp->exit();
}


bool UserWidget::appendMessage(const QString &message)
{
    m_UI->textEditOutput->append("\n" + message);
    return true;
}

bool UserWidget::completeMatch()
{
    m_UI->pushButtonStartOrCancle->setEnabled(true);
    m_UI->pushButtonStartOrCancle->setText(QStringLiteral("挑战"));
    m_UI->labelTotalScore->setText(QStringLiteral("你的总积分是：")
                                   + QString::number(CTYDb::getInstance()->getScoreByUser(strUserName)));
    return true;
}
