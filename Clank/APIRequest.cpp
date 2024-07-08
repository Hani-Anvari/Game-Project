#include "APIRequest.h"
#include "Category.h"
#include "QuizItem.h"
#include <QDebug>
#include <QUrl>
#include <QUrlQuery>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

QString APIRequest::token = "";
APIRequest::APIRequest() : manager(new QNetworkAccessManager)
{
    manager = new QNetworkAccessManager();
    if(token == "")
        session_token();
}

void APIRequest::session_token()
{
    QUrl tokenURL("https://opentdb.com/api_token.php?command=request");
    //request token
    QNetworkReply* reply = manager->get(QNetworkRequest(tokenURL));
    //QNetworkAccessManager::connect(reply, SIGNAL(QNetworkAccessManager::finished(reply)), this, SLOT(onTokenReplyFinished(reply)));
}

void APIRequest::onTokenReplyFinished(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        if (jsonDoc.isObject())
        {
            // Extract specific information from the JSON object
            QJsonObject jsonObj = jsonDoc.object();

            // Check for errors
            if(jsonObj.contains("response_code") && jsonObj["response_code"].isDouble())
            {
                if(!result(jsonObj["response_code"].toInt()))
                    return;
                else
                    qDebug() << "Token Generated Successfully!\n";
            }

            //Search for token value
            if(jsonObj.contains("token") && jsonObj["token"].isString())
            {
                token = jsonObj["token"].toString();
                qDebug() << "token: " << token << "\n";
            }
            else
                qDebug() << "Invalid token format in the response.\n";
        }
    } else {
        // Handle error
        qDebug() << "Error:" << reply->errorString();
    }
    reply->deleteLater();
}

void APIRequest::getQuizItems(QVector<QuizItem>& arr, const int& amount, const Category& category, const QString& difficulty)
{
    //example: https://opentdb.com/api.php?amount=5&category=27&difficulty=easy&type=multiple
    URL = QUrl("https://opentdb.com/api.php?") ;
    QUrlQuery url(URL);
    // Creating the URL for HTTP Get
    // DO I NEED TO ADD & INBETWEEN ?
    if(0 < amount && amount <= 50)
        url.addQueryItem("amount", QString::number(amount));
        //QTextStream(&URL) << "amount=" + QString::number(amount); //QString::number() changes int to QString

    if(Category::anyCategory != category)
        url.addQueryItem("category", QString::number(static_cast<int>(category)));
       //URL += "category=" + category;

    if("" != difficulty)
        url.addQueryItem("difficulty", difficulty);

    url.addQueryItem("type", "multiple");

    if("" != token)
        url.addQueryItem("token", token);

    URL.setQuery(url);
    //request questions
    QNetworkReply* reply = manager->get(QNetworkRequest(URL));
    //QNetworkAccessManager::connect(reply, SIGNAL(QNetworkAccessManager::finished(reply)), this, SLOT(onQuizItemsReplyFinished(reply, arr)));
}

void APIRequest::onQuizItemsReplyFinished(QNetworkReply *reply, QVector<QuizItem>& quizItems)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        if (jsonDoc.isObject())
        {
            // Extract specific information from the JSON object
            QJsonObject jsonObj = jsonDoc.object();

            // Check for errors
            if(jsonObj.contains("response_code") && jsonObj["response_code"].isDouble())
            {
                if(!result(jsonObj["response_code"].toInt()))
                    return;
                else
                    qDebug() << "Data Generated Successfully!\n";
            }

            //get quiz items
            if(jsonObj.contains("results") && jsonObj["results"].isArray())
            {
                QJsonArray results = jsonObj["results"].toArray();
                for(const QJsonValue& value : results)
                {
                    QJsonObject itemObj = value.toObject();
                    QuizItem item;
                    item.question = itemObj["question"].toString();
                    item.correctAnswer = itemObj["correct_answer"].toString();
                    QJsonArray incorrectAnswersArr = itemObj["incorrect_answers"].toArray();
                    for(const QJsonValue& incorrectValue : incorrectAnswersArr)
                        item.incorrectAnswers.append(incorrectValue.toString());
                    quizItems.append(item);
                }
                return;
            }
            else
                qDebug() << "Invalid result format in the response.\n";
        }
    } else {
        // Handle error
        qDebug() << "Error:" << reply->errorString();
    }
    reply->deleteLater();
}
bool APIRequest::result(int r)
{
    switch (r) {
    case 0:
        qDebug() << "Success: Returned results successfully.\n";
        return true;
    case 1:
        qDebug() << " No Results: Could not return results. The API doesn't have enough questions for your query. (Ex. Asking for 50 Questions in a Category that only has 20.)\n";
        //Requested amount: " << amount << "\nAvailable amount: ";
        break;
    case 2:
        qDebug() << "Invalid Parameter: Contains an invalid parameter. Arguements passed in aren't valid. (Ex. Amount = Five)\n";
        break;
    case 3:
        qDebug() << "Token not found: Session Token does not exist!\n";
        break;
    case 4:
        qDebug() << "Token Empty: Session Token has returned all possible questions for the specified query. Resetting the Token is necessary.\n";
        break;
    case 5:
        qDebug() << "Rate Limit: Too many requests have occurred. Each IP can only access the API once every 5 seconds.\n";
        break;
    default:
        qDebug() << "Unknown error occurred.\n";
        break;
    }
    return false;
}
