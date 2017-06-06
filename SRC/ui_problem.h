/********************************************************************************
** Form generated from reading UI file 'problem.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROBLEM_H
#define UI_PROBLEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QLabel *labelRunTime;
    QLabel *labelScore;
    QLabel *labelRunTime_2;
    QLabel *labelRunTime_3;
    QLabel *labelRunTime_4;
    QLabel *labelOpponentScore;
    QPushButton *pushButtonNext;
    QPushButton *pushButtonCommit;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(880, 800);
        layoutWidget = new QWidget(Form);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(110, 41, 771, 71));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_1 = new QLabel(layoutWidget);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setBaseSize(QSize(60, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(26);
        font.setBold(true);
        font.setWeight(75);
        label_1->setFont(font);
        label_1->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setBaseSize(QSize(60, 60));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setBaseSize(QSize(60, 60));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setBaseSize(QSize(60, 60));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setBaseSize(QSize(60, 60));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_5);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setBaseSize(QSize(60, 60));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_6);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setBaseSize(QSize(60, 60));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_7);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setBaseSize(QSize(60, 60));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_8);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setBaseSize(QSize(60, 60));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_9);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setBaseSize(QSize(60, 60));
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_10);

        stackedWidget = new QStackedWidget(Form);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(110, 149, 521, 521));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        groupBox = new QGroupBox(Form);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(640, 150, 241, 526));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 60, 201, 211));
        labelRunTime = new QLabel(groupBox_2);
        labelRunTime->setObjectName(QStringLiteral("labelRunTime"));
        labelRunTime->setGeometry(QRect(120, 20, 70, 45));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        labelRunTime->setFont(font1);
        labelScore = new QLabel(groupBox_2);
        labelScore->setObjectName(QStringLiteral("labelScore"));
        labelScore->setGeometry(QRect(120, 90, 70, 45));
        labelScore->setFont(font1);
        labelRunTime_2 = new QLabel(groupBox_2);
        labelRunTime_2->setObjectName(QStringLiteral("labelRunTime_2"));
        labelRunTime_2->setGeometry(QRect(10, 20, 51, 45));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        labelRunTime_2->setFont(font2);
        labelRunTime_3 = new QLabel(groupBox_2);
        labelRunTime_3->setObjectName(QStringLiteral("labelRunTime_3"));
        labelRunTime_3->setGeometry(QRect(10, 90, 51, 45));
        labelRunTime_3->setFont(font2);
        labelRunTime_4 = new QLabel(groupBox_2);
        labelRunTime_4->setObjectName(QStringLiteral("labelRunTime_4"));
        labelRunTime_4->setGeometry(QRect(10, 150, 101, 45));
        labelRunTime_4->setFont(font2);
        labelOpponentScore = new QLabel(groupBox_2);
        labelOpponentScore->setObjectName(QStringLiteral("labelOpponentScore"));
        labelOpponentScore->setGeometry(QRect(120, 150, 70, 45));
        labelOpponentScore->setFont(font1);
        pushButtonNext = new QPushButton(groupBox);
        pushButtonNext->setObjectName(QStringLiteral("pushButtonNext"));
        pushButtonNext->setGeometry(QRect(20, 440, 75, 23));
        pushButtonCommit = new QPushButton(groupBox);
        pushButtonCommit->setObjectName(QStringLiteral("pushButtonCommit"));
        pushButtonCommit->setGeometry(QRect(120, 440, 75, 23));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
        label_1->setText(QApplication::translate("Form", "1", 0));
        label_2->setText(QApplication::translate("Form", "2", 0));
        label_3->setText(QApplication::translate("Form", "3", 0));
        label_4->setText(QApplication::translate("Form", "4", 0));
        label_5->setText(QApplication::translate("Form", "5", 0));
        label_6->setText(QApplication::translate("Form", "6", 0));
        label_7->setText(QApplication::translate("Form", "7", 0));
        label_8->setText(QApplication::translate("Form", "8", 0));
        label_9->setText(QApplication::translate("Form", "9", 0));
        label_10->setText(QApplication::translate("Form", "10", 0));
        groupBox->setTitle(QString());
        groupBox_2->setTitle(QApplication::translate("Form", "\345\257\271\346\210\230\347\212\266\346\200\201", 0));
        labelRunTime->setText(QApplication::translate("Form", "0", 0));
        labelScore->setText(QApplication::translate("Form", "0", 0));
        labelRunTime_2->setText(QApplication::translate("Form", "\346\227\266\351\227\264\357\274\232", 0));
        labelRunTime_3->setText(QApplication::translate("Form", "\345\276\227\345\210\206\357\274\232", 0));
        labelRunTime_4->setText(QApplication::translate("Form", "\345\257\271\346\211\213\345\276\227\345\210\206\357\274\232", 0));
        labelOpponentScore->setText(QApplication::translate("Form", "0", 0));
        pushButtonNext->setText(QApplication::translate("Form", ">>", 0));
        pushButtonCommit->setText(QApplication::translate("Form", "\346\217\220\344\272\244", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROBLEM_H
