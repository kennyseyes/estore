#include "login.h"
#include "ui_login.h"
#include "user.h"

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    setFixedSize(this->width(),this->height());
}

login::~login()
{
    delete ui;
}


void login::on_pushButton_clicked()
{
    QSqlQuery query;
    uh=new user;
    //debug
    query.exec("select * from bank");

    QString input_username=ui->username->text();
    QString input_password=ui->password->text();

     query.exec("SELECT * FROM bank");
    //载入数据库失败
    if(!query.first()){
        QMessageBox::warning(NULL, "Error", "Unable to find \"bank\"!", QMessageBox::Ok);
    }

    query.exec(QString("SELECT card_no FROM bank WHERE card_no=%1").arg(input_username));

    //不存在用户
    if(!query.first()){
        QMessageBox::warning(NULL, "Error", "Can't find user.", QMessageBox::Ok);
    }

    //密码错误
    else {
        query.exec(QString("SELECT card_no,passwd FROM bank WHERE card_no=%1 AND passwd=%2").arg(input_username).arg(input_password));

        if(!query.first()){
            QMessageBox::warning(NULL, "Error", "Incorrect password. Please try again.", QMessageBox::Ok);
        }

        //登录成功
        else{
            query.exec(QString("SELECT * FROM bank WHERE card_no=%1").arg(input_username));
            if(query.first())
            {
                uh->set_name(query.value("name").toString().toStdString());
                uh->set_id(query.value("id").toString().toStdString());
                uh->set_pw(query.value("passwd").toString().toStdString());
                uh->set_bknm(query.value("bank_name").toString().toStdString());
                uh->set_ques(query.value("question").toString().toStdString());
                uh->set_ans(query.value("answer").toString().toStdString());
                uh->set_money(query.value("money").toFloat());
                uh->set_log(query.value("log").toString().toStdString());
                uh->set_phone(query.value("phone").toString().toStdString());
                uh->set_card_no(query.value("card_no").toString().toStdString());

                connect(this,SIGNAL(send_userhead(user *)),b,SLOT(rece_userhead(user *)));
                emit(send_userhead(uh));

                QMessageBox::about(NULL, "成功", "登录成功");

                b->show();
                this->hide();
                if(b->exec())
                    this->show();
            }
            //数据库出错
            else
            {
                QMessageBox::warning(NULL,"Oops..","数据库出了些问题...",QMessageBox::Ok);
                this->close();
            }


        }
    }
}

void login::on_pushButton_2_clicked()
{
    r->show();
    this->hide();
    if(r->exec() || r->exec()==QDialog::Accepted)
        this->show();
}

void login::on_pushButton_3_clicked()
{
    g=new get_pw;
   // connect(this,SIGNAL(send_userhead(user *)),g,SLOT(rece_userhead(user *)));
  //  emit(send_userhead(uh));

    g->show();
    this->hide();
    if(g->exec())
    {
        delete g;
        g=NULL;
        ui->username->clear();
        ui->password->clear();
        this->show();
    }

}


