#ifndef PROBLEMWIDGET_H
#define PROBLEMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QRadioButton>
#include <QPushButton>
#include "ui_problem.h"
#include "Problem.h"
#include "CTYDb.h"
#include <QTimer>
#include "SelectWidget.h"
#include "QAWidget.h"

enum LabelColor
{
    White,
    Red,
    Green,
    Yellow
};

class ProblemWidget : public QWidget
{
    Q_OBJECT
Q_SIGNALS:
    void signalCommit(int);
public:
    explicit ProblemWidget(QWidget *parent = 0);

    void setData(const ProblemItem &p);
    void setProblems(ListProblemItem Problems);
    bool updateLabel(int index, LabelColor color);
    bool updateProblem();

    void vaildAnswer();
    void setUsername(const QString &username);
    void reset();
signals:

public slots:
    void slotClickedPrevious();
    void slotClickedNext();
    void slotClickedCommit();
    void slotTimerUpDate();
    void slotUpdateScore(const QString &, const QString &);
private:
    void _init();
private:
    Ui_Form *m_UI;
    QMap<int, QLabel*> indexToLabel;

    ListProblemItem m_ListProblem;
    int m_CurrentIndex;
    static QList<ProblemWidget*> listProblemWidget;

    int nTotal;
    QString m_Username;
    QTimer *timer;

    SelectWidget *m_ChoiceWidget;
    QAWidget *m_QAWidget;
};

#endif // PROBLEMWIDGET_H
