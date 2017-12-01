#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <user.h>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_return_2_clicked();

    void on_ok_clicked();

private:
    Ui::login *ui;
    user *u=new user;
};

#endif // LOGIN_H
