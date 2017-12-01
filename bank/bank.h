#ifndef BANK_H
#define BANK_H


#include <QDialog>
#include "chg_pw.h"
#include "user.h"
#include<QMessageBox>
#include <QtSql>
#include <QDebug>
#include <string>
#include <QString>
#include <sstream>

namespace Ui {
class bank;
}

class bank : public QDialog
{
    Q_OBJECT

public:
    explicit bank(QWidget *parent = 0);
    ~bank();

private slots:
    void on_chg_pw_clicked();

    void on_deposit_clicked();

    void on_withdraw_clicked();

    void on_transfer_clicked();

    void on_check_record_clicked();

    void on_back_clicked();

    void rece_userhead(user* uh);


    void on_ok_clicked();

    void on_back_2_clicked();

    void on_back_3_clicked();

    void on_ok_2_clicked();

    void on_ok_save_clicked();

    void on_back_save_clicked();

signals:
    void send_userhead(user* u);

private:
    Ui::bank *ui;
    chg_pw *chg=new chg_pw;
    user *uh1;
};

#endif // BANK_H
