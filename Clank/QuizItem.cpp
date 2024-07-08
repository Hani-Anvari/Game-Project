#include "QuizItem.h"

bool QuizItem::Check_answer(QString &answer)
{
    if(answer == correctAnswer)
        return true;
    return false;
}
