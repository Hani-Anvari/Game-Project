#ifndef BATTLEOFBRAINS_H
#define BATTLEOFBRAINS_H

#include "player.h"
#include <QVector>
#include <QDialog>

namespace Ui {
class BattleOfBrains;
}

class BattleOfBrains : public QDialog
{
    Q_OBJECT

public:
    explicit BattleOfBrains(QWidget *parent = nullptr);
    ~BattleOfBrains();
    void start(Player &player);

private:
    QVector <Player> players;
    Ui::BattleOfBrains *ui;
};

#endif // BATTLEOFBRAINS_H
