#include "bank.h"
#include "ui_bank.h"
#include <QListWidget>
#include <QListWidgetItem>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>

bank::bank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bank)
{
    ui->setupUi(this);
    ui->welcome->show();
    ui->depositw->hide();
    ui->withdraww->hide();
    ui->checkw->hide();
    ui->transferw->hide();
    ui->log->clear();
    connect(ui->back,SIGNAL(clicked(bool)),this,SLOT(close()));


}

bank::~bank()
{
    delete ui;
}

void bank::rece_userhead(user *uh){
    uh1=uh;
    stringstream ss; string money;
    ss << uh1->get_money();
    ss >> money;
   // qDebug() << uh1;
    ui->name->setText(QString::fromStdString(uh1->get_name()));
    ui->bank_2->setText(QString::fromStdString(uh1->get_bknm()));
    ui->money->setText(QString::fromStdString(money));
    ui->card->setText(QString::fromStdString(uh1->get_card_no()));
}

void bank::on_chg_pw_clicked()
{
    connect(this,SIGNAL(send_userhead(user *)),chg,SLOT(rece_userhead(user *)));
    emit(send_userhead(uh1));
    chg->show();
}

void bank::on_deposit_clicked()
{
    ui->depositw->show();
    ui->withdraww->hide();
    ui->transferw->hide();
    ui->checkw->hide();
    ui->welcome->hide();
    ui->log->clear();
    ui->save->clear();
}

void bank::on_withdraw_clicked()
{
    ui->depositw->hide();
    ui->withdraww->show();
    ui->transferw->hide();
    ui->checkw->hide();
    ui->welcome->hide();
    ui->log->clear();
    ui->quqian->clear();
    ui->pw->clear();
}

void bank::on_transfer_clicked()
{
    ui->transferw->show();
    ui->depositw->hide();
    ui->withdraww->hide();
    ui->checkw->hide();
    ui->welcome->hide();
    ui->log->clear();
    ui->rec_card->clear();
    ui->amount->clear();
}

void bank::on_check_record_clicked()
{
    ui->checkw->show();
    ui->transferw->hide();
    ui->depositw->hide();
    ui->withdraww->hide();
    ui->welcome->hide();
    ui->log->clear();

    QSqlQuery query;
    query.exec(QString("select * from bank where card_no=%1").arg(QString::fromStdString(uh1->get_card_no())));
    query.next();
    string s,str = query.value("log").toString().toStdString();
    stringstream ss(s);
    ss << str;
    while(getline(ss,s,' '))
    {
        qDebug() << QString(s[1]);

        if(s.at(0)=='S')//存入
            ui->log->addItem(new QListWidgetItem(QIcon(":/icon/icons/in.png"), QString::fromStdString(s)));
        else if(s.at(0)=='W')//取出
            ui->log->addItem(new QListWidgetItem(QIcon(":/icon/icons/out.png"), QString::fromStdString(s)));
        else if(s.at(0)=='R')//收到他人转账
            ui->log->addItem(new QListWidgetItem(QIcon(":/icon/icons/get.png"), QString::fromStdString(s)));
        else   //转账
            ui->log->addItem(new QListWidgetItem(QIcon(":/icon/icons/trans.png"), QString::fromStdString(s)));
    }



}

void bank::on_back_clicked()
{
    delete uh1;
    uh1=NULL;
    accept();
}

void bank::on_ok_clicked()//取钱
{
    string money_out = ui->quqian->text().toStdString();
    string pw=ui->pw->text().toStdString();

    float f_money_out;
    stringstream ss;
    ss << money_out; ss >> f_money_out;
    float money = uh1->get_money();

    if(money<f_money_out)
    {
        QMessageBox::warning(NULL,"wrong","余额不足",QMessageBox::Ok);
        ui->withdraww->hide();
        ui->welcome->show();
    }

    else if(pw!=uh1->get_pw())
    {
        QMessageBox::warning(NULL,"wrong","密码错误",QMessageBox::Ok);
        ui->pw->clear();
    }

    else
    {
        uh1->set_money(money-f_money_out);
        QSqlQuery query;
        query.exec(QString("select * from bank where id=%1").arg(QString::fromStdString(uh1->get_id())));
        if(query.next())
        {
            query.exec(QString("UPDATE bank SET money=%1 WHERE card_no=%2").arg(uh1->get_money()).
                       arg(QString::fromStdString(uh1->get_card_no())));

            //写入日志--------------------------
            string s_log=uh1->get_log();
            string update=s_log+"WITHDRAW:取出"+money_out+"元 ";
            uh1->set_log(update);
            query.exec(QString("UPDATE bank SET log='%1' WHERE card_no='%2'").arg(QString::fromStdString(update)).arg(QString::fromStdString(uh1->get_card_no())));

            //--------------------------------
            QString s = QString("取出了%1元，余额：%2元").arg(f_money_out).arg(uh1->get_money());
            QMessageBox::about(NULL,"result",s);

            string m;
            ss.clear(); ss << uh1->get_money(); ss >> m;
            ui->money->setText(QString::fromStdString(m));
            ui->withdraww->hide();
            ui->pw->clear();
            ui->quqian->clear();
            ui->welcome->show();
        }
    }
}

void bank::on_back_2_clicked()
{
    ui->withdraww->hide();
    ui->welcome->show();
}

void bank::on_back_3_clicked()
{
    ui->transferw->hide();
    ui->welcome->show();
}

void bank::on_ok_2_clicked()//转账
{
    string cd = ui->rec_card->text().toStdString();
    string mny_trans = ui->amount->text().toStdString();
    stringstream ss;
    float f_mny_trans;
    ss << mny_trans; ss >> f_mny_trans;
    if(f_mny_trans>uh1->get_money())
    {
        QMessageBox::warning(NULL,"穷","余额不足",QMessageBox::Ok);
    }
    else
    {
        QSqlQuery query;
        query.exec(QString("select * from bank where card_no=%1").arg(ui->rec_card->text()));
        if(!query.next())
        {
            QMessageBox::warning(NULL,"error","找不到该卡号，请确认卡号无误",QMessageBox::Ok);
        }
        else
        {
            if(ui->amount->text()==NULL)
                QMessageBox::warning(NULL,"wrong","请输入转账金额",QMessageBox::Ok);
            else
            {
                QString s=QString("请确认您的转账对象：\n姓名：%1\n卡号：%2").arg(query.value("name").toString()).arg(query.value("card_no").toString());
                QMessageBox msg;
                msg.addButton("核实无误，确认",QMessageBox::AcceptRole);
                msg.addButton("有错再去改一下",QMessageBox::RejectRole);
                msg.setText(s);
                if(msg.exec()==QMessageBox::AcceptRole)
                {
                    //增加转账对象钱数
                    float m2 = query.value("money").toFloat();
                    query.exec(QString("UPDATE bank SET money='%1' WHERE card_no='%2'").arg(m2+f_mny_trans).arg(query.value("card_no").toString()));

                    //写入日志--------------------------
                    query.exec(QString("select * from bank where card_no=%1").arg(ui->rec_card->text()));
                    query.next();
                    string s_log=query.value("log").toString().toStdString();
                    string update=s_log+"RECEIVE:收到转账"+mny_trans+"元从"+uh1->get_card_no()+" ";
                    query.exec(QString("update bank set log='%1' where card_no='%2'").arg(QString::fromStdString(update)).arg(query.value("card_no").toString()));

                    //--------------------------------

                    //减少当前用户钱数
                    query.exec(QString("select * from bank where card_no=%1").arg(QString::fromStdString(uh1->get_card_no())));
                    query.next();
                    float mon =query.value("money").toFloat();
                    float c_mny = mon - f_mny_trans;
                    query.exec(QString("UPDATE bank SET money=%1 WHERE card_no=%2").arg(c_mny).arg(QString::fromStdString(uh1->get_card_no())));
                    uh1->set_money(c_mny);

                    //log-----------------------------
                    s_log=uh1->get_log();
                    update=s_log+"TRANSFER:转账"+mny_trans+"元给"+cd+" ";
                    uh1->set_log(update);
                    query.exec(QString("update bank set log='%1' where card_no='%2'").arg(QString::fromStdString(update)).arg(QString::fromStdString(uh1->get_card_no())));

                    //--------------------------------

                    QMessageBox::about(NULL,"成功","转账成功");
                    string m;
                    ss.clear(); ss << uh1->get_money(); ss >> m;
                    ui->money->setText(QString::fromStdString(m));
                    ui->transferw->hide();
                    ui->welcome->show();

                    ui->amount->clear();
                    ui->rec_card->clear();
                 }
            }
        }
    }
}

void bank::on_ok_save_clicked()
{
    if(ui->save->text()=="")
        QMessageBox::warning(NULL,"wrong","请输入存款金额",QMessageBox::Ok);
    else
    {
        string s_money = ui->save->text().toStdString();
        stringstream ss;
        float money_f;
        ss << s_money; ss >> money_f;
        uh1->set_money(money_f+uh1->get_money());

        QSqlQuery query;
        query.exec(QString("select * from bank where card_no=%1").arg(QString::fromStdString(uh1->get_card_no())));
        query.next();
        query.exec(QString("UPDATE bank SET money='%1' WHERE card_no='%2'").arg(uh1->get_money()).arg(QString::fromStdString(uh1->get_card_no())));

        //log-------------------
        string s_log=uh1->get_log();
        string update=s_log+"SAVE:存入"+s_money+"元 ";
        uh1->set_log(update);
        query.exec(QString("UPDATE bank SET log='%1' WHERE card_no='%2'").arg(QString::fromStdString(update)).arg(QString::fromStdString(uh1->get_card_no())));
        //-----------------------

        QString s=QString("成功存款%1元").arg(ui->save->text());
        QMessageBox::about(NULL,"成功",s);

        ui->save->clear();
        ui->depositw->hide();
        string m;
        ss.clear(); ss << uh1->get_money(); ss >> m;
        ui->money->setText(QString::fromStdString(m));
        ui->welcome->show();
    }
}

void bank::on_back_save_clicked()
{
    ui->depositw->hide();
    ui->save->clear();
    ui->welcome->show();
}
