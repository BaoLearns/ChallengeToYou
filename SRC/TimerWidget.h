#ifndef TIMERWIDGET_H
#define TIMERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QDialog>
#include <QTimer>

class TimerWidget : public QDialog
{
    //Q_OBJECT
Q_SIGNALS:
public:
    explicit TimerWidget(QDialog *parent = NULL);
    ~TimerWidget();
    static TimerWidget* getInstance();
    void start(int sec);
    void stop();
private slots:
    void slotTimeout();
private:
    static TimerWidget *s_Ins;
    QLabel *label;
    QTimer *timer;
    int seconds;
};

#endif // TIMERWIDGET_H
