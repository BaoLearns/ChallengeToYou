#ifndef CHOICEWIDGET_H
#define CHOICEWIDGET_H
#include <QWidget>
#include <QTextEdit>
#include <QCheckBox>
#include <QRadioButton>

class SelectWidget : public QWidget
{
public:
    explicit SelectWidget(QWidget *parent = NULL);
    void setDesc(const QString &);
    void setOptions(const QString &a,
                             const QString &b,
                             const QString &c,
                             const QString &d);
    QString getOption();
private:
private:
    QTextEdit *textEditDesc;
    QRadioButton *optionA;
    QRadioButton *optionB;
    QRadioButton *optionC;
    QRadioButton *optionD;

};

#endif // CHOICEWIDGET_H
