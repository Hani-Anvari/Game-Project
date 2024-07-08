#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "player.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    Player getPlayer()const;
    ~Login();

private slots:
    void on_loginPushButton_clicked();

private:
    Ui::Login *ui;
    Player player;
};

#endif // LOGIN_H
