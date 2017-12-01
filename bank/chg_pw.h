#ifndef CHG_PW_H
#define CHG_PW_H

#include <QDialog>
#include<QMessageBox>
#include <QtSql>
#include <QDebug>
#include <string>
#include <QString>
#include "user.h"

namespace Ui {
class chg_pw;
}

class chg_pw : public QDialog
{
    Q_OBJECT

public:
    explicit chg_pw(QWidget *parent = 0);
    ~chg_pw();

private slots:
    void on_quit_clicked();

    void on_confirm_clicked();

    void rece_userhead(user* uh);

private:
    Ui::chg_pw *ui;
};

#endif // CHG_PW_H
