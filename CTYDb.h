#ifndef CTYDb_H
#define CTYDb_H

#include <QObject>
#include <QSqlDatabase>
#include "Problem.h"
#include <QList>
#include <QMap>

struct MatchPair
{
    MatchPair()
        : index(0)
        , first("")
        , second("")
        , first_score(0)
        , second_score(0)
        , problems(ListProblem())
    {

    }
    MatchPair(const int _index, const QString &_first,
              const QString &_second, const int _first_score, const int _second_score,
              const ListProblem &_problems)
        : index(_index)
        , first(_first)
        , second(_second)
        , first_score(_first_score)
        , second_score(_second_score)
        , problems(_problems)
    {

    }

    int index;
    QString first;
    QString second;
    int first_score;
    int second_score;
    ListProblem problems;
};
typedef QList<MatchPair> ListMatchPair;

class CTYDb : public QObject
{
    Q_OBJECT
Q_SIGNALS:
    void signalMatchSuccess(const QString &);
    void signalMatchFail(const QString &);
    void signalContestDone();
public:
    static CTYDb *getInstance();
    bool isVaild(const QString &username, const QString &password);
    bool updateStatus(const QString &username, const QString &status);
    ListProblem getNumProblem(int num = 10);

    QString getCurrentUser();
    int getScoreByUser(const QString &username);
    int getAnswerByIndex(int index);

    bool MatchOpponent(const QString &username);

    bool commitByUser(const QString &username, const int score);

    MatchPair getMatchPair(const QString &name);

    bool isAlreadyMatch(const QString &username);

    bool updateScore(const QString &username);
public:
    CTYDb(QObject *parent = NULL);
    ~CTYDb();
private:
    static CTYDb *s_Ins;
    QSqlDatabase db;

    QString strCurrentUserName;
    static QList<QString> requestMatchContest;

    ListMatchPair MatchPairs;
    QMap<QString, int> userScoreMap;
};
#endif // CTYDb_H
