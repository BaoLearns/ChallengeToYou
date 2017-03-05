#ifndef PROBLEM_H
#define PROBLEM_H
#include <QString>

class Problem
{
public:
    Problem();
    Problem(const int _index, const QString &desc, const QString &optionA, const QString &optionB,
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

typedef QList<Problem> ListProblem;

#endif // PROBLEM_H
