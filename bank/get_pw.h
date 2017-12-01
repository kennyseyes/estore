#ifndef GET_PW_H
#define GET_PW_H

#include <QDialog>
#include <user.h>
#include<QMessageBox>
#include <QtSql>
#include <QDebug>
#include <string>
#include <QString>

namespace Ui {
class get_pw;
}

class get_pw : public QDialog
{
    Q_OBJECT

public:
    explicit get_pw(QWidget *parent = 0);
    ~get_pw();

private slots:
    void on_return_2_clicked();

    void rece_userhead(user* uh);

    void on_ok_clicked();

    void on_get_ques_clicked();

private:
    Ui::get_pw *ui;
};

#endif // GET_PW_H
