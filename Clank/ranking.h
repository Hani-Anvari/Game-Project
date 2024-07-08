#ifndef RANKING_H
#define RANKING_H

#include <QDialog>
#include <QVector>

namespace Ui {
class Ranking;
}

class Ranking : public QDialog
{
    Q_OBJECT

public:
    explicit Ranking(QWidget *parent = nullptr);
    load();
    sort();
    void display();
    ~Ranking();

private:
    Ui::Ranking *ui;
    //QVector<Player> players;

};

#endif // RANKING_H
