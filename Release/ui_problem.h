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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButtonA;
    QRadioButton *radioButtonB;
    QRadioButton *radioButtonC;
    QRadioButton *radioButtonD;
    QTextEdit *textEdit;
    QGroupBox *groupBox_2;
    QLabel *labelRunTime;
    QLabel *labelScore;
    QPushButton *pushButtonCommit;
    QPushButton *pushButtonNext;
    QWidget *layoutWidget1;
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

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(684, 800);
        groupBox = new QGroupBox(Form);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 330, 411, 201));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 391, 141));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButtonA = new QRadioButton(layoutWidget);
        radioButtonA->setObjectName(QStringLiteral("radioButtonA"));

        verticalLayout->addWidget(radioButtonA);

        radioButtonB = new QRadioButton(layoutWidget);
        radioButtonB->setObjectName(QStringLiteral("radioButtonB"));

        verticalLayout->addWidget(radioButtonB);

        radioButtonC = new QRadioButton(layoutWidget);
        radioButtonC->setObjectName(QStringLiteral("radioButtonC"));

        verticalLayout->addWidget(radioButtonC);

        radioButtonD = new QRadioButton(layoutWidget);
        radioButtonD->setObjectName(QStringLiteral("radioButtonD"));

        verticalLayout->addWidget(radioButtonD);

        textEdit = new QTextEdit(Form);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(30, 110, 421, 201));
        groupBox_2 = new QGroupBox(Form);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(500, 250, 151, 141));
        labelRunTime = new QLabel(groupBox_2);
        labelRunTime->setObjectName(QStringLiteral("labelRunTime"));
        labelRunTime->setGeometry(QRect(20, 20, 120, 45));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        labelRunTime->setFont(font);
        labelScore = new QLabel(groupBox_2);
        labelScore->setObjectName(QStringLiteral("labelScore"));
        labelScore->setGeometry(QRect(20, 90, 120, 45));
        labelScore->setFont(font);
        pushButtonCommit = new QPushButton(Form);
        pushButtonCommit->setObjectName(QStringLiteral("pushButtonCommit"));
        pushButtonCommit->setGeometry(QRect(480, 620, 75, 23));
        pushButtonNext = new QPushButton(Form);
        pushButtonNext->setObjectName(QStringLiteral("pushButtonNext"));
        pushButtonNext->setGeometry(QRect(370, 620, 75, 23));
        layoutWidget1 = new QWidget(Form);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(21, 41, 641, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_1 = new QLabel(layoutWidget1);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setBaseSize(QSize(60, 60));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(26);
        font1.setBold(true);
        font1.setWeight(75);
        label_1->setFont(font1);
        label_1->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_1);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setBaseSize(QSize(60, 60));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setBaseSize(QSize(60, 60));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setBaseSize(QSize(60, 60));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setBaseSize(QSize(60, 60));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_5);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setBaseSize(QSize(60, 60));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_6);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setBaseSize(QSize(60, 60));
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_7);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setBaseSize(QSize(60, 60));
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_8);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setBaseSize(QSize(60, 60));
        label_9->setFont(font1);
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_9);

        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setBaseSize(QSize(60, 60));
        label_10->setFont(font1);
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_10);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
        groupBox->setTitle(QApplication::translate("Form", "\351\200\211\346\213\251\347\255\224\346\241\210\357\274\232", 0));
        radioButtonA->setText(QApplication::translate("Form", "RadioButton", 0));
        radioButtonB->setText(QApplication::translate("Form", "RadioButton", 0));
        radioButtonC->setText(QApplication::translate("Form", "RadioButton", 0));
        radioButtonD->setText(QApplication::translate("Form", "RadioButton", 0));
        groupBox_2->setTitle(QApplication::translate("Form", "\350\200\227\346\227\266(s)&&\345\276\227\345\210\206", 0));
        labelRunTime->setText(QApplication::translate("Form", "0", 0));
        labelScore->setText(QApplication::translate("Form", "0", 0));
        pushButtonCommit->setText(QApplication::translate("Form", "\346\217\220\344\272\244", 0));
        pushButtonNext->setText(QApplication::translate("Form", ">>", 0));
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
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROBLEM_H
