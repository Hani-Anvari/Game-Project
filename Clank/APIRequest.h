#ifndef APIREQUEST_H
#define APIREQUEST_H
#include "Category.h"
#include "QuizItem.h"
#include <QString>
#include <QVector>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>

class APIRequest
{
public:
    APIRequest();
    void getQuizItems(QVector<QuizItem>& arr, const int& amount, const Category& category, const QString& difficulty);
private:
    static QString token;
    QUrl URL;
    QNetworkAccessManager *manager;
    void onQuizItemsReplyFinished(QNetworkReply *reply, QVector<QuizItem>& quizItems);
    void onTokenReplyFinished(QNetworkReply *reply);
    bool result(int result);
    void session_token();
};

#endif // APIREQUEST_H

//Only 1 Category can be requested per API Call.
//To get questions from any category, don't specify a category.
//A Maximum of 50 Questions can be retrieved per call.
//Session Tokens will be deleted after 6 hours of inactivity. In this program for every new game a new token is used.

// connect(sender, SIGNAL(signal), receiver, SLOT(slot))
