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

void UserWidget::_init()
{
    setFixedSize(300, 800);
    QLabel *label = new QLabel(QStringLiteral("欢迎，") + strUserName);
    QLabel *labelScore = new QLabel(QStringLiteral("你的总积分是：")
                                    + QString::number(CTYDb::getInstance()->getScoreByUser(strUserName)));
    btnStart = new QPushButton("挑战");
    labelStatus = new QLabel(QStringLiteral(""));
    QVBoxLayout *layoutMain = new QVBoxLayout();
    layoutMain->addWidget(label);
    layoutMain->addWidget(labelScore);
    layoutMain->addWidget(btnStart);
    layoutMain->addWidget(labelStatus);

    setLayout(layoutMain);

    connect(btnStart, SIGNAL(clicked()), this, SLOT(slotClickedStart()));
//    connect(btnStart, SIGNAL(clicked()), this, SIGNAL(signalRequestStart()));

    connect(CTYDb::getInstance(), SIGNAL(signalMatchSuccess(const QString&)),
            this, SLOT(slotMatchSuccess(const QString&)));
//    connect(CTYDb::getInstance(), SIGNAL(signalMatchFail(const QString&)),
//            this, SLOT(slotMatchFail(const QString&)));
}

void UserWidget::slotClickedStart()
{
    labelStatus->setText(QStringLiteral("正在匹配对手...."));

    labelStatus->update();
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
      labelStatus->setText(QStringLiteral("没有合适的对手！"));
      return;
    }
    else
    {
        MatchPair pair = CTYDb::getInstance()->getMatchPair(strUserName);
        if(pair.first == strUserName)
        {
            labelStatus->setText(QStringLiteral("匹配到对手:") + pair.second);
        }
        else
        {
            labelStatus->setText(QStringLiteral("匹配到对手:") + pair.first);
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
    labelStatus->setText(message);
    labelStatus->setHidden(isHidden);
}

void UserWidget::setUserName(const QString &username)
{
    strUserName = username;

}

QString UserWidget::getUserName() const
{
    return strUserName;
}
