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
#include <QGroupBox>
#include <QDialog>
#include "TimerWidget.h"
#include <QSplitter>
#include "CTYConfig.h"

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
    setFont(Config::getInstance()->getFont());
    //m_UI = new Ui_UserForm();
    //m_UI->setupUi(this);
    //m_UI->groupBox->setStyleSheet(QObject::tr(" border: 1px solid;"));
    m_UserWidget = new QDockWidget();
    labelUser = new QLabel(QStringLiteral("欢迎您，") + strUserName);
    btnLogout = new QPushButton(QStringLiteral("注销"));
    labelScore = new QLabel(QStringLiteral("总积分：")
                            + QString::number(CTYDb::getInstance()->getScoreByUser(strUserName)));
    btnCommit = new QPushButton(QStringLiteral("发起挑战"));
    labelUser->setFont(Config::getInstance()->getFont());
    btnLogout->setFont(Config::getInstance()->getFont());
    labelScore->setFont(Config::getInstance()->getFont());
    btnCommit->setFont(Config::getInstance()->getFont());

    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(labelUser);
    topLayout->addWidget(btnLogout, 0, Qt::AlignRight);

    QVBoxLayout *userLayout = new QVBoxLayout();
    userLayout->addLayout(topLayout);
    userLayout->addWidget(labelScore);
    userLayout->addWidget(btnCommit);
    QGroupBox *userBox = new QGroupBox();
    userBox->setLayout(userLayout);
    //m_UserWidget->setWidget(userBox);
    QVBoxLayout *tLayout = new QVBoxLayout();
    tLayout->addWidget(userBox);
    QWidget *topWidget = new QWidget();
    topWidget->setLayout(tLayout);

    m_EventWidget = new QDockWidget();
    textEditEvents = new QTextEdit();
    textEditEvents->setFont(QFont("宋体", 10));
    QGroupBox *eventBox = new QGroupBox("消息列表");
    eventBox->setFont(Config::getInstance()->getFont());
    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->addWidget(textEditEvents);
    eventBox->setLayout(vLayout);
    //m_EventWidget->setWidget(eventBox);
    QVBoxLayout *bLayout = new QVBoxLayout();
    bLayout->addWidget(eventBox);
    QWidget *bottomWidget = new QWidget();
    bottomWidget->setLayout(bLayout);

    QSplitter *spliter = new QSplitter(Qt::Vertical);
    //spliter->addWidget(m_UserWidget);
    //spliter->addWidget(m_EventWidget);
    spliter->addWidget(topWidget);
    spliter->addWidget(bottomWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(spliter);
    setLayout(mainLayout);

    //setFixedSize(300, 740);
//    m_UI->label->setText(QStringLiteral("欢迎您，") + strUserName);
//    m_UI->labelTotalScore->setText(QStringLiteral("总积分：")
//                                        + QString::number(CTYDb::getInstance()->getScoreByUser(strUserName)));

    isContesting = false;
    connect(btnCommit, SIGNAL(clicked()), this, SLOT(slotClickedStart()));
    connect(btnLogout, SIGNAL(clicked()), this, SLOT(slotLogout()));
//    connect(btnStart, SIGNAL(clicked()), this, SIGNAL(signalRequestStart()));

    connect(CTYDb::getInstance(), SIGNAL(signalMatchSuccess(const QString&)),
            this, SLOT(slotMatchSuccess(const QString&)));
//    connect(CTYDb::getInstance(), SIGNAL(signalMatchFail(const QString&)),
//            this, SLOT(slotMatchFail(const QString&)));

    m_Timer = new QTimer(this);

    // 匹配时间15秒
    m_Timer->setInterval(1000 * 15);
    connect(m_Timer, SIGNAL(timeout()), this, SLOT(slotTimeout()));
}

void UserWidget::slotClickedStart()
{
    m_Timer->start();
    btnCommit->setText(QStringLiteral("匹配中"));
    appendMessage(QStringLiteral("正在匹配对手...."));

    btnCommit->setEnabled(false);
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
        btnCommit->setEnabled(false);
        MatchPair pair = CTYDb::getInstance()->getMatchPair(strUserName);
        if(pair.first == strUserName)
        {
            appendMessage(QStringLiteral("匹配到对手:") + pair.second);

        }
        else
        {
            appendMessage(QStringLiteral("匹配到对手:") + pair.first);
        }
        m_Timer->stop();
    }
    //btnStart->setHidden(true);
    btnCommit->setText(QStringLiteral("对战中..."));
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
    labelUser->setText(username);
}

void UserWidget::setScore(int score)
{
    labelScore->setText(QStringLiteral("总积分：")
                            + QString::number(score));
}

QString UserWidget::getUserName() const
{
    return strUserName;
}

void UserWidget::slotLogout()
{
    CTYDb::getInstance()->updateStatus(strUserName, "offline");
    appendMessage(QStringLiteral("成功注销！"));
    //Sleep(2000);
    emit signalLogout();
}


bool UserWidget::appendMessage(const QString &message)
{
    textEditEvents->append("\n" + message);
    return true;
}

bool UserWidget::completeMatch()
{
    btnCommit->setEnabled(true);
    btnCommit->setText(QStringLiteral("挑战"));
    labelScore->setText(QStringLiteral("你的总积分是：")
                                   + QString::number(CTYDb::getInstance()->getScoreByUser(strUserName)));
    return true;
}

void UserWidget::slotTimeout()
{
    m_Timer->stop();
    appendMessage(QStringLiteral("未匹配到合适的对手，结束匹配！"));

    QMessageBox box(this);
    box.setWindowTitle(QStringLiteral("提示："));
    box.setText(QStringLiteral("暂未匹配到合适的对手.\n请稍后重新输入！"));
    box.setIcon(QMessageBox::Information);
    box.setStandardButtons (QMessageBox::Ok);
    box.setButtonText (QMessageBox::Ok,QString("确定"));
    box.exec ();

    CTYDb::getInstance()->CancelMatchOpponent(strUserName);
    btnCommit->setEnabled(true);
}

void UserWidget::reset()
{
    textEditEvents->clear();
    btnCommit->setText(QStringLiteral("发起挑战"));

}
