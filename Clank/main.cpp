#include "mainmenu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainMenu menu;
    menu.show();
    return app.exec();
}

/*
int Player::getChances()const
{
    return chances;
}

bool Player::loseChance()
{
    chances--;
    if(0 == chances)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void resetChances();
*/
