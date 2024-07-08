#ifndef QUIZITEM_H
#define QUIZITEM_H

#include <QString>
#include <QVector>
class QuizItem
{
public:
    QString question;
    QString correctAnswer;
    QVector <QString> incorrectAnswers;
    bool Check_answer(QString &answer);
};

#endif // QUIZITEM_H
