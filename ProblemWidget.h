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
    ProblemWidget(const int id, const QString &strDesc, const QString &strOptionA,
                  const QString &strOptionB, const QString &strOptionC, const QString &strOptionD,
                  bool isFirst = false, bool isLast = false);

    void setData(const Problem &p);
    void setData(const int index, const QString &strDesc, const QString &strOptionA,
                  const QString &strOptionB, const QString &strOptionC, const QString &strOptionD);
    void setProblems(ListProblem Problems);
    bool updateLabel(int index, LabelColor color);
    bool updateProblem();

    void vaildAnswer();
signals:

public slots:
    void slotClickedPrevious();
    void slotClickedNext();
    void slotClickedCommit();
    void slotTimerUpDate();
private:
    void _init();
private:

    Ui_Form *m_UI;
    QMap<int, QLabel*> indexToLabel;

    ListProblem m_ListProblem;
    int m_CurrentIndex;
    static QList<ProblemWidget*> listProblemWidget;

    int nTotal;

    QTimer *timer;
};

#endif // PROBLEMWIDGET_H
