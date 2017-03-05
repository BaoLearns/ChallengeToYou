#include "mainwindow.h"
#include <QMessageBox>
#include "CTYDb.h"


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , m_loginWidget(new LoginWidget)
    /*, m_userWidget(new UserWidget(""))*/
    , m_problemWidget(new ProblemWidget)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    setWindowTitle(QString::fromLocal8Bit("ChallengeToYou"));
    setWindowIcon(QIcon(QString::fromLocal8Bit(":/resources/image/icon.ico")));
    //setWindowFlags(Qt::FramelessWindowHint);

    //m_loginWidget->resize(size());
    widgetBlank = new QWidget();
    widgetBlank->resize(1200, 800);
    widgetBlank->setFixedWidth(this->width() - m_loginWidget->width() - 100);
    //widgetBlank->setStyleSheet("background-image:url(:/resources/image/background.jpg)");
    mainLayout = new QHBoxLayout();
    mainLayout->setAlignment(Qt::AlignRight);
    mainLayout->addWidget(widgetBlank);
    mainLayout->addWidget(m_loginWidget, 100);
    setLayout(mainLayout);

    connect(m_loginWidget, SIGNAL(signalAuthenticationSucceed()),
            this, SLOT(slotLoginSucceed()));
    connect(m_loginWidget, SIGNAL(signalAuthenticationFailed()),
            this, SLOT(slotLoginFailed()));

}

MainWindow::~MainWindow()
{

}

void MainWindow::slotLoginSucceed()
{
    const int widthRight = m_loginWidget->width();
    const QString strUserName = m_loginWidget->getUserName();
    //delete m_loginWidget;
    mainLayout->removeWidget(m_loginWidget);
    delete m_loginWidget;
    //delete widgetBlank;
    //delete mainLayout;
    //delete m_userWidget;

//    widgetBlank = new QWidget();
//    widgetBlank->setFixedWidth(this->width() - widthRight - 100);
//QString st = CTYDb::getInstance()->getCurrentUser();

    m_userWidget = new UserWidget(strUserName);
    mainLayout->addWidget(m_userWidget);

    //setLayout(mainLayout);
    connect(m_userWidget, SIGNAL(signalStart()), this, SLOT(slotStartContest()));
}

void MainWindow::slotLoginFailed()
{
    QMessageBox box(this);
    box.setWindowTitle(QStringLiteral("错误："));
    box.setText(QStringLiteral("用户名或密码错请重新输入！"));
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
    if(widgetBlank != NULL)
    {
        mainLayout->removeWidget(widgetBlank);
    }
    //mainLayout->removeWidget(m_userWidget);

    //m_problemWidget = new ProblemWidget();
    m_problemWidget->setFixedWidth(this->width() - m_userWidget->width() - 100);
    m_problemWidget->setProblems(CTYDb::getInstance()->getMatchPair(strUserName).problems);
    //m_userWidget = new UserWidget(strUserName);
    m_userWidget->appendMessage(QStringLiteral("匹配到对手，开始答题！"));

    delete mainLayout;
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(m_problemWidget);
    layout->setAlignment(Qt::AlignLeft);
    //layout->addWidget(m_userWidget);

    setLayout(layout);
    Log::writeLog("End Match Contest.");
    connect(m_problemWidget, SIGNAL(signalCommit(int)), this, SLOT(slotCommitProblems(int)));
    connect(CTYDb::getInstance(), SIGNAL(signalContestDone()), this, SLOT(slotContestDone()));
}

void MainWindow::slotCommitProblems(int score)
{
    m_userWidget->appendMessage(QStringLiteral("已提交给系统，正在处理..."));
    CTYDb::getInstance()->commitByUser(m_userWidget->getUserName(), score);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Enter)
    {
        m_loginWidget->slotLogin();
    }
}


void MainWindow::setProblems(const ListProblem &problems)
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
