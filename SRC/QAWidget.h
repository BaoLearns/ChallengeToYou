#ifndef QAWIDGET_H
#define QAWIDGET_H
#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>

class QAWidget : public QWidget
{
public:
    explicit QAWidget(QWidget *parent = NULL);
    void setDesc(const QString &);
    QString getAnswer();
private:
    QTextEdit *textEditDesc;
    QLineEdit *lineEditAnswer;
};

#endif // QAWIDGET_H
