#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    connect(ui->return_2,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->ok,SIGNAL(clicked(bool)),this,SLOT(close()));
}

login::~login()
{
    delete ui;
}

void login::on_return_2_clicked()
{
    accept();
}

void login::on_ok_clicked()
{
    this->hide();
    u->show();
    if(u->exec())
        accept();
}
