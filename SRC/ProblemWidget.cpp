#include "ProblemWidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMessageBox>
#include "Client.h"
#include <QThread>
#include "CTYConfig.h"

ProblemWidget::ProblemWidget(QWidget *parent)
    : QWidget(parent)
{
    _init();
}

void ProblemWidget::_init()
{
    m_UI = new Ui_Form();
    m_UI->setupUi(this);

    indexToLabel.insert(1, m_UI->label_1);
    indexToLabel.insert(2, m_UI->label_2);
    indexToLabel.insert(3, m_UI->label_3);
    indexToLabel.insert(4, m_UI->label_4);
    indexToLabel.insert(5, m_UI->label_5);
    indexToLabel.insert(6, m_UI->label_6);
    indexToLabel.insert(7, m_UI->label_7);
    indexToLabel.insert(8, m_UI->label_8);
    indexToLabel.insert(9, m_UI->label_9);
    indexToLabel.insert(10, m_UI->label_10);

    for(int i = 1; i <= 10; ++i)
    {
        updateLabel(i, LabelColor::White);
    }

    connect(m_UI->pushButtonNext, SIGNAL(clicked()), this, SLOT(slotClickedNext()));
    connect(m_UI->pushButtonCommit, SIGNAL(clicked()), this, SLOT(slotClickedCommit()));
    //m_ListProblem = CTYDb::getInstance()->getNumProblem();
    //m_ListProblem = CTYClient::getInstance()->getProblmes();
    m_CurrentIndex = 0;

    m_UI->labelRunTime->setText(QString::number(0));
    timer = new QTimer();
    // 关联定时器计满信号和相应的槽函数
    connect(timer,SIGNAL(timeout()),this,SLOT(slotTimerUpDate()));
    // 每隔1ms执行xytimerUpDate()函数
    timer->setInterval(1000);
    connect(CTYDb::getInstance(), SIGNAL(signalUpdateScore(const QString &, const QString &)),
            this, SLOT(slotUpdateScore(const QString &, const QString &)));

    m_ChoiceWidget = new SelectWidget();
    m_QAWidget  = new QAWidget();
    m_UI->stackedWidget->addWidget(m_ChoiceWidget);
    m_UI->stackedWidget->addWidget(m_QAWidget);
}

void ProblemWidget::setData(const ProblemItem &p)
{
    if(p.type == ProblemType::Select)
    {
        m_ChoiceWidget->setDesc(p.opProblem.strDescription);
        m_ChoiceWidget->setOptions(p.opProblem.strOptionA,
                                   p.opProblem.strOptionB,
                                   p.opProblem.strOptionC,
                                   p.opProblem.strOptionD);
        m_UI->stackedWidget->setCurrentWidget(m_ChoiceWidget);
    }
    else if(p.type == ProblemType::QAndA)
    {
        m_QAWidget->setDesc(p.qaProblem.desc);
        m_UI->stackedWidget->setCurrentWidget(m_QAWidget);
    }
    else
    {
        Log::writeLog("Some Error Was Happend.");
        Log::writeLog("Type Is " + QString::number(p.type));
    }

    if(indexToLabel.find(m_CurrentIndex + 1) != indexToLabel.end())
    {
        updateLabel(m_CurrentIndex + 1, LabelColor::Yellow);
    }
}

void ProblemWidget::slotClickedPrevious()
{
    vaildAnswer();
    m_CurrentIndex--;
    // 上一题
    setData(m_ListProblem.at(m_CurrentIndex));
}

void ProblemWidget::slotClickedNext()
{
    vaildAnswer();
    CTYDb::getInstance()->updateContestingScore(
                m_Username, m_UI->labelScore->text().toInt());
    m_CurrentIndex++;

    if(m_CurrentIndex < m_ListProblem.size())
    {
        // 下一题
        setData(m_ListProblem.at(m_CurrentIndex));
    }
    else
    {
        m_UI->pushButtonNext->setEnabled(false);
        //计算得分
    }
}

void ProblemWidget::slotClickedCommit()
{
    timer->stop();
    emit signalCommit(m_UI->labelScore->text().toInt());
    m_UI->pushButtonCommit->setEnabled(false);
    m_UI->pushButtonNext->setEnabled(false);
    QMessageBox box(this);
    box.setWindowTitle(QStringLiteral("提示："));
    box.setText(QStringLiteral("系统已经接受您的提交，请等待本局对抗结束!"));
    box.setIcon(QMessageBox::Information);
    box.setStandardButtons (QMessageBox::Ok);
    box.setButtonText (QMessageBox::Ok,QString("确定"));
    box.exec ();
}

bool ProblemWidget::updateLabel(int index, LabelColor color)
{
    QString sheet;
    if(color == LabelColor::White)
    {
        sheet = QString("background-color: rgb(255, 255, 255)");
    }
    else if(color == LabelColor::Red)
    {
        sheet = QString("background-color: rgb(255, 0, 0)");
    }
    else if(color == LabelColor::Yellow)
    {
        sheet = QString("background-color: rgb(245, 255, 44)");
    }
    else if(color == LabelColor::Green)
    {
        sheet = QString("background-color: rgb(55, 255, 61)");
    }
    if(indexToLabel.find(index) != indexToLabel.end())
    {
        indexToLabel[index]->setStyleSheet(sheet);
        return true;
    }
    return false;
}

void ProblemWidget::vaildAnswer()
{
    bool ok = false;
    if(m_ListProblem.at(m_CurrentIndex).type == ProblemType::Select)
    {
        QString answer = m_ChoiceWidget->getOption();
        ok = CTYDb::getInstance()->vaildAnswer(
                        m_ListProblem.at(m_CurrentIndex).opProblem.index,
                        m_ListProblem.at(m_CurrentIndex).type,
                        answer);
    }
    else if(m_ListProblem.at(m_CurrentIndex).type == ProblemType::QAndA)
    {
        QString answer = m_QAWidget->getAnswer();
        ok = CTYDb::getInstance()->vaildAnswer(
                        m_ListProblem.at(m_CurrentIndex).qaProblem.index,
                        m_ListProblem.at(m_CurrentIndex).type,
                        answer);
    }

    if(ok)
    {
        updateLabel(m_CurrentIndex + 1, LabelColor::Green);
        int score = m_UI->labelScore->text().toInt();
        m_UI->labelScore->setText(QString::number(score + 1));
    }
    else
    {
        updateLabel(m_CurrentIndex + 1, LabelColor::Red);
    }
}

void ProblemWidget::slotTimerUpDate()
{
    int second = m_UI->labelRunTime->text().toInt();
    if(second == Config::getInstance()->getMaxContestingSec())
    {
        timer->stop();
        emit signalCommit(m_UI->labelScore->text().toInt());
        m_UI->pushButtonCommit->setEnabled(false);
        m_UI->pushButtonNext->setEnabled(false);
        QMessageBox box(this);
        box.setWindowTitle(QStringLiteral("提示："));
        box.setText(QStringLiteral("您已超过答题时间，被强制提交."));
        box.setIcon(QMessageBox::Information);
        box.setStandardButtons (QMessageBox::Ok);
        box.setButtonText (QMessageBox::Ok,QString("确定"));
        box.exec ();
        return ;
    }
    m_UI->labelRunTime->setText(QString::number(second + 1));
}

void ProblemWidget::setProblems(ListProblemItem Problems)
{
    m_ListProblem = Problems;

    m_CurrentIndex = 0;
    if(timer->isActive())
    {
        m_UI->labelRunTime->setText("0");
        timer->stop();
    }

    m_UI->pushButtonCommit->setEnabled(true);
    m_UI->pushButtonNext->setEnabled(true);
    timer->start();
    setData(m_ListProblem.at(m_CurrentIndex));
}

void ProblemWidget::setUsername(const QString &username)
{
    m_Username = username;
}

void ProblemWidget::slotUpdateScore(const QString &first, const QString &second)
{
    Log::writeLog("QQQQQQ");
    if(first == m_Username)
    {
        int oppScore = CTYDb::getInstance()->getContestingScore(second);
        Log::writeLog("Update score opp score " + second);
        m_UI->labelOpponentScore->setText(QString::number(oppScore));
    }
    else if(second == m_Username)
    {
        int oppScore = CTYDb::getInstance()->getContestingScore(first);
        Log::writeLog("Update score opp score " + second);
        m_UI->labelOpponentScore->setText(QString::number(oppScore));
    }
}

void ProblemWidget::reset()
{
    m_UI->labelRunTime->setText("0");
    m_UI->labelScore->setText("0");
    m_UI->labelOpponentScore->setText("0");
    for(int i = 1; i <= 10; ++i)
    {
        updateLabel(i, LabelColor::White);
    }
    timer->stop();
}
