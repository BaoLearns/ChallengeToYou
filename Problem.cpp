#include "Problem.h"

Problem::Problem()
{

}

Problem::Problem(const int _index, const QString &desc, const QString &optionA,
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
