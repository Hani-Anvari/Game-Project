#ifndef MAINMENU_H
#define MAINMENU_H

#include "ranking.h"
#include "login.h"
#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainMenu;
}
QT_END_NAMESPACE

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:

    void on_switchPlayerPushButton_clicked();

    void on_rankingPushButton_clicked();

    void on_quitPushButton_clicked();

    void on_startPushButton_clicked();

private:
    Ui::MainMenu *ui;
    Login *login;
    Ranking *ranking;
    QString *game_mode;
    Player *host;
};
#endif // MAINMENU_H
