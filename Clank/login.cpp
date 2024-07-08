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
    delete ui;
}

void Login::on_loginPushButton_clicked()
{
    player.setUserName(ui->loginLineEdit->text());
    hide();
}
Player Login::getPlayer()const
{
    //Check database for players info
    //if found set name and score
    //else add name and set score to 0
    return player;
}
