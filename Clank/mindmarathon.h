#ifndef MINDMARATHON_H
#define MINDMARATHON_H

#include "player.h"
#include <QDialog>


namespace Ui {
class MindMarathon;
}

class MindMarathon : public QDialog
{
    Q_OBJECT

public:
    explicit MindMarathon(QWidget *parent = nullptr);
    ~MindMarathon();
    void start(Player& player);

private slots:
    void on_playPushButton_clicked();

    void on_playPushButton_clicked(bool checked);

private:
    Ui::MindMarathon *ui;
};

#endif // MINDMARATHON_H
