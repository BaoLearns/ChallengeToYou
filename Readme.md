#毕业设计 Graduation design

基于Qt5开发的问题对抗系统（Challenge To You）--2017年毕业设计。

github 地址：[https://github.com/BaoLearns/ChallengeToYou](https://github.com/BaoLearns/ChallengeToYou)

运行环境：Windows/Linux/OS + Qt5 + SQLITE3

网络通信协议：TCP协议

###使用步骤：

>运行Release下的ChallengeToYou.exe

>现在有两个客户端在运行，可假设一个为A客户端另一个为B客户端，在A中输入用户密码（账号：admin 密码：admin）,在B中输入用户密码（账号：royecode 密码royecode）

>进入用户模式，分别点击挑战（客户端会提交请求给服务器）

>等待服务器给客户端的答复，A、B客户端各自开始答题，并提交答案

>服务器会评判两人的答题结果并在消息列表中给出信息


文件结构：

```
├── ChallengeToYou.pro
├── ChallengeToYou.pro.user
├── Client.cpp
├── Client.h
├── CTYConfig.cpp
├── CTYConfig.h
├── CTYDb.cpp
├── CTYDb.h
├── cty.qrc
├── cty.sqlite
├── cty.sqlite3
├── CTYThread.cpp
├── CTYThread.h
├── form.ui
├── Log.cpp
├── Log.h
├── LoginWidget.cpp
├── LoginWidget.h
├── log.txt
├── main.cpp
├── mainwindow.cpp
├── mainwindow.h
├── Problem.cpp
├── Problem.h
├── problem.ui
├── ProblemWidget.cpp
├── ProblemWidget.h
├── Readme.md
├── release
│   ├── ChallengeToYou.exe
│   ├── Client.o
│   ├── CTYConfig.o
│   ├── CTYDb.o
│   ├── CTYThread.o
│   ├── LoginWidget.o
│   ├── Log.o
│   ├── main.o
│   ├── mainwindow.o
│   ├── moc_Client.cpp
│   ├── moc_Client.o
│   ├── moc_CTYDb.cpp
│   ├── moc_CTYDb.o
│   ├── moc_CTYThread.cpp
│   ├── moc_CTYThread.o
│   ├── moc_LoginWidget.cpp
│   ├── moc_LoginWidget.o
│   ├── moc_mainwindow.cpp
│   ├── moc_mainwindow.o
│   ├── moc_ProblemWidget.cpp
│   ├── moc_ProblemWidget.o
│   ├── moc_Server.cpp
│   ├── moc_Server.o
│   ├── moc_Socket.cpp
│   ├── moc_Socket.o
│   ├── moc_UserWidget.cpp
│   ├── moc_UserWidget.o
│   ├── Problem.o
│   ├── ProblemWidget.o
│   ├── qrc_cty.cpp
│   ├── qrc_cty.o
│   ├── Server.o
│   ├── Socket.o
│   └── UserWidget.o
├── resources
│   ├── image
│   │   ├── background.jpg
│   │   ├── icon1.ico
│   │   └── icon.ico
│   └── qss
│       └── style.qss
├── result.ui
├── Server.cpp
├── Server.h
├── Socket.cpp
├── Socket.h
├── user_from.ui
├── UserWidget.cpp
└── UserWidget.h
```

###关于数据库

使用SQLITE3数据库，这种数据库的特点是数据存储在文件中，使用方便。

数据库文件cty.sqlite中有3张表，结构如下：

Problem(Id, Desctiption, OptionA, OptionB, OptionC, OptionD, Index, Answer, Create_date)

User(Id, Username, Password, Status, Score)

Result(Id, First_user, Second_user, First_user_score, Second_user_score, Status, Create_date, Create_time)

特别解释：

1.Problem表中Answer是四个选型答案的索引，即值的范围是[1，4]

2.User表中的Status有四中状态（offline：离线, online：在线, watting：等待匹配比赛, contesting：正在比赛）

3.Resul表中Status有两种状态（contesting：正在比赛， done：比赛结束）

###系统待完成列表

>调整界面的美观

>分离客户机、服务器
 
###Lisense

任何人都可以免费使用学习，免费传播。

###与我联系

如果你有任何问题，请用Email联系我： Royecode@163.com
