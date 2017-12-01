#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "bank.h"
#include "reg.h"
#include "get_pw.h"
#include "user.h"
#include<QMessageBox>
#include <QtSql>
#include <QDebug>
#include <string>
#include <QString>



namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

signals:
    void send_userhead(user* u);

private:
    Ui::login *ui;
    reg *r=new reg;
    get_pw *g;
    bank *b = new bank;
    user *uh;
};

#endif // LOGIN_H
