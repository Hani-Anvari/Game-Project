#include "player.h"
#include <QString>

Player::Player()
{
    score = 0;
}
Player::~Player()
{
}

void Player::addScore(int& s)
{
    score += s;
}

int Player::getScore()const
{
    return score;
}

void Player::setUserName(QString n)
{
    userName = n;
}
