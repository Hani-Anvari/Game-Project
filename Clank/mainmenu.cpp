#include "mainmenu.h"
#include "./ui_mainmenu.h"
#include <QMessageBox>
#include "mindmarathon.h"
#include "battleofbrains.h"

MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    login = new Login(this);
    login->show(); //the main menu should be locked until logged in successfully
    host = new Player;
    *host = login->getPlayer();
}

MainMenu::~MainMenu()
{
    delete login, game_mode, ui, ranking;
}

void MainMenu::on_switchPlayerPushButton_clicked()
{
    delete login, host;
    login = new Login(this);
    login->show();
    host = new Player;
    *host = login->getPlayer();
}


void MainMenu::on_rankingPushButton_clicked()
{
    ranking = new Ranking();
    //ranking->setHost(host);
    ranking->show();
}

/*QPixmap pix("pic dir");
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRaito));
  */

void MainMenu::on_quitPushButton_clicked()
{
    //connect(_quit, SIGNAL(clicked()), this, SLOT(quit()));
}


void MainMenu::on_startPushButton_clicked()
{
    QMessageBox game_mode;
    game_mode.setWindowTitle("Game Mode");
    game_mode.setText("Choose Game Mode");
    QAbstractButton* pButtonYes = game_mode.addButton("Mind Marathon", QMessageBox::NoRole);
    game_mode.addButton("Battle of Brains", QMessageBox::NoRole);

    int result = game_mode.exec();
    if (game_mode.clickedButton() == pButtonYes) {
        MindMarathon game;
        game.start(*host);
        game.show(); //window closes??
        hide();
    } else {
        BattleOfBrains game;
        game.start(*host);
        game.show(); //window closes??
        hide();
    }
}

