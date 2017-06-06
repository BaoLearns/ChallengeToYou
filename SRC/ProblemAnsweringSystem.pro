#-------------------------------------------------
#
# Project created by QtCreator 2017-01-04T20:42:18
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProblemAnsweringSystem
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    LoginWidget.cpp \
    CTYConfig.cpp \
    ProblemWidget.cpp \
    UserWidget.cpp \
    Server.cpp \
    Socket.cpp \
    Client.cpp \
    Log.cpp \
    Problem.cpp \
    CTYThread.cpp \
    CTYDb.cpp \
    QAWidget.cpp \
    TimerWidget.cpp \
    SelectWidget.cpp \
    RegisterWidget.cpp

HEADERS  += mainwindow.h \
    LoginWidget.h \
    CTYConfig.h \
    ProblemWidget.h \
    UserWidget.h \
    Server.h \
    Socket.h \
    Client.h \
    Log.h \
    Problem.h \
    CTYThread.h \
    CTYDb.h \
    QAWidget.h \
    TimerWidget.h \
    SelectWidget.h \
    RegisterWidget.h

RESOURCES += \
    pas.qrc

FORMS += \
    form.ui \
    problem.ui \
    user_from.ui \
    result.ui \
    qa.ui

DISTFILES += \
    resources/qss
