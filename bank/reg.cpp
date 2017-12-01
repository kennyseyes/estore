#include "reg.h"
#include "ui_reg.h"
#include <cctype>
#include <sstream>
#include <iomanip>
#include <iostream>

reg::reg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reg)
{
    ui->setupUi(this);
    connect(ui->back,SIGNAL(clicked(bool)),this,SLOT(close()));


}

reg::~reg()
{
    delete ui;
}

void reg::on_back_clicked()
{
    accept();
}

void reg::on_submit_clicked()
{
    QString s_bank=ui->bank->currentText();
    QString s_pw=ui->pw->text();
    QString s_pw2=ui->pw2->text();
    QString s_name=ui->name->text();
    QString s_id=ui->id->text();
    QString s_ques=ui->ques->currentText();
    QString s_ans=ui->ans->text();
    QString s_phone=ui->phone->text();

    QByteArray bank1=s_bank.toUtf8();
    QByteArray pw1=s_pw.toUtf8();
    QByteArray name1=s_name.toUtf8();
    QByteArray id1=s_id.toUtf8();
    QByteArray ques1=s_ques.toUtf8();
    QByteArray ans1=s_ans.toUtf8();
    QByteArray phone1=s_phone.toUtf8();

    bool problem=0;
    int i=0;

    QSqlQuery query;
    query.exec("SELECT * FROM bank");
    //载入数据库失败
    if(!query.first())
       QMessageBox::warning(NULL, "Error", "Unable to find \"bank\"!", QMessageBox::Ok);




    //错误处理
    while(!problem)
    {
        if(s_bank.toStdString()=="请选择"){
            QMessageBox::warning(NULL, "填写错误", "请选择开户银行", QMessageBox::Ok);
            problem=1;
        }

        else if(s_pw.length()!=6 && !problem){
            QMessageBox::warning(NULL, "填写错误", "密码为6位", QMessageBox::Ok);
            problem=1;
        }

        else if(s_pw.length()==6 && !problem)
        {
            while(i<6)
            {
                if(!isdigit(s_pw.toStdString().at(i)) )
                {
                    QMessageBox::warning(NULL, "填写错误", "密码只能由数字组成", QMessageBox::Ok);
                    problem=1;
                    break;
                }
                i++;
            }
            if(s_pw.toStdString()!=s_pw2.toStdString() && !problem){
                QMessageBox::warning(NULL, "填写错误", "两次密码输入不一致", QMessageBox::Ok);
                problem=1;
            }


            else if(s_name.length()==0 && !problem)
            {
                QMessageBox::warning(NULL, "填写错误", "请输入持卡人姓名", QMessageBox::Ok);
                problem=1;
            }

            else if(s_name.length()!=0 && !problem)
            {
                for( i=0;i<s_name.length();i++)
                    if(isdigit(s_name.toStdString().at(i)) || ispunct((s_name.toStdString().at(i))))
                    {
                        QMessageBox::warning(NULL, "填写错误", "持卡人姓名中含非法字符", QMessageBox::Ok);
                        problem=1;
                        break;
                    }
                    else if(s_id.length()!=7 && !problem)
                    {
                        QMessageBox::warning(NULL, "填写错误", "身份证号为七位数字", QMessageBox::Ok);
                        problem=1;
                    }

                    else if(s_id.length()==7 && !problem)
                    {
                        for( i=0;i<s_id.length();i++)
                            if(!isdigit(s_id.toStdString().at(i)))
                            {
                                QMessageBox::warning(NULL, "填写错误", "身份证号码只能由数字组成", QMessageBox::Ok);
                                problem=1;
                                break;
                            }
                            if(s_ques.toStdString()=="请选择" && !problem)
                            {
                                QMessageBox::warning(NULL, "填写错误", "请选择密码提示问题", QMessageBox::Ok);
                                problem=1;
                            }
                            else if(s_ans.length()==0)
                            {
                                QMessageBox::warning(NULL, "填写错误", "请回答密码提示问题答案", QMessageBox::Ok);
                                problem=1;
                            }

                            else if(s_phone.length()!=11 && !problem)
                            {
                                QMessageBox::warning(NULL, "填写错误", "手机号码为11位数字", QMessageBox::Ok);
                                problem=1;
                            }

                            else if(s_id.length()==11 && !problem)
                            {
                                for( i=0;i<s_phone.length();i++)
                                    if(!isdigit(s_phone.toStdString().at(i)))
                                    {
                                        QMessageBox::warning(NULL, "填写错误", "手机号码只能由数字组成", QMessageBox::Ok);
                                        problem=1;
                                        break;
                                    }

                            }
                    }
            }
        }

        break;
    }
    if(!problem)
    {
        //注册成功，将数据写入数据库。

        query.exec("SELECT count(*) FROM bank ");
        query.next();
        int n = query.value(0).toInt();
        n+=1;
        stringstream ss;
        string num,card_no,s1;
        ss << n; ss >> num; ss.clear();
        ss << std::setw(4) << std::setfill('0') << num;
        ss >> card_no;
        QString q_card_no = QString::fromStdString(card_no);

        query.prepare("INSERT INTO bank(name, id, passwd, bank_name, question, answer, money, phone, card_no) "
                      "VALUES(?,?,?,?,?,?,?,?,?)");

        query.addBindValue(name1);
        query.addBindValue(id1);
        query.addBindValue(pw1);
        query.addBindValue(bank1);
        query.addBindValue(ques1);
        query.addBindValue(ans1);
        query.addBindValue(0.0);
        query.addBindValue(phone1);
        query.addBindValue(q_card_no);
        query.exec();



        QMessageBox megBox;
        megBox.addButton("返回主页",QMessageBox::AcceptRole);
        QString s = QString("您已成功注册，卡号为：%1").arg(QString::fromStdString(card_no));
        megBox.setText(s);
        if(megBox.exec()==QMessageBox:: AcceptRole)
            accept();
    }
}
