/********************************************************************************
** Form generated from reading UI file 'qa.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QA_H
#define UI_QA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QTextEdit *textEditDesc;
    QGroupBox *groupBox;
    QLineEdit *lineEditAnswer;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(569, 300);
        textEditDesc = new QTextEdit(Form);
        textEditDesc->setObjectName(QStringLiteral("textEditDesc"));
        textEditDesc->setGeometry(QRect(30, 20, 501, 151));
        groupBox = new QGroupBox(Form);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 180, 501, 51));
        lineEditAnswer = new QLineEdit(groupBox);
        lineEditAnswer->setObjectName(QStringLiteral("lineEditAnswer"));
        lineEditAnswer->setGeometry(QRect(10, 20, 481, 20));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
        groupBox->setTitle(QApplication::translate("Form", "\345\241\253\345\206\231\347\255\224\346\241\210", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QA_H
