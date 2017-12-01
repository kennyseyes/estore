#include "forgetpassword.h"
#include "ui_forgetpassword.h"

ForgetPassword::ForgetPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ForgetPassword)
{
    ui->setupUi(this);
    connect(ui->back,SIGNAL(clicked(bool)),this,SLOT(close()));
}

ForgetPassword::~ForgetPassword()
{
    delete ui;
}

void ForgetPassword::on_back_clicked()
{
    accept();
}
