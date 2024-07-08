#ifndef PLAYER_H
#define PLAYER_H

#include"QString"

class Player
{
public:
    Player();
    void addScore(int& s);
    int getScore()const;
    void setUserName(QString n);
    ~Player();
private:
    QString userName;
    int score;
};

#endif // PLAYER_H
