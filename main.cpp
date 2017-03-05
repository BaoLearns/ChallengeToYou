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

    // 加载qss
    QFile file(":/resources/qss/style.qss");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        Log::writeLog("No Such File.");
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
    MainWindow w1;
    w1.showMaximized();
    MainWindow w2;
    w2.showMaximized();
    return a.exec();
}
