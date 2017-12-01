#include "get_pw.h"
#include "ui_get_pw.h"

user *uh3=NULL;

get_pw::get_pw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::get_pw)
{
    ui->setupUi(this);
    connect(ui->return_2,SIGNAL(clicked(bool)),this,SLOT(close()));
}

get_pw::~get_pw()
{
    delete ui;
}

void get_pw::rece_userhead(user *uh){
    uh3=uh;
}

void get_pw::on_return_2_clicked()
{
    accept();
}

void get_pw::on_ok_clicked()
{
    QString cd = ui->card->text();
    QString ansr = ui->ans->text();

    QSqlQuery query;
    query.exec(QString("select * from bank where card_no=%1").arg(cd));
    if(query.first())
    {
        QString ans1 = query.value("answer").toString();
        QString pw = query.value("passwd").toString();
        if(ans1!=ansr)
            QMessageBox::warning(NULL,"错误","问题回答错误",QMessageBox::Ok);
        else
        {
            QMessageBox msg;
            QString s = QString("您的密码为：%1").arg(pw);
            msg.setText(s);
            msg.addButton("记住了",QMessageBox::AcceptRole);

            if(msg.exec()==QMessageBox:: AcceptRole)
                this->close();
        }
    }
    else
        QMessageBox::warning(NULL,"wrong","未找到用户",QMessageBox::Ok);
}

void get_pw::on_get_ques_clicked()
{
    QString cd = ui->card->text();
    QSqlQuery query;
    query.exec(QString("select * from bank where card_no=%1").arg(cd));
    if(query.first())
    {
        QString ques = query.value("question").toString();
        ui->ques->setText(ques);
    }
}
