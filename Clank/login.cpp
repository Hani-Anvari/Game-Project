#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete userName;
    delete ui;
}

void Login::on_loginPushButton_clicked()
{
    set_userName(ui->loginLineEdit->text());
    //Check database for players info
    //if found set name and score
    //else add name and set score to 0
    hide();
}

void set_userName(QString name)
{
    userName = new QString();
    userName = name;
}

QString get_userName()const
{
    return userName;
}
