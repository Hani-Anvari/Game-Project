#ifndef APIREQUEST_H
#define APIREQUEST_H
#include "Category.h"
#include "Question.h"
#include <QString>
#include <QVector>

class APIRequest
{
public:
    APIRequest();
    bool question(QVector<Question>& arr, const int& amount, const Category& category, const QString& difficulty);
    QString session_token();
private:
    static QString token;
    bool result(int result);
};

#endif // APIREQUEST_H

//Only 1 Category can be requested per API Call.
//To get questions from any category, don't specify a category.
//A Maximum of 50 Questions can be retrieved per call.
//Session Tokens will be deleted after 6 hours of inactivity. In this program for every new game a new token is used.
