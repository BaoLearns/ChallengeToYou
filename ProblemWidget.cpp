#include "ProblemWidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMessageBox>
#include "Client.h"

ProblemWidget::ProblemWidget(QWidget *parent)
    : QWidget(parent)
{
    _init();
}

ProblemWidget::ProblemWidget(const int id, const QString &strDesc,
                             const QString &strOptionA, const QString &strOptionB,
                             const QString &strOptionC, const QString &strOptionD,
                             bool isFirst, bool isLast)
{
    _init();
    setData(id, strDesc, strOptionA, strOptionB, strOptionC, strOptionD);
}

void ProblemWidget::_init()
{
    m_UI = new Ui_Form();
    m_UI->setupUi(this);
    m_UI->textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//设置垂直滚动条不可见
    m_UI->textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//设置水平滚动条不可见
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
    connect(timer,SIGNAL(timeout()),this,SLOT(slotTimerUpDate()));//关联定时器计满信号和相应的槽函数
       //每隔1ms执行xytimerUpDate()函数
    timer->setInterval(1000);
    timer->start();
}

void ProblemWidget::setData(const Problem &p)
{

    m_UI->textEdit->setText(p.strDescription.toLocal8Bit());
    m_UI->radioButtonA->setText(p.strOptionA);
     m_UI->radioButtonA->setChecked(true);
    m_UI->radioButtonB->setText(p.strOptionB);
    m_UI->radioButtonC->setText(p.strOptionC);
    m_UI->radioButtonD->setText(p.strOptionD);

    if(indexToLabel.find(m_CurrentIndex + 1) != indexToLabel.end())
    {
        updateLabel(m_CurrentIndex + 1, LabelColor::Yellow);
    }
}

void ProblemWidget::setData(const int index, const QString &strDesc,
                            const QString &strOptionA, const QString &strOptionB,
                            const QString &strOptionC, const QString &strOptionD)
{
    m_UI->textEdit->setText(strDesc);
    m_UI->radioButtonA->setText(strOptionA);
    m_UI->radioButtonB->setText(strOptionB);
    m_UI->radioButtonC->setText(strOptionC);
    m_UI->radioButtonD->setText(strOptionD);

    if(indexToLabel.find(m_CurrentIndex + 1) != indexToLabel.end())
    {
        updateLabel(m_CurrentIndex + 1, LabelColor::Yellow);
    }
}

void ProblemWidget::slotClickedPrevious()
{
    vaildAnswer();
    m_CurrentIndex--;

    setData(m_ListProblem.at(m_CurrentIndex));
}

void ProblemWidget::slotClickedNext()
{
    vaildAnswer();
    m_CurrentIndex++;

    if(m_CurrentIndex < m_ListProblem.size())
    {
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
    int answer = 1;
    if(m_UI->radioButtonA->isChecked())
    {
        answer = 1;
    }
    else if(m_UI->radioButtonB->isChecked())
    {
        answer = 2;
    }
    else if(m_UI->radioButtonC->isChecked())
    {
        answer = 3;
    }
    else if(m_UI->radioButtonD->isChecked())
    {
        answer = 4;
    }

    //int returnAnswer = CTYDb::getInstance()->getAnswerByIndex(m_UI->labelIndex->text().toInt());
    int returnAnswer = m_ListProblem.at(m_CurrentIndex).indexAnswer;
    qDebug() << answer <<  "   &&&" << returnAnswer;
    if(answer == returnAnswer)
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
    m_UI->labelRunTime->setText(QString::number(second + 1));
}

void ProblemWidget::setProblems(ListProblem Problems)
{
    m_ListProblem = Problems;
    for(int i = 0; i <m_ListProblem.size(); ++i)
    {
        Problem p = m_ListProblem.at(i);
        qDebug() << "!!!!!!" << p.indexAnswer;
    }
    m_CurrentIndex = 0;
    setData(m_ListProblem.at(m_CurrentIndex));
}
