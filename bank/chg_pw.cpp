#include "chg_pw.h"
#include "ui_chg_pw.h"
#include "user.h"

user *uh2=NULL;

chg_pw::chg_pw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chg_pw)
{
    ui->setupUi(this);
}

chg_pw::~chg_pw()
{
    delete ui;
}

void chg_pw::rece_userhead(user *uh){
    uh2=uh;
}

void chg_pw::on_quit_clicked()
{
    this->close();
}

void chg_pw::on_confirm_clicked()
{
    QString _id=ui->id->text();
    QString _pw=ui->pw_before->text();
    QString _pw_new=ui->pw_new->text();
    QString _pw_new2=ui->pw_new2->text();

    bool problem = 0;
    while(!problem)
    {
        if(_id.toStdString()!=uh2->get_id())
        {
            QMessageBox::warning(NULL,"错误","身份证号不符",QMessageBox::Ok);
            problem = 1;
        }
        else
        {
            if(_pw.toStdString()!=uh2->get_pw())
            {
                QMessageBox::warning(NULL,"错误","原密码输入错误",QMessageBox::Ok);
                problem = 1;
            }
            else
            {
                if(_pw_new.length()!=6)
                {
                    QMessageBox::warning(NULL,"错误","密码为六位数字",QMessageBox::Ok);
                    problem = 1;
                }
                else
                {
                    for(int i=0;i<6;i++)
                    {
                        if(!isdigit(_pw_new.toStdString().at(i)))
                        {
                            QMessageBox::warning(NULL,"错误","密码中包含非数字字符",QMessageBox::Ok);
                            problem = 1;
                            break;
                        }
                        else if(_pw_new!=_pw_new2)
                        {
                            QMessageBox::warning(NULL,"错误","新密码输入不同",QMessageBox::Ok);
                            problem = 1;
                            break;
                        }
                     }
                        if(!problem)
                        {
                            QSqlQuery query;
                            QString card = QString::fromStdString(uh2->get_card_no());
                            query.exec(QString("SELECT * FROM bank WHERE id=%1").arg(_id));

                            if(query.first())
                                query.exec(QString("UPDATE bank SET passwd=%1 WHERE card_no=%2").arg(_pw_new).arg(card));
                            QMessageBox::warning(NULL,"成功","修改密码成功",QMessageBox::Ok);
                            problem = 1;
                            this->close();
                            break;
                        }
                }
            }
        }
    }

}
