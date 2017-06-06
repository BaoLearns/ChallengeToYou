#include "TimerWidget.h"

#include "Log.h"

TimerWidget* TimerWidget::s_Ins = NULL;

TimerWidget::TimerWidget(QDialog *parent)
    : QDialog(parent)
{
    setWindowFlags(windowFlags()
                   &~Qt::WindowMaximizeButtonHint
                   &~Qt::WindowMinimizeButtonHint
                   &~Qt::WindowCloseButtonHint);
    setFixedSize(300, 400);
    label = new QLabel("0", this);
    label->setFixedSize(200, 300);
    timer = new QTimer();
    timer->setInterval(1000);

    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimeout()));
}
TimerWidget::~TimerWidget()
{

}

TimerWidget* TimerWidget::getInstance()
{
    if(s_Ins == NULL)
    {
        s_Ins = new TimerWidget();
    }
    return s_Ins;
}

void TimerWidget::start(int sec)
{
    seconds = sec;
    timer->setInterval(1000);
    timer->start();
}

void TimerWidget::stop()
{
    timer->stop();
}
void TimerWidget::slotTimeout()
{
    Log::writeLog("timeout");
    int currSec = label->text().toInt();
    if(currSec == seconds)
    {
        QDialog::accepted();
        close();
        return ;
    }
    label->setText(QString::number(currSec + 1));
}
