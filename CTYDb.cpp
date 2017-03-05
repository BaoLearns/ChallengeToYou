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
        Log::writeLog(QString("Database Error Stop!"));
        qApp->exit();
    }
}

CTYDb::~CTYDb()
{
    db.close();
}

int CTYDb::getAnswerByIndex(int index)
{
    QSqlQuery query;
    QString sql = QString("select Answer from Problem where Id=%0").arg(index);
    qDebug() << sql;
    if(!query.exec(sql))
    {
        Log::writeLog("Query Failed. Sotp!");
        qApp->exit();
    }
    while(query.next())
     {
              return query.value(0).toInt();
    }
    return -1;
}



CTYDb* CTYDb::getInstance()
{
    if(s_Ins == NULL)
    {
        s_Ins = new CTYDb();
    }
    return s_Ins;
}

bool CTYDb::isVaild(const QString &username, const QString &password)
{
    QSqlQuery query;
    QString sql = QString("select * from User where username=\"%0\" and password=\"%1\"")
            .arg(username).arg(password);
    qDebug() << sql;
    if(!query.exec(sql))
    {
        Log::writeLog("Query Failed. Sotp!");
        qApp->exit();
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
    qDebug() << sql;
    if(!query.exec(sql))
    {
        Log::writeLog("Query Failed. Sotp!");
        qApp->exit();
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

ListProblem CTYDb::getNumProblem(int num)
{
    QSqlQuery query;
    QString sql = QString("select * from Problem");
    //QString sql = QString("select top %0 * from Problem order by newid()").arg(num); //随机选择num条数据
    qDebug() << sql;
    if(!query.exec(sql))
    {
        Log::writeLog("Query Failed. Sotp!");
        qApp->exit();
    }
    QFile file(Config::getInstance()->getRootPath() + "CTYDb.out");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        Log::writeLog("No Such File");
    }
    ListProblem problems;
    while(query.next())
     {
        //QStringLiteral str = QString("sdffds").toLocal8Bit();
              int id = query.value(0).toInt();
              QString desc = query.value(1).toString();
              QString optionA = query.value(2).toString();
              QString optionB = query.value(3).toString();
              QString optionC = query.value(4).toString();
              QString optionD = query.value(5).toString();
              int indexAnswer = query.value(6).toInt();
              problems.push_back(Problem(id, desc, optionA, optionB, optionC, optionD, indexAnswer));
    }
   //return problems;
    ListProblem rtnProblems;
    const unsigned int SIZE = problems.size();
    if(num > SIZE)
    {
        Log::writeLog("Not So Many Problmes Are Available. Stop!");
        qApp->exit();
    }
    QSet<int> index;
    while(index.size() != num)
    {
        int n = rand() % SIZE;
        index.insert(n);
    }
    QSetIterator<int> i(index);
    while (i.hasNext())
    {
            rtnProblems.append(problems.at(i.next()));
    }
    return rtnProblems;
}

QString CTYDb::getCurrentUser()
{
    return strCurrentUserName;
}

int CTYDb::getScoreByUser(const QString &username)
{
    QSqlQuery query;
    QString sql = QString("select * from User where username=\"%0\"").arg(username);
    qDebug() << sql;
    if(!query.exec(sql))
    {
        Log::writeLog("Query Failed. Sotp!");
        qApp->exit();
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
    // 更新状态为watting
    QString sql = QString("update User set Status=\"watting\" where username=\"%0\"").arg(username);
    qDebug() << sql;
    if(!query.exec(sql))
    {
        Log::writeLog("Query Failed. Sotp!");
        qApp->exit();
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
            QString sql = QString("update User set Status=\"watting\" where username=\"%0\" or username=\"%1\"")
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
//        sql = QString("select * from User where Username!=\"%0\" and Status=\"watting\"").arg(username);
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
