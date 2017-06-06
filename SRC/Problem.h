#ifndef PROBLEM_H
#define PROBLEM_H
#include <QString>

enum ProblemType
{
    Select = 0,
    QAndA = 1
};

class Problem
{
public:
    Problem();
    Problem(int id, int t, int pid);
    int index;
    int type;
    int pIndex;
};

class SelectProblem
{
public:
    SelectProblem();
    SelectProblem(const int _index, const QString &desc, const QString &optionA, const QString &optionB,
            const QString &optionC, const QString &optionD, int _indexAnswer);
public:
    int index;
    QString strDescription;
    QString strOptionA;
    QString strOptionB;
    QString strOptionC;
    QString strOptionD;
    int indexAnswer;
};

class QAProblem
{
public:
    QAProblem();
    QAProblem(int id, const QString &des, const QString &ans);
    int index;
    QString desc;
    QString answer;
};

class ProblemItem
{
public:
    ProblemItem();
    ProblemItem(int id, int t, const SelectProblem &p);
    ProblemItem(int id, int t, const QAProblem &p);
    int index;
    int type;
    SelectProblem opProblem;
    QAProblem qaProblem;
};

typedef QList<Problem> ListProblem;
typedef QList<ProblemItem> ListProblemItem;

#endif // PROBLEM_H
