#include "CTYDb.h"
#include "CTYConfig.h"
#include "Log.h"
#include <QSqlDataBase>
#include <QSqlQuery>
#include <QApplication>
#include <QMessageBox>
#include <QFileInfo>
#include <QSet>
#include <QSetIterator>
#include <iostream>
#include <synchapi.h>
#include <QThread>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <ctime>
#include <QSqlError>

#define QString2string(STRING) std::string(static_cast<const char*>(STRING.toLocal8Bit()))

CTYDb* CTYDb::s_Ins = NULL;
QList<QString> CTYDb::requestMatchContest = QList<QString>();

CTYDb::CTYDb(QObject *parent)
    : strCurrentUserName("")
    , QObject(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(Config::getInstance()->getDBFile());
    db.exec("SET NAMES 'Utf8'");
    if(!db.open())
    {
        Log::writeLog(db.lastError().text());
        qApp->exit();
    }
}

CTYDb::~CTYDb()
{
    db.close();
}

CTYDb* CTYDb::getInstance()
{
    if(s_Ins == NULL)
    {
        s_Ins = new CTYDb();
    }
    return s_Ins;
}

int CTYDb::getAnswerByIndex(int index, int type)
{
    QSqlQuery query;
    QString sql;
    if(type == ProblemType::Select)
    {
        sql = QString("select Answer from SelectProblem where Id=%0").arg(index);
    }
    else if(type == ProblemType::QAndA)
    {
        sql = QString("select Answer from QAndAProblem where Id=%0").arg(index);
    }

    if(!query.exec(sql))
    {
        Log::writeLog(query.lastError().text());
        Log::writeLog("Query Failed. Sotp!");
    }
    while(query.next())
    {
        return query.value(0).toInt();
    }

    Log::writeLog(QString("Not Found index=%0 And type=%1").arg(index).arg(type));
    return -1;
}

bool CTYDb::isVaild(const QString &username, const QString &password)
{
    QSqlQuery query;
    QString sql = QString("select * from User where username=\"%0\" and password=\"%1\"")
            .arg(username).arg(password);

    if(!query.exec(sql))
    {
        Log::writeLog(query.lastError().text());
        Log::writeLog("Query Failed. Sotp!");
    }

    if(query.next())
    {
        strCurrentUserName = username;
        return true;
    }
    else
    {
        return false;
    }
}

bool CTYDb::updateStatus(const QString &username, const QString &status)
{
    strCurrentUserName = username;
    QSqlQuery query;
    QString sql = QString("update User set status=\"%0\" where username=\"%1\"")
            .arg(status).arg(username);

    if(!query.exec(sql))
    {
        Log::writeLog(query.lastError().text());
        Log::writeLog("Query Failed. Sotp!");
    }
    if(query.next())
    {
        return true;
    }
    else
    {
        return false;
    }
}

ListProblemItem CTYDb::getNumProblem(int num)
{
    QSqlQuery query;
    QString sql = QString("select * from Problem");
    //QString sql = QString("select top %0 * from Problem order by newid()").arg(num); //随机选择num条数据
    if(!query.exec(sql))
    {
        Log::writeLog(query.lastError().text());
        Log::writeLog("Query Failed. Sotp!");
    }
    QFile file(Config::getInstance()->getRootPath() + "CTYDb.out");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        Log::writeLog("No Such File");
    }

    ListProblem problems;
    while(query.next())
     {
        int id = query.value(0).toInt();
        int type = query.value(1).toInt();
        int pid = query.value(2).toInt();
        problems.push_back(Problem(id, type, pid));
    }
    ListProblem rtnProblems;
    if(!Shuffle(problems, rtnProblems, num))
    {

    }
    return parseProblems(rtnProblems);
}

QString CTYDb::getCurrentUser()
{
    return strCurrentUserName;
}

int CTYDb::getScoreByUser(const QString &username)
{
    QSqlQuery query;
    QString sql = QString("select * from User where username=\"%0\"").arg(username);
    if(!query.exec(sql))
    {
        Log::writeLog(query.lastError().text());
        Log::writeLog("Query Failed. Sotp!");
    }
    while(query.next())
    {
        int sorce = query.value(4).toInt();
        return sorce;
    }
    return 0;
}

bool CTYDb::MatchOpponent(const QString &username)
{
    if(!requestMatchContest.contains(username))
    {
        requestMatchContest.push_back(username);
    }

    Log::writeLog(QString("Size:") + QString::number(requestMatchContest.size()));
    QSqlQuery query;
    // 更新状态为waitting
    QString sql = QString("update User set Status=\"waitting\" where username=\"%0\"").arg(username);
    if(!query.exec(sql))
    {
        Log::writeLog(query.lastError().text());
        Log::writeLog("Query Failed. Sotp!");
    }

    //for(int times = 0; times < 15; ++times)
    {
        QString firstUser, secondUser;
        if(requestMatchContest.size() >= 2)
        {
            firstUser = requestMatchContest.at(0);
            secondUser = requestMatchContest.at(1);
            requestMatchContest.pop_front();
            requestMatchContest.pop_front();
            QSqlQuery query;
            QString sql = QString("update User set Status=\"waitting\" where username=\"%0\" or username=\"%1\"")
                    .arg(firstUser).arg(secondUser);
            qDebug() << sql;
            if(!query.exec(sql))
            {
                Log::writeLog("Query Failed. Sotp!");
                qApp->exit();
            }

            sql = QString("select * from Result");
            qDebug() << sql;
            if(!query.exec(sql))
            {
                Log::writeLog("Query Failed. Sotp!");
                qApp->exit();
            }
            int size = 1;
            while(query.next())
            {
                size += 1;
            }
            sql = QString("insert into Result values(%0,\"%1\",\"%2\",%3,%4,\"%5\",\"%6\",\"%7\")")
                    .arg(size).arg(firstUser).arg(secondUser).arg(0).arg(0).arg("contesting")
                    .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd"))
                    .arg(QDateTime::currentDateTime().toString("hh:mm:ss.zzz"));

            qDebug() << sql;
            if(!query.exec(sql))
            {
                Log::writeLog("Query Failed. Sotp!");
                qApp->exit();
            }

            qDebug() << "!!!" << firstUser << "    " << secondUser;
            MatchPairs.push_back(MatchPair(size, firstUser, secondUser, 0, 0,getNumProblem()));

            //emit signalMatchSuccess(firstUser);
            emit signalMatchSuccess(secondUser);
            return true;
        }

        //休眠一秒
        Sleep(1000);
    }
    //requestMatchContest.removeOne(username);
    return false;

//    int times = 0;
//    while(true)
//    {
//        times++;
//        if(times > 10)
//        {
////            QMessageBox box();
////            box.setWindowTitle(QStringLiteral("提示："));
////            box.setText(QStringLiteral("暂时没有等待比赛的用户，请稍后重试！"));
////            box.setIcon(QMessageBox::Warning);
////            box.setStandarCTYDbuttons (QMessageBox::Ok);
////            box.setButtonText (QMessageBox::Ok,QString("确定"));
////            box.exec ();
//            emit signalMatchFail(QString::fromLocal8Bit("暂时没有等待比赛的用户，请稍后重试！"));
//            return false;
//        }
//        sql = QString("select * from User where Username!=\"%0\" and Status=\"waitting\"").arg(username);
//        qDebug() << sql;
//        if(!query.exec(sql))
//        {
//            Log::writeLog("Query Failed. Sotp!");
//            qApp->exit();
//        }
//        if(query.next())
//        {
//            int id = query.value(0).toInt();
//            QString strUsername = query.value(1).toString();
//            //更新状态为比赛中
//            sql = QString("update User set Status=\"contesting\" where username=\"%0\"").arg(username);
//            qDebug() << sql;
//            if(!query.exec(sql))
//            {
//                Log::writeLog("Query Failed. Sotp!");
//                qApp->exit();
//            }
//            sql = QString("update User set Status=\"contesting\" where Id=%0").arg(id);
//            qDebug() << sql;
//            if(!query.exec(sql))
//            {
//                Log::writeLog("Query Failed. Sotp!");
//                qApp->exit();
//            }
//            emit signalMatchSuccess(strUsername);
//            return true;
//        }
//        //休眠一秒
//        Sleep(1000);
//        //QThread::sleep (1);
//    }
    return false;
}

bool CTYDb::CancelMatchOpponent(const QString &username)
{
    if(requestMatchContest.contains(username))
    {
        requestMatchContest.removeOne(username);
        updateStatus(username, "online");
        return true;
    }
    return false;
}

bool CTYDb::commitByUser(const QString &username, const int score)
{
    userScoreMap.insert(username, score);
    for(int i = 0; i < MatchPairs.size(); ++i)
    {
        int index = MatchPairs.at(i).index;
        QString first = MatchPairs.at(i).first;
        QString second = MatchPairs.at(i).second;

        if(userScoreMap.value(first, -1) != -1 && userScoreMap.value(second, -1) != -1)
        {
            MatchPairs[i].first_score = userScoreMap.value(first);
            MatchPairs[i].second_score = userScoreMap.value(second);

            QSqlQuery query;
            QString sql = QString("update Result set First_user_score=%0,Second_user_score=%1,Status=\"%2\" where Id=%3")
                    .arg(userScoreMap.value(first)).arg(userScoreMap.value(second)).arg("done")
                    .arg(index);
            qDebug() << sql;
            if(!query.exec(sql))
            {
                Log::writeLog("Query Failed. Sotp!");
                qApp->exit();
            }
            if(MatchPairs.at(i).first_score > MatchPairs.at(i).second_score)
            {
                updateScore(MatchPairs.at(i).first);
            }
            else
            {
                updateScore(MatchPairs.at(i).second);
            }
            userScoreMap.remove(first);
            userScoreMap.remove(second);
            emit signalContestDone();
            MatchPairs.removeAt(i);

        }
    }
    return true;
}


MatchPair CTYDb::getMatchPair(const QString &name)
{
    for(int i = 0; i < MatchPairs.size(); ++i)
    {
        if(MatchPairs.at(i).first == name || MatchPairs.at(i).second == name)
        {
            return MatchPairs.at(i);
        }
    }
}

bool CTYDb::isAlreadyMatch(const QString &username)
{
    for(int i = 0; i < MatchPairs.size(); ++i)
    {
        if(MatchPairs.at(i).first == username || MatchPairs.at(i).second == username)
        {
            return true;
        }
    }
    return false;
}

bool CTYDb::updateScore(const QString &username)
{
    QSqlQuery query;
    QString sql = QString("select Score from User where Username=\"%0\"").arg(username);
    qDebug() << sql;
    if(!query.exec(sql))
    {
        Log::writeLog("Query Failed. Sotp!");
        qApp->exit();
    }
    if(query.next())
    {
        int score = query.value(0).toInt();
        sql = QString("update User set Score=%0 where Username=\"%1\"")
                .arg(score + 1).arg(username);
        qDebug() << sql;
        if(!query.exec(sql))
        {
            Log::writeLog("Query Failed. Sotp!");
            qApp->exit();
        }
        return true;
    }
    return false;
}

bool CTYDb::addNewUser(const QString &username, const QString &password)
{
    QSqlQuery query;
    QString sql = QString("select count(*) from User");
    if(!query.exec(sql))
    {
        Log::writeLog("Query Failed. Sotp!");
        return false;
    }
    int SIZE = 0;
    if(query.next())
    {
        SIZE = query.value(0).toInt();
    }
    sql = QString("insert into User values(%0,\"%1\",\"%2\",\"%3\",%4)").arg(SIZE + 1)
            .arg(username).arg(password).arg("offline").arg(0);
    if(!query.exec(sql))
    {
        Log::writeLog(query.lastError().text());
        Log::writeLog(sql);
        Log::writeLog("Query Failed. Sotp!");
        return false;
    }
    return true;
}

bool CTYDb::updateContestingScore(const QString &username, int score)
{
    QSqlQuery query;
    QString sql = QString("select Id,First_user, Second_user from Result where Status=\"contesting\" and (First_user=\"%0\" or Second_user=\"%1\")")
            .arg(username).arg(username);
    if(!query.exec(sql))
    {
        Log::writeLog(sql);
        Log::writeLog(query.lastError().text());
        Log::writeLog("Query Failed. Sotp!");
        return false;
    }
    if(query.next())
    {
        int id = query.value(0).toInt();
        QString first = query.value(1).toString();
        QString second = query.value(2).toString();
        if(first == username)
        {
            sql = QString("update Result set First_user_score=%0 where Id=%1")
                .arg(score).arg(id);
        }
        else
        {
            sql = QString("update Result set Second_user_score=%0 where Id=%1")
                .arg(score).arg(id);
        }
        if(!query.exec(sql))
        {
            Log::writeLog(sql);
            Log::writeLog(query.lastError().text());
            Log::writeLog("Query Failed. Sotp!");
            return false;
        }
        emit signalUpdateScore(first, second);
        return true;
    }
    return false;
}

int CTYDb::getContestingScore(const QString &username)
{
    QSqlQuery query;
    QString sql = QString("select First_user, Second_user,First_user_score,Second_user_score "
                          "from Result where Status=\"contesting\" and (First_user=\"%0\" or Second_user=\"%1\")")
                           .arg(username).arg(username);
    if(!query.exec(sql))
    {
        Log::writeLog(sql);
        Log::writeLog(query.lastError().text());
        Log::writeLog("Query Failed. Sotp!");
        return 0;
    }
    if(query.next())
    {
        QString first = query.value(0).toString();
        QString second = query.value(1).toString();
        int firstScore = query.value(2).toInt();
        int secondScore = query.value(3).toInt();
        if(first == username)
        {
            return firstScore;
        }
        else
        {
            return secondScore;
        }
    }
    Log::writeLog(sql);
    Log::writeLog("Not Found Username " + username);
    return 0;
}

bool CTYDb::Shuffle(const ListProblem &src, ListProblem &dst, int num)
{
    const unsigned int SIZE = src.size();
    if(num > SIZE)
    {
        Log::writeLog("Not So Many Problmes Are Available. Stop!");
        return false;
    }

    QSet<int> index;
    srand((unsigned)time(NULL));
    const int MIN = 0, MAX = src.size() - 1;

    while(index.size() != num)
    {
        int n = (rand() % (MAX - MIN + 1)) + MIN;
        index.insert(n);
    }
    QSetIterator<int> i(index);
    while (i.hasNext())
    {
        dst.append(src.at(i.next()));
    }
    return true;
}

ListProblemItem CTYDb::parseProblems(const ListProblem &problems)
{
    QSqlQuery query;
    ListProblemItem retItems;
    for(int i = 0; i < problems.size(); ++i)
    {
        Problem problem = problems.at(i);
        if(problem.type == ProblemType::Select)
        {
            QString sql = QString("select * from SelectProblem where Id=%0").arg(problem.pIndex);
            if(!query.exec(sql))
            {
                Log::writeLog(sql);
                Log::writeLog(query.lastError().text());
                return retItems;
            }
            if(query.next())
            {
                int id = query.value(0).toInt();
                QString desc = query.value(1).toString();
                QString optionA = query.value(2).toString();
                QString optionB = query.value(3).toString();
                QString optionC = query.value(4).toString();
                QString optionD = query.value(5).toString();
                int indexAnswer = query.value(6).toInt();
                SelectProblem p(id, desc, optionA, optionB, optionC, optionD, indexAnswer);
                ProblemItem item(problem.index, problem.type, p);
                retItems.push_back(item);
            }
        }
        else
        {
            QString sql = QString("select * from QAndAProblem where Id=%0").arg(problem.pIndex);
            if(!query.exec(sql))
            {
                Log::writeLog(query.lastError().text());
                return retItems;
            }
            if(query.next())
            {
                int id = query.value(0).toInt();
                QString desc = query.value(1).toString();
                QString answer = query.value(3).toString();
                QAProblem p(id, desc, answer);
                ProblemItem item(problem.index, problem.type, p);
                retItems.push_back(item);
            }
        }
    }
    return retItems;

}

bool CTYDb::vaildAnswer(int index, int type, const QString &answer)
{
    QSqlQuery query;
    QString sql;
    if(type == ProblemType::Select)
    {
        sql = QString("select Answer from SelectProblem where Id=%0").arg(index);
    }
    else if(type == ProblemType::QAndA)
    {
        sql = QString("select Answer from QAndAProblem where Id=%0").arg(index);
    }

    if(!query.exec(sql))
    {
        Log::writeLog(query.lastError().text());
        Log::writeLog("Query Failed. Sotp!");
    }
    while(query.next())
    {
        QString retAnswer = query.value(0).toString();
        return answer == retAnswer;
    }

    Log::writeLog(QString("Not Found index=%0 And type=%1").arg(index).arg(type));
    return -1;
}
