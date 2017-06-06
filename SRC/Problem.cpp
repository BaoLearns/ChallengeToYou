#include "Problem.h"

Problem::Problem()
{

}
Problem::Problem(int id, int t, int pid)
    : index(id)
    , type(t)
    , pIndex(pid)
{

}

SelectProblem::SelectProblem()
{

}

SelectProblem::SelectProblem(const int _index, const QString &desc, const QString &optionA,
                 const QString &optionB, const QString &optionC,
                 const QString &optionD, int _indexAnswer)
    : index(_index)
    , strDescription(desc)
    , strOptionA(optionA)
    , strOptionB(optionB)
    , strOptionC(optionC)
    , strOptionD(optionD)
    , indexAnswer(_indexAnswer)
{

}

QAProblem::QAProblem()
{

}

QAProblem::QAProblem(int id, const QString &des, const QString &ans)
    : index(id)
    , desc(des)
    , answer(ans)
{

}

ProblemItem::ProblemItem()
{

}

ProblemItem::ProblemItem(int id, int t, const SelectProblem &p)
    : index(id)
    , type(t)
    , opProblem(p)
{

}

ProblemItem::ProblemItem(int id, int t, const QAProblem &p)
    : index(id)
    , type(t)
    , qaProblem(p)
{

}
