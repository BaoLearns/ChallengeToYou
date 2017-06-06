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
        , problems(ListProblemItem())
    {

    }
    MatchPair(const int _index, const QString &_first,
              const QString &_second, const int _first_score, const int _second_score,
              const ListProblemItem &_problems)
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
    ListProblemItem problems;
};
typedef QList<MatchPair> ListMatchPair;

class CTYDb : public QObject
{
    Q_OBJECT
Q_SIGNALS:
    void signalMatchSuccess(const QString &);
    void signalMatchFail(const QString &);
    void signalContestDone();
    void signalUpdateScore(const QString &, const QString &);
public:
    static CTYDb *getInstance();
    bool isVaild(const QString &username, const QString &password);
    bool updateStatus(const QString &username, const QString &status);
    ListProblemItem getNumProblem(int num = 10);

    QString getCurrentUser();
    int getScoreByUser(const QString &username);
    int getAnswerByIndex(int index, int type);
    bool vaildAnswer(int index, int type, const QString &answer);
    bool MatchOpponent(const QString &username);
    bool CancelMatchOpponent(const QString &username);

    bool commitByUser(const QString &username, const int score);

    MatchPair getMatchPair(const QString &name);

    bool isAlreadyMatch(const QString &username);

    bool updateScore(const QString &username);
    bool updateContestingScore(const QString &username, int score);
    int getContestingScore(const QString &username);
    bool addNewUser(const QString &username, const QString &password);

    bool Shuffle(const ListProblem &src, ListProblem &dst, int num);
private:
    ListProblemItem parseProblems(const ListProblem &);
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
