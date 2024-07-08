#include "battleofbrains.h"
#include "ui_battleofbrains.h"
#include "APIRequest.h"
#include "login.h"

BattleOfBrains::BattleOfBrains(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BattleOfBrains)
{
    ui->setupUi(this);
}

BattleOfBrains::~BattleOfBrains()
{
    delete ui;
}

void BattleOfBrains::start(Player &player)
{
    APIRequest request;
    QStringList categories = { "anyCategory", "General_Knowledge", "Entertainment_Books", "Entertainment_Film", "Entertainment_Music", "Entertainment_Musicals_and_Theatres", "Entertainment_Television", "Entertainment_VideoGames", "Entertainment_BoardGames", "Science_and_Nature", "Science_Computers", "Science_Mathematics", "Mythology", "Sports", "Geography", "History", "Politics", "Art", "Celebrities", "Animals", "Vehicles", "Entertainment_Comics", "Science_Gadgets", "Entertainment_JapaneseAnime_and_Manga", "Entertainment_Cartoon_and_Animations"};
    ui->comboBox->addItems(categories);
    players.push_back(player);
    Login login;
    login.show();
    players.push_back(login.getPlayer());

}
