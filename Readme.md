#毕业设计 Graduation design

	基于C++/Qt开发的桌面应用程序--问题对答系统（Problem Answering System）

设计者：鲍黎 	 	

指导老师：陈庆利教授

###背景

为了营造一个健康、快乐的互联网生活环境，增加人们生活的乐趣，锻炼人们的思维，开发此问题对抗系统（Problem Answering System）。

此系统中，两两配对用户可在线回答等量同等问题，系统会及时反馈某一问题回答是否正确，待两人提交了最后的答案，系统会反馈两人之间的对抗结果，谁得分更高。

用户可向本系统添加题目，丰富系统的题库，使用起来越来越有趣。


###运行环境&步骤：

Qt是优秀的跨平台C++图形用户界面应用程序开发框架，官网[https://www.qt.io/](https://www.qt.io/)。

项目github 地址：[https://github.com/BaoLearns/ChallengeToYou](https://github.com/BaoLearns/ChallengeToYou)

运行环境：Windows/Linux/OS X + Qt5 + SQLITE3

网络通信协议：TCP协议族

1. 运行Release文件夹下的ProblemAnsweringSystem.exe

1. 现在有两个客户端在运行，可假设一个为A客户端，另一个为B客户端。在A中输入账号密码（账号：admin 密码：admin）,在B中输入账号密码（账号：royecode 密码royecode）。或者注册两个新账号登录系统。
  
1. 进入用户模式，分别点击“发起挑战”（客户端会提交请求给服务器）
 
1. 等待服务器给客户端的答复，A、B客户端各自开始答题，并提交答案
 
1. 服务器会评判两人的对抗结果并在消息列表中给出结果信息


*文件结构：*


    │  Client.cpp
    │  Client.h
    │  CTYConfig.cpp
    │  CTYConfig.h
    │  CTYDb.cpp
    │  CTYDb.h
    │  CTYThread.cpp
    │  CTYThread.h
    │  Log.cpp
    │  Log.h
    │  LoginWidget.cpp
    │  LoginWidget.h
    │  main.cpp
    │  mainwindow.cpp
    │  mainwindow.h
    │  Problem.cpp
    │  Problem.h
    │  ProblemWidget.cpp
    │  ProblemWidget.h
    │  QAWidget.cpp
    │  QAWidget.h
    │  RegisterWidget.cpp
    │  RegisterWidget.h
    │  SelectWidget.cpp
    │  SelectWidget.h
    │  Server.cpp
    │  Server.h
    │  Socket.cpp
    │  Socket.h
    │  TimerWidget.cpp
    │  TimerWidget.h
    │  UserWidget.cpp
    │  UserWidget.h
    │  config.xml
    │  log.txt
    │  pas.sqlite
    │  ProblemAnsweringSystem.exe
    └─resources
    ├─image
    │  background.jpg
    │  background2.jpg
    │  background3.jpg
    │  icon.ico
    │  icon1.ico
    │  
    └─qss
    style.qss
    

###软件架构
![软件架构图](http://wx1.sinaimg.cn/mw690/006DBlWAly1ffk48jg9p9j30cq0e1dft.jpg)
###TCP通信
![SOCKET通信图](http://my.csdn.net/uploads/201204/10/1334044170_5136.jpg)
###匹配规则

系统维护一个用户请求对战队列Queue，当有新请求到达时放到队列尾端，如果队列大小大于等于2，则取出前两个进行对战，匹配规则即：

**先到达优先匹配（First In, First Match）对战**

###关于数据库

使用SQLITE3数据库，这种数据库的特点是数据存储在本地文件中，使用简单方便。

数据库文件pas.sqlite中有5张表，结构如下：

Problem(Id, Type, PId)

SelectProblem(Id, Description, OptionA, OptionB, OptionC, OptionD, Index, Answer, Create_date) 

QAndAProblem(Id, Description, Answer, Create_date)

User(Id, Username, Password, Status, Score)

Result(Id, First_user, Second_user, First_user_score, Second_user_score, Status, Create_date, Create_time)

*特别解释*：

1.Problem表的PId是问题表的关联Id，Type是题目类型,可选数值0:SelectProblem, 1:QAndAProblem

2.SelectProblem表中Answer是四个选型答案的索引，即值的范围是[1，4]

3.User表中的Status有四中状态（offline：离线, online：在线, waiting：等待匹配比赛, contesting：正在比赛）

4.Resul表中Status有两种状态（contesting：正在比赛， done：比赛结束）

###关于答题颜色

>**绿色**：回答正确

>**红色**：回答错误

>**黄色**：正在解答

###关于积分规则

评判两人对抗结果：

1)假设用户A得分、耗时分别为SA、TA，用户B得分、耗时分别为SB、TB

2)如果SA不等于SB，则得MAX(SA,SB)分数的用户胜，算法完成；否则执行第3歩

3)如果TA不等于TB，则耗MIN(TA,TB)分数的用户胜，算法完成；否则执行第4歩

4)无法判别对战结果，没有胜者也没有输者，算法完成


###系统待完成列表

> 好友信息管理
 
> 增加题型（图片识别、声音识别等）
###Lisense

任何人都可以免费使用学习，免费传播。

###与我联系

如果你有任何问题，请用Email联系我： lbaocode@gmail.com
