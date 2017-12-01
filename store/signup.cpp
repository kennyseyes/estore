#include "signup.h"
#include "ui_signup.h"

signup::signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);

//    QImage *img =new QImage();
//    img->load("./img/books/edu/edu_0001.jpg");
//    ui->label->setPixmap(QPixmap::fromImage(*img));
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(close()));
}

signup::~signup()
{
    delete ui;
}

void signup::on_pushButton_2_clicked()
{
    accept();
}
