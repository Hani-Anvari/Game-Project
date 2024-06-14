#include "mainmenu.h"
#include "./ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    login = new Login(this);
    login->show(); //the main menu should be locked until logged in successfully

  /*QPixmap pix("pic dir");
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRaito));
  */

}

MainMenu::~MainMenu()
{
    delete login, game_mode, ui, ranking;
}

void MainMenu::on_switchPlayerPushButton_clicked()
{
    delete login;
    login = new Login(this);
    login->show();
}


void MainMenu::on_rankingPushButton_clicked()
{
    ranking = new Ranking();
    //select game mode


}

