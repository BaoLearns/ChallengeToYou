#include "mainwindow.h"
#include <QMessageBox>
#include "CTYDb.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , m_blankWidget(new QWidget)
    , m_loginWidget(new LoginWidget)
    , m_userWidget(new UserWidget)
    , m_problemWidget(new ProblemWidget)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    setWindowTitle(QString::fromLocal8Bit("ProblemAnsweringSystem"));
    setWindowIcon(QIcon(QString::fromLocal8Bit(":/resources/image/icon.ico")));
    //setWindowFlags(Qt::FramelessWindowHint);

    //m_loginWidget->resize(size());
    //m_blankWidget->setFixedSize(1000, 800);
    m_blankWidget->setFixedWidth(1000);
    m_leftStkWid = new QStackedWidget();
    m_rightStkWid = new QStackedWidget();
    m_leftStkWid->setStyleSheet("border-color: rgb(255, 255, 255)");
    m_rightStkWid->setStyleSheet("border-color: rgb(255, 255, 255)");
    m_leftStkWid->addWidget(m_blankWidget);

    m_leftStkWid->addWidget(m_problemWidget);
    m_rightStkWid->addWidget(m_loginWidget);
    m_rightStkWid->addWidget(m_userWidget);

    //widgetBlank->setFixedWidth(this->width() - m_loginWidget->width() - 100);
   // widgetBlank->setStyleSheet("background-image:url(:/resources/image/background3.jpg)");

    mainLayout = new QHBoxLayout();
    //mainLayout->setAlignment(Qt::AlignRight);
    mainLayout->addWidget(m_leftStkWid, 0, Qt::AlignLeft);
    mainLayout->addWidget(m_rightStkWid, 0, Qt::AlignRight);
    setLayout(mainLayout);
    connect(m_loginWidget, SIGNAL(signalAuthenticationSucceed()),
            this, SLOT(slotLoginSucceed()));
    connect(m_loginWidget, SIGNAL(signalAuthenticationFailed()),
            this, SLOT(slotLoginFailed()));

    connect(m_userWidget, SIGNAL(signalStart()), this, SLOT(slotStartContest()));
    connect(m_userWidget, SIGNAL(signalLogout()), this, SLOT(slotLogout()));

    connect(m_problemWidget, SIGNAL(signalCommit(int)), this, SLOT(slotCommitProblems(int)));
    connect(CTYDb::getInstance(), SIGNAL(signalContestDone()), this, SLOT(slotContestDone()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::slotLoginSucceed()
{
    const QString strUserName = m_loginWidget->getUserName();
    //delete widgetBlank;
    //delete mainLayout;
    //delete m_userWidget;

//    widgetBlank = new QWidget();
//    widgetBlank->setFixedWidth(this->width() - widthRight - 100);
//    QString st = CTYDb::getInstance()->getCurrentUser();
    //setLayout(mainLayout);
    m_rightStkWid->setCurrentWidget(m_userWidget);
    m_userWidget->reset();
    m_userWidget->setUserName(strUserName);
    m_userWidget->setScore(CTYDb::getInstance()->getScoreByUser(strUserName));
}

void MainWindow::slotLoginFailed()
{
    QMessageBox box(this);
    box.setWindowTitle(QStringLiteral("错误："));
    box.setText(QStringLiteral("用户名或密码错.\n请重新输入！"));
    box.setIcon(QMessageBox::Critical);
    box.setStandardButtons (QMessageBox::Ok);
    box.setButtonText (QMessageBox::Ok,QString("确定"));
    box.exec ();
}

void MainWindow::slotStartContest()
{
    Log::writeLog("Begin Match Contest.");
    const QString strUserName = m_userWidget->getUserName();

    //delete widgetBlank;
    //delete mainLayout;
    //mainLayout->removeWidget(m_userWidget);

    //m_problemWidget->setFixedWidth(this->width() - m_userWidget->width() - 100);
    m_problemWidget->reset();
    m_problemWidget->setProblems(CTYDb::getInstance()->getMatchPair(strUserName).problems);
    m_problemWidget->setUsername(strUserName);
    //m_userWidget = new UserWidget(strUserName);
    m_userWidget->appendMessage(QStringLiteral("匹配到对手，开始答题！"));
    m_leftStkWid->setCurrentWidget(m_problemWidget);
    //layout->addWidget(m_userWidget);

    Log::writeLog("End Match Contest.");
}

void MainWindow::slotCommitProblems(int score)
{
    m_userWidget->appendMessage(QStringLiteral("已提交给系统，正在处理..."));
    CTYDb::getInstance()->commitByUser(m_userWidget->getUserName(), score);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    Log::writeLog("Entry Key Press");
    if(event->key() == Qt::Key_Enter)
    {
        Log::writeLog("Begin Login");
        m_loginWidget->slotLogin();
    }
}

void MainWindow::setProblems(const ListProblemItem &problems)
{
    m_Problems = problems;
}

void MainWindow::setMatchStatus(bool status)
{
    isAlreadyMatch = status;
}

void MainWindow::slotContestDone()
{
    MatchPair pair = CTYDb::getInstance()->getMatchPair(m_userWidget->getUserName());
    QString firstUser = pair.first;
    QString secondUser = pair.second;
    QString result;
    if(m_userWidget->getUserName() == firstUser)
    {
        if(pair.first_score > pair.second_score)
        {
            result = QStringLiteral("(*@ο@*) 哇～， 你赢得了比赛，总积分+1");
        }
        else if(pair.first_score < pair.second_score)
        {
            result = QStringLiteral("o(╯□╰)o，你输了比赛");
        }
        else
        {
            result = QStringLiteral("┑(￣Д ￣)┍，你们实力接近，分不出胜负");
        }
    }
    else
    {
        if(pair.first_score > pair.second_score)
        {
            result = QStringLiteral("o(╯□╰)o，你输了比赛");
        }
        else if(pair.first_score < pair.second_score)
        {
            result = QStringLiteral("(*@ο@*) 哇～， 你赢得了比赛，总积分+1");
        }
        else
        {

            result = QStringLiteral("┑(￣Д ￣)┍，你们实力接近，分不出胜负");
        }
    }
    m_userWidget->appendMessage(result);
    m_userWidget->completeMatch();
}

void MainWindow::slotLogout()
{
    _reset();
    Log::writeLog("reset MainWindow");
    //close();

//    if(m_userWidget)
//    {
//        delete m_userWidget;
//    }
//    if(m_problemWidget)
//    {
//        delete m_problemWidget;
//    }
//    widgetBlank = new QWidget();
//    widgetBlank->resize(1200, 800);
//    widgetBlank->setFixedWidth(this->width() - m_loginWidget->width() - 100);
//    //widgetBlank->setStyleSheet("background-image:url(:/resources/image/background.jpg)");

//    m_loginWidget = new LoginWidget();
//    QHBoxLayout *mainLayout = new QHBoxLayout();
//    mainLayout->setAlignment(Qt::AlignRight);
//    mainLayout->addWidget(widgetBlank);
//    mainLayout->addWidget(m_loginWidget, 100);
//    setLayout(mainLayout);

//    connect(m_loginWidget, SIGNAL(signalAuthenticationSucceed()),
//            this, SLOT(slotLoginSucceed()));
//    connect(m_loginWidget, SIGNAL(signalAuthenticationFailed()),
//            this, SLOT(slotLoginFailed()));
}

void MainWindow::_reset()
{/*
    if(m_userWidget)
    {
        delete m_userWidget;
        m_userWidget = NULL;
    }
    if(m_problemWidget)
    {
        delete m_problemWidget;
        m_problemWidget = NULL;
    }

    m_loginWidget = new LoginWidget;
    m_problemWidget = new ProblemWidget;
    //m_loginWidget->resize(size());
    widgetBlank = new QWidget();
    widgetBlank->resize(1200, 800);
    widgetBlank->setFixedWidth(this->width() - m_loginWidget->width() - 100);
    //widgetBlank->setStyleSheet("background-image:url(:/resources/image/background.jpg)");
    mainLayout = static_cast<QHBoxLayout*>(this->layout());
    delete mainLayout;
    mainLayout = new QHBoxLayout();
    mainLayout->setAlignment(Qt::AlignRight);
    mainLayout->addWidget(widgetBlank);
    mainLayout->addWidget(m_loginWidget, 100);
    setLayout(mainLayout);

    connect(m_loginWidget, SIGNAL(signalAuthenticationSucceed()),
            this, SLOT(slotLoginSucceed()));
    connect(m_loginWidget, SIGNAL(signalAuthenticationFailed()),
            this, SLOT(slotLoginFailed()));*/

    m_loginWidget->reset();
    m_leftStkWid->setCurrentWidget(m_blankWidget);
    m_rightStkWid->setCurrentWidget(m_loginWidget);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(m_userWidget)
    {
        Log::writeLog("Start Offline.");
        QString username = m_userWidget->getUserName();
        if(!username.isEmpty())
        {
            CTYDb::getInstance()->updateStatus(username, "offline");
            CTYDb::getInstance()->CancelMatchOpponent(username);
        }
    }
}
