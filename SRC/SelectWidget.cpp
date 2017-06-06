#include "SelectWidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include "Log.h"
#include "CTYConfig.h"

SelectWidget::SelectWidget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(QStringLiteral("单选题"));
    //setFixedSize(480, 527);

    QLabel *labelType = new QLabel("单选题");
    textEditDesc = new QTextEdit();
    //设置垂直滚动条不可见
    textEditDesc->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //设置水平滚动条不可见
    textEditDesc->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    textEditDesc->setFont(Config::getInstance()->getFont());
    optionA = new QRadioButton();
    optionB = new QRadioButton();
    optionC = new QRadioButton();
    optionD = new QRadioButton();
    optionA->setFont(QFont("宋体", 10));
    optionB->setFont(QFont("宋体", 10));
    optionC->setFont(QFont("宋体", 10));
    optionD->setFont(QFont("宋体", 10));

    QVBoxLayout *vLayoutOption = new QVBoxLayout();
    vLayoutOption->addWidget(optionA);
    vLayoutOption->addWidget(optionB);
    vLayoutOption->addWidget(optionC);
    vLayoutOption->addWidget(optionD);
    QGroupBox *boxOption = new QGroupBox(QStringLiteral("选择答案："));
    boxOption->setLayout(vLayoutOption);

    QVBoxLayout *vLayout = new QVBoxLayout(this);
    vLayout->addWidget(labelType);
    vLayout->addWidget(textEditDesc);
    vLayout->addWidget(boxOption);
}

void SelectWidget::setDesc(const QString &desc)
{
    textEditDesc->setText(desc);
}

void SelectWidget::setOptions(const QString &a,
                              const QString &b,
                              const QString &c,
                              const QString &d)
{
    optionA->setText(a);
    optionB->setText(b);
    optionC->setText(c);
    optionD->setText(d);
    optionA->setChecked(true);
}

QString SelectWidget::getOption()
{
    if(optionA->isChecked())
    {
        return "1";
    }
    if(optionB->isChecked())
    {
        return "2";
    }
    if(optionC->isChecked())
    {
        return "3";
    }
    if(optionD->isChecked())
    {
        return "4";
    }
    Log::writeLog("Not Checked Answer.");
    return "-1";
}
