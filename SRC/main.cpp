#include "mainwindow.h"
#include "Server.h"
#include "Client.h"
#include "CTYConfig.h"

#include <QApplication>
#include <QDebug>
#include <cstdio>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::codecForName("UTF-8");

    Log::beginLog();
    // 加载qss
    QFile file(":/resources/qss/coffee.qss");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        Log::writeLog(QString("No Such File %0.").arg("style.qss"));
    }
    else
    {
        a.setStyleSheet(file.readAll());
        file.close();
    }

    // 开启服务器
    const int port = 3333;
    CTYServer server;
    server.Run(port);

//    // 运行客户机
//    CTYClient client1;
//    client1.Run();
//    CTYClient client2;
//    client2.Run();
    int ClientNum = 2;
    for(int i = 0; i < ClientNum; ++i)
    {
        MainWindow *w = new MainWindow;
        w->showMaximized();
    }
    return a.exec();
}
