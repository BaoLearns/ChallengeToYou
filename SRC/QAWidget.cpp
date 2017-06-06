#include "QAWidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QLabel>

QAWidget::QAWidget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(QStringLiteral("问答题"));
    //setFixedSize(480, 527);

    QLabel *lable = new QLabel(QStringLiteral("问答题"));
    textEditDesc = new QTextEdit();
    //设置垂直滚动条不可见
    textEditDesc->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //设置水平滚动条不可见
    textEditDesc->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QFont serifFont("黑体", 11, QFont::Bold);
    textEditDesc->setFont(serifFont);

    lineEditAnswer = new QLineEdit();
    lineEditAnswer->setFont(QFont("宋体", 10));
    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addWidget(lineEditAnswer);
    QGroupBox *boxAns = new QGroupBox("填写答案");
    boxAns->setLayout(hLayout);
    QVBoxLayout *vLayout = new QVBoxLayout(this);
    vLayout->addWidget(lable);
    vLayout->addWidget(textEditDesc);
    vLayout->addWidget(boxAns);
}

void QAWidget::setDesc(const QString &desc)
{
    textEditDesc->setText(desc);
    lineEditAnswer->clear();
}

QString QAWidget::getAnswer()
{
    return lineEditAnswer->text();
}
