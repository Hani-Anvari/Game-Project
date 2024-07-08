#include "mindmarathon.h"
#include "ui_mindmarathon.h"
#include "APIRequest.h"

MindMarathon::MindMarathon(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MindMarathon)
{
    ui->setupUi(this);
}

MindMarathon::~MindMarathon()
{
    delete ui;
}

void MindMarathon::start(Player &player)
{
    APIRequest request;
    QStringList categories = { "anyCategory", "General_Knowledge", "Entertainment_Books", "Entertainment_Film", "Entertainment_Music", "Entertainment_Musicals_and_Theatres", "Entertainment_Television", "Entertainment_VideoGames", "Entertainment_BoardGames", "Science_and_Nature", "Science_Computers", "Science_Mathematics", "Mythology", "Sports", "Geography", "History", "Politics", "Art", "Celebrities", "Animals", "Vehicles", "Entertainment_Comics", "Science_Gadgets", "Entertainment_JapaneseAnime_and_Manga", "Entertainment_Cartoon_and_Animations"};
    ui->comboBox->addItems(categories);
}
