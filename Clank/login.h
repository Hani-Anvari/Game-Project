#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    void set_userName(QString name);
    QString get_userName()const;
    ~Login();

private slots:
    void on_loginPushButton_clicked();

private:
    Ui::Login *ui;
    QString *userName;
};

#endif // LOGIN_H
