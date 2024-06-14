#include "APIRequest.h"
#include <QDebug>

QString APIRequest::token = "";
APIRequest::APIRequest()
{
    //URL{"https://opentdb.com/"};
    if(token == "")
        token = session_token();
}

QString APIRequest::session_token()
{
    QString tokenURL = "https://opentdb.com/api_token.php?command=request";
    //request token
    int r;
    if(result(r))
    {
        return "token";
    }
    else
    {
        return "";
    }

}

bool APIRequest::question(QVector<Question>& arr, const int& amount, const Category& category, const QString& difficulty)
{
    QString URL = "https://opentdb.com/api.php?";
    if(0 < amount && amount <= 50)
    {
        URL += "amount=" + amount;
    }
    if(anyCategory != category)
    {
        URL += "category=" + category;
    }
    if("" != difficulty)
    {
        URL += "difficulty" + difficulty;
    }
    //request questions
    int r;
    if(result(r))
    {
        //fill the arr vector
        return true;
    }
    else
    {
        return false;
    }
}

bool result(int r)
{
    switch (r) {
    case 0:
        return true;
    case 1:
        qDebug() << "Amount exceeds available questions.\n";
        //Requested amount: " << amount << "\nAvailable amount: ";
        break;
    case 2:
        qDebug() << "Invalid Parameter!\n";
        //Your API Call: " << tokenURL << '\n'
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        qDebug() << "Rate Limit.\nToo many requests have occurred, Please try later.\n";
        break;
    default:
        qDebug() << "Unknown error occurred.\n";
        break;
    }
    return false;
}
