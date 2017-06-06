/********************************************************************************
** Form generated from reading UI file 'user_from.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_FROM_H
#define UI_USER_FROM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserForm
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *pushButtonLogout;
    QLabel *labelTotalScore;
    QPushButton *pushButtonStartOrCancle;
    QLabel *labelOutput;
    QTextEdit *textEditOutput;

    void setupUi(QWidget *UserForm)
    {
        if (UserForm->objectName().isEmpty())
            UserForm->setObjectName(QStringLiteral("UserForm"));
        UserForm->resize(442, 800);
        UserForm->setStyleSheet(QStringLiteral("border:none"));
        widget = new QWidget(UserForm);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(31, 60, 258, 571));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        widget->setFont(font);
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 10);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        pushButtonLogout = new QPushButton(widget);
        pushButtonLogout->setObjectName(QStringLiteral("pushButtonLogout"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        pushButtonLogout->setFont(font1);

        horizontalLayout->addWidget(pushButtonLogout);


        verticalLayout->addLayout(horizontalLayout);

        labelTotalScore = new QLabel(widget);
        labelTotalScore->setObjectName(QStringLiteral("labelTotalScore"));
        labelTotalScore->setFont(font);

        verticalLayout->addWidget(labelTotalScore);

        pushButtonStartOrCancle = new QPushButton(widget);
        pushButtonStartOrCancle->setObjectName(QStringLiteral("pushButtonStartOrCancle"));
        pushButtonStartOrCancle->setFont(font);

        verticalLayout->addWidget(pushButtonStartOrCancle);

        labelOutput = new QLabel(widget);
        labelOutput->setObjectName(QStringLiteral("labelOutput"));
        labelOutput->setFont(font);

        verticalLayout->addWidget(labelOutput);

        textEditOutput = new QTextEdit(widget);
        textEditOutput->setObjectName(QStringLiteral("textEditOutput"));

        verticalLayout->addWidget(textEditOutput);

        textEditOutput->raise();

        retranslateUi(UserForm);

        QMetaObject::connectSlotsByName(UserForm);
    } // setupUi

    void retranslateUi(QWidget *UserForm)
    {
        UserForm->setWindowTitle(QApplication::translate("UserForm", "Form", 0));
        label->setText(QApplication::translate("UserForm", "\346\254\242\350\277\216\357\274\232", 0));
        pushButtonLogout->setText(QApplication::translate("UserForm", "\346\263\250\351\224\200", 0));
        labelTotalScore->setText(QApplication::translate("UserForm", "\345\276\227\345\210\206\346\200\273\350\256\241\357\274\232", 0));
        pushButtonStartOrCancle->setText(QApplication::translate("UserForm", "\346\214\221\346\210\230", 0));
        labelOutput->setText(QApplication::translate("UserForm", "\346\266\210\346\201\257\345\210\227\350\241\250\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class UserForm: public Ui_UserForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_FROM_H
